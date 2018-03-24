/*************************************************************************
> File Name: test.cpp
> Author: Akira 
> Mail: qaq.febr2.qaq@gmail.com 
************************************************************************/

//#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
#include <climits>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define pb emplace_back
using namespace std;                                                                                              

#define MaxN 105
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}

int N,A[MaxN];
bool mark[MaxN][MaxN];
int weight[MaxN][MaxN];

struct Edge  
{  
    int cost, cap, v;  
    int next, re;  
}edge[500050];  
int head[50005], cont;  
int vis[50005], d[50005];  
int ans, cost, sum,src, des, n;  

inline void add(int u, int v, int cap, int cost)  
{  
    edge[cont].v = v;  
    edge[cont].cap = cap;  
    edge[cont].cost = cost;  
    edge[cont].re = cont + 1;  
    edge[cont].next = head[u];  
    head[u] = cont++;  
    edge[cont].v = u;  
    edge[cont].cap = 0;  
    edge[cont].cost = -cost;  
    edge[cont].re = cont - 1;  
    edge[cont].next = head[v];  
    head[v] = cont++;  
}  

int aug(int u, int f)  
{  
    if(u == des)  
    {  
        ans += cost * f;  
        return f;  
    }  
    vis[u] = 1;  
    int tmp = f;  
    for(int i = head[u]; i != -1; i = edge[i].next)  
        if(edge[i].cap && !edge[i].cost && !vis[edge[i].v])  
        {  
            int delta = aug(edge[i].v, tmp < edge[i].cap ? tmp : edge[i].cap);  
            edge[i].cap -= delta;  
            edge[edge[i].re].cap += delta;  
            tmp -= delta;  
            if(!tmp) return f;  
        }  
    return f - tmp;  
}  
bool modlabel()  
{  
    for(int i = 0; i <= n; i++) d[i] = INF;  
    d[des] = 0;  
    deque<int>Q;  
    Q.push_back(des);  
    while(!Q.empty())  
    {  
        int u = Q.front(), tmp;  
        Q.pop_front();  
        for(int i = head[u]; i != -1; i = edge[i].next)  
            if(edge[edge[i].re].cap && (tmp = d[u] - edge[i].cost) < d[edge[i].v])  
                (d[edge[i].v] = tmp) <= d[Q.empty() ? src : Q.front()] ? Q.push_front(edge[i].v) : Q.push_back(edge[i].v);  
    }  
    for(int u = 0; u <= n; u++)  
        for(int i = head[u]; i != -1; i = edge[i].next)  
            edge[i].cost += d[edge[i].v] - d[u];  
    cost += d[src];  
    return d[src] < INF;  
}  
void costflow()  
{  
    while(modlabel())  
    {  
        do  {  CLR(vis);  }while(aug(src, INF));  
    }  
}  

void solve()
{
    src = 0, des = 2*N+1;
    for(int i=1;i<=N;i++){
        add(src,i,INF,0); add(i,i+N,A[i],0);
    }
    int id = des;    
    for(int i=1;i<=N;i++) 
    for(int j=i+1;j<=N;j++)
    {
        if(i==j ||weight[i][j]==-1) continue;
        ++id;
        add(i+N, id, 1, -weight[i][j]);
        add(j+N, id, 1, -weight[j][i]);
        ++id;
        add(id-1, id, 1, 0);
        add(id, des, INF, 0);
    }
    n = id+1;
    costflow();
    // cout << sum << " - " <<ans << endl;
    cout << sum-ans << endl;
}

void init()
{
    CLR(mark);
    MST(head, -1); cont = 0;  
    ans = cost = sum = 0;
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin >> N)
    {
        init();
        for(int i=1;i<=N;i++) cin >> A[i];
        int k,a,b;
        cin >> k;
        while(k--){
            cin >> a >> b;
            mark[a][b] = true;
            A[a]--;
        }
        for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++){
            cin >> weight[i][j];
            if(mark[i][j]) {
                sum+=weight[i][j];
                weight[i][j] = weight[j][i] = -1;
            }
            if(mark[j][i]){
                weight[i][j] = weight[j][i] = -1;
            }
        }
        solve();
    }

}

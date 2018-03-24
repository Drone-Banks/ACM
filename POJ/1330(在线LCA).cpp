/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

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
using namespace std;

#define MaxN 10001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
#define mmin(seq, a, b)  ((seq[a] < seq[b]) ? (a) : (b))
struct Edge  
{  
    int to,next;  
}edge[MaxN*2];  
int head[MaxN],tot;  
void addedge(int u,int v)//邻接表头插法加边  
{  
    edge[tot].to=v;  
    edge[tot].next=head[u];  
    head[u]=tot++;  
}  

int fij[100000][100];
template <typename T>
void st(T seq[], int n)//预处理
{ 
    memset(fij, 0, 100 * MaxN * sizeof(int));
    int k = (int)(log((double)n) / log(2.0)); 
    /**/////初始状态
    for(int i = 0; i < n; i++)
        fij[i][0] = i; 
    /**/////递推计算状态
    for(int j = 1; j <= k; j++)
    {
        for(int i = 0; i + (1 << j) - 1 < n; i++)
        {
            //
            int m = i + (1 << (j - 1)); 
            //fij[i][j] = seq[fij[i][j - 1]] < seq[fij[m][j - 1]] ? fij[i][j - 1] : fij[m][j - 1];
            fij[i][j] = mmin(seq, fij[i][j - 1], fij[m][j - 1]);
        }
    }
}
template <typename T>
int RMQ(T seq[], int i, int j)//求解RMQ
{
    /**///// 用对2去对数的方法求出k
    int k = (int)(log(double(j - i + 1)) / log(2.0)); 
    /**/////
    //int t = seq[fij[i][k]] < seq[fij[j - (1 << k) + 1][k]] ? fij[i][k] : fij[j - (1 << k) + 1][k];
    int t = mmin(seq, fij[i][k], fij[j - (1 << k) + 1][k]);
    return t;
}
int E[MaxN*2+1],R[MaxN*2+1],D[MaxN*2+1],vis[MaxN];
int cnt;
void LCA(int u,int dep)
{
    vis[u] = true;
    cnt++;
    E[cnt] = u;
    D[cnt] = dep;
    R[u] = cnt;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if( !vis[v] )
        {
            LCA(v, dep+1);
            cnt++;
            E[cnt] = u;
            D[cnt] = dep;
        }
    }
}   
int t;  
int n,u,v;  
bool flag[MaxN];//用来确定根节点的  
void init()
{
    CLR(flag);
    MST(head,-1);
    tot = 0;
    cnt = 0;
    CLR(vis);
}
int main()  
{  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d",&n);  
        init();  
        for(int i=1;i<n;i++)  
        {  
            scanf("%d%d",&u,&v);  
            flag[v]=true;//有入度  
            addedge(u,v);  
            addedge(v,u);  
        } 
        int root;  
        for(int i=1;i<=n;i++)  
        {  
            if(!flag[i])  
            {  
                root=i;  
                break;  
            }  
        }  
        LCA(root,0);  
        st(D,2*n+2);
        int l,r;
        Q = 1;
        while(Q--)
        {
            scanf("%d%d", &l, &r);
            l=R[l], r = R[r];
            int s = min(l,r), t = max(l,r);
            int tt = RMQ(D,s,t);
            printf("%d\n",E[tt] );
        }
    }  
    return 0;  
} 


/*
4231
5
1 2
1 3
3 4
3 5
*/
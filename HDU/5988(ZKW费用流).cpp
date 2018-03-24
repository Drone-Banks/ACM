/*************************************************************************
> File Name: test.cpp
> Author: Akira 
> Mail: qaq.febr2.qaq@gmail.com 
************************************************************************/

//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
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

#define MaxN 202
#define MaxM 10005
#define INF 1000000000
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-8;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}

bool dayu(double a, double b)
{
    if( a-b>eps) return true;
    else return false;
}

int N,M;
double dis[105][105];
int s[105],b[105];

struct Edge  
{  
    double cost; 
    int cap, v;  
    int next, re;  
}edge[500050];  
int head[50005], cont;  
int vis[50005];
double d[50005];  

double ans, cost;
int src, des, n;  

inline void add(int u, int v, int cap, double cost)  
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
        int u = Q.front();
        double tmp;  
        Q.pop_front();  
        for(int i = head[u]; i != -1; i = edge[i].next)  
            if(edge[edge[i].re].cap && dayu(d[edge[i].v], (tmp=d[u] - edge[i].cost) ) )  
            {
                d[edge[i].v] = tmp;
                if( dayu((d[edge[i].v] = tmp), d[Q.empty() ? src : Q.front()] )) Q.push_back(edge[i].v);
                else Q.push_front(edge[i].v);  
            }
    }  
    for(int u = 0; u <= n; u++)  
        for(int i = head[u]; i != -1; i = edge[i].next)  
            edge[i].cost += d[edge[i].v] - d[u];  
    cost += d[src];  
    return dayu(INF, d[src]);  
}  
void costflow()  
{  
    while(modlabel())  
    {  
        do  {  CLR(vis);  }while(aug(src, INF));  
    }  
}  

void init()
{
    MST(head, -1); cont = 0;  
    ans = cost = 0;
}

int main()
{
    int Case;
    scanf("%d", &Case);
    while(Case--)
    {
        init();
        scanf("%d%d", &N, &M);
        int u,v,x;
        double y;
        src = 0, des = N+1;
        for(int i=1;i<=N;i++)
        {
            scanf("%d%d", &s[i], &b[i]);
            if(s[i]>b[i]) add(src,i,s[i]-b[i],0);
            if(b[i]>s[i]) add(i,des,b[i]-s[i],0);
        }
        while(M--){
           scanf("%d%d%d%lf", &u, &v, &x, &y);
            y = -log((double)(1.0-y));
            if(x>1){
                add(u,v,x-1,y);
                add(u,v,1,0);
            }
            else if(x==1) 
                add(u,v,1,0);
        }
        n = N+2;
        costflow();  
        ans = 1.0 - exp(-ans);  
        printf("%.2f\n", ans);
    }
}
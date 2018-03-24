/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 100001
#define MaxM MaxN*4
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
int N,M,Q;
int V[MaxN], D[MaxN], C[MaxN];
struct Edge
{
    int u,v,next;
}edge[MaxM];
int cont,head[MaxN];
void add(int u, int v)
{
    edge[cont].u = u, edge[cont].v = v, edge[cont].next = head[u], head[u] = cont++;
}
int num = 0;
int color[MaxN];
int MAX[MaxN];
void Paint(int pre,int u, int d, int c)
{
    if(d && MAX[u]>=d) return ;
    MAX[u] = max(MAX[u],d);
    if(!color[u]) 
    {
        color[u] = c;
        num++;
    }
    if(d==0) return;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(v == pre) continue;
        Paint(u, v, d-1, c);
    }
}
void solve()
{
    for(int i=Q-1;i>=0;i--)
    {
        if(D[i] && D[i]<=MAX[V[i]]) continue;
        Paint(0, V[i], D[i], C[i]);
        if(num>=N) break;
    }
    for(int i=1;i<=N;i++) printf("%d\n", color[i]);
}
void init()
{
    cont = 0;
    MST(head,-1);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    init();
    scanf("%d%d", &N, &M);
    int a,b;
    while(M--)
    {
        scanf("%d%d", &a, &b);
        add(a,b),add(b,a);
    }
    scanf("%d", &Q);
    for(int i=0;i<Q;i++) scanf("%d%d%d", &V[i], &D[i], &C[i]);
    solve();
    system("pause");
}

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

#define MaxN 1000001
#define MaxM MaxN*2
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
int N;
struct Edge
{
    int u,v,w,next;
}edge[MaxM];
int cont,head[MaxN];
void add(int u, int v,int w)
{
    edge[cont].u = u, edge[cont].v = v, edge[cont].w = w, edge[cont].next = head[u], head[u] = cont++;
}
int dsize[MaxN];
LL ans;

void DFS(int u, int pre)
{
    dsize[u] = 1;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(v==pre) continue;
        DFS(v,u);
        dsize[u]+=dsize[v];
        ans += abs(N-2*dsize[v])*(LL)edge[i].w;
    }
}

void solve()
{
    DFS(1,0);
    printf("%lld\n", ans);
}
void init()
{
    CLR(dsize);
    ans = 0;
    cont = 0;
    MST(head,-1);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &N))
    {
        init();
        int a,b,c;
        for(int i=1;i<N;i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            add(a,b,c);add(b,a,c);
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

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
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define ps push_back
using namespace std;

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
inline int max2(int a, int b) {return ((a > b)? a : b);}
inline int min2(int a, int b) {return ((a < b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}
inline int min3(int a, int b, int c) {return min2(a, min2(b, c));}
const int log2n = 20;
int n,q;
struct Edge
{
    int u,v,next;
}edge[MaxM];
int cont, head[MaxN];
void add(int u, int v)
{
    edge[cont].u = u, edge[cont].v = v, edge[cont].next = head[u], head[u] = cont++;
}

int dep[MaxN], pre[MaxN][log2n], fa[MaxN], dfn[MaxN], low[MaxN], clo;
void dfs(int u)
{
	pre[u][0] = fa[u], dfn[u] = low[u] = ++clo;
	for (int i=head[u]; i!=-1; i=edge[i].next)
	{
        int v = edge[i].v;
        dep[v] = dep[u]+1;
        dfs(v);
        low[u] = max(low[u], low[v]);
    }
    //debug(dep[u])
}

void lcabinarylifting(int n)
{
	for(int j=1;(1<<j)<=n;++j)
		for(int i=1;i<=n;++i)
			if(pre[i][j-1]!=-1) pre[i][j]=pre[pre[i][j-1]][j-1];   ///2^j=2^(j-1)+2^(j-1)

}

inline int lca(int x,int y)
{
    int D = 0;
    if(dep[x]<dep[y])swap(x,y);
    while( (1<<D) <= dep[x])D++;
    D--;
    for(int i =D;i>=0;i--) if(dep[x]-(1<<i)>=dep[y]) x=pre[x][i];
    if(x==y) return x;
    for(int i=D;i>=0;--i)
        if(pre[x][i]!=-1 && pre[x][i]!=pre[y][i])
        {
            x=pre[x][i];y=pre[y][i];
        }
    return pre[x][0];
}
int ans;
void cal(int a,int b,int c)
{
	int x=lca(b,c);
	int sum=0;
	if(dfn[a]>=dfn[x] && dfn[a]<=low[x])
	{
		int y=lca(a,b),z=lca(a,c); 
		if(y==x) sum=dep[a]-dep[z]+1;
		else sum=dep[a]-dep[y]+1;
	}
	else
	{
		int y=lca(x,a);
		sum=dep[x]+dep[a]-2*dep[y]+1;
	}
	ans=max(ans,sum);
}

void solve()
{
    clo = 0;
    dfs(1);
    lcabinarylifting(n);
}
void init()
{
    cont = 0, MST(head,-1);
    fa[1] = -1, dep[1] = 0;
    MST(pre,-1);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &q))
    {
        init();
        for(int u=2;u<=n;u++)
        {
            scanf("%d", &fa[u]);
            add(fa[u],u);
        }
        solve();
        int a, b, c;
        while(q--)  
        {
            scanf("%d%d%d", &a, &b, &c);
            ans = 0;
            cal(a,b,c);
            cal(b,a,c);
            cal(c,a,b);
            printf("%d\n", ans);
        }
    }
    //system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

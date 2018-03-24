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
#define pb push_back
using namespace std;

#define MaxN 300005
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

int n,k,p[MaxN];
struct Edge
{
    int u,v,next;
}edge[MaxM];
int cont, head[MaxN];
void add(int u, int v)
{
    edge[cont].u=u, edge[cont].v=v, edge[cont].next = head[u];
    head[u] = cont++;
}
const int log2N = 25;
int dep[MaxN], fa[MaxN][30];
bool vis[MaxN];
void dfs(const int &u, const int &d) {
    vis[u]=1; dep[u]=d;
    for(int i=head[u]; i!=-1; i=edge[i].next)
        if(!vis[edge[i].v]) { dfs(edge[i].v, d+1); fa[edge[i].v][0]=u; }
}
inline void bz() { 
for(int j=1; j<log2N; ++j) 
    for(int i=1; i<=n; ++i) 
        fa[i][j]=fa[fa[i][j-1]][j-1]; 
}

inline int lca(int u, int v) {
    if(dep[u]<dep[v]) swap(u, v);
    int d=dep[u]-dep[v];
    for(int i=log2N-1; i>=0; --i) if((1<<i)&d) u=fa[u][i];
    if(u==v) return u;
    for(int i=log2N-1; i>=0; --i) if(fa[u][i]!=fa[v][i]) u=fa[u][i], v=fa[v][i];
    return fa[u][0];
}
vector<vector<int> >dp;
int LCA[MaxN];
void solve()
{
    CLR(vis);
    dfs(1, 1);
    bz();
    for(int i=2;i<=n;i++)
    {
        int baba = lca(p[i-1], p[i]);
        LCA[i] = dep[baba];
    }
    dp.assign(n+1,vector<int>(k+1,0));
    for(int i=1;i<=n;i++)
    {
        int limit = min(i,k);   
        for(int j=0;j<=limit;j++)
        {
            int tmp = INF;
            if(j<=i-1) tmp = min(dp[i-1][j], tmp);
            if(j>0&&i>0) tmp = min(tmp, dp[i-1][j-1]+dep[p[i]]);
            if(i-2>=0&&j-1>=0&&j-1<=i-2) tmp = min(tmp, dp[i-2][j-1]+LCA[i]);
            dp[i][j] = tmp;
        }
    }
    printf("%d\n", dp[n][k]);
}

void init()
{
    cont = 0, MST(head, -1);
}

int main()
{
    // freopen("1010.in","r",stdin);
	// freopen("wo.out","w",stdout);
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &k))
    {
        init();
        for(int i=1;i<=n;i++) scanf("%d", p+i);
        int a, b;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d", &a, &b);
            add(a,b),add(b,a);
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

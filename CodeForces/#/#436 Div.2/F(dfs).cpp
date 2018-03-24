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

#define MaxN 3005
#define MaxM 400004
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}

int n,m,q;
vector<int> G[MaxN],IG[MaxN];
vector< pair<int,int> > qs[MaxN][MaxN];
vector<int> Path, Fa[MaxN];
int ans[MaxM];
bool vis[MaxN];
void dfs(int u)
{
    if(vis[u]) return;
    vis[u] = 1;
    for(auto v : IG[u])
        dfs(v);
}

void cal(int t, int u)
{
    Path.pb(u);
    for(auto it : qs[t][u])
        if( it.first < Path.size() ) 
            ans[it.second] = Path[Path.size()-1 - it.first] + 1;
    for( auto fa : Fa[u])
    {
        cal(t, fa);
    }
    Path.pop_back();
}

void solve()
{
    MST(ans,-1);
    for(int i=0;i<n;i++)
    {
        CLR(vis);
        dfs(i);
        for(int j=0;j<n;j++) Fa[j].clear();
        for(int j=0;j<n;j++)
        {
            if(j==i) continue;
            int first_node = j;
            for(auto v : G[j])
            {
                if(vis[v]){
                    first_node = v;
                    break; 
                }
            }
            if(first_node != j) Fa[first_node].pb(j);
        }
     }
    for(int i=1;i<=q;i++) printf("%d\n", ans[i]);
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    {
        int a,b,k;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d", &a, &b);
            a--,b--;
            G[a].pb(b);
            IG[b].pb(a);
        }
        for(int i=0;i<n;i++) sort(G[i].begin(), G[i].end());
        for(int i=1;i<=q;i++)
        {
            scanf("%d%d%d", &a, &b, &k);
            a--,b--;
            qs[b][a].pb( k-1,i );
        }
        solve();
    }
}

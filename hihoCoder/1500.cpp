#include <bits/stdc++.h>

#define MaxN 2005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f

using namespace std;

int N,fa[MaxN],need[MaxN],give[MaxN],cost[MaxN];

struct Edge 
{
    int u,v,next;
}edge[MaxM];
int cont, head[MaxN];

inline void add(int u, int v){
    edge[cont].u = u, edge[cont].v = v, edge[cont].next = head[u], head[u] = cont++;
}

int DP[40005];
int dfs(int u)
{
    if( need[u]==0 ) return cost[u]; 
    vector<int> C,W;
    int mx = 0;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].v;
        if( v==fa[u] ) continue;
        int c = dfs(v), w = give[v];   
        C.push_back(c), W.push_back(w);
        mx = max(mx, w);
    }
    int n = C.size(), V = need[u]+mx;
    for(int i=1;i<=V;i++) DP[i] = INF;
    DP[0] = 0;
    for(int i=0; i<n; i++)
    {
        for(int v=V;v>=W[i];v--)
        {
            DP[v] = min(DP[v], DP[v-W[i]]+C[i]);
        }
    }
    int ans = INF;
    for(int v=need[u];v<=V;v++) ans = min(ans, DP[v]);
    return ans+cost[u]; 
} 

int root;
void solve()
{
    int ans = dfs(root);
    if(ans>=INF) ans = -1;
    printf("%d\n", ans);
}


void init()
{
    cont = 0;
    memset(head,-1,sizeof(head));
}

int main()
{
    while(~scanf("%d", &N))
    {
        init();
        for(int i=1;i<=N;i++)
        {
            scanf("%d%d%d%d", &fa[i], &need[i], &give[i], &cost[i]);
            if(fa[i]==0) {
                root = i;
                continue;
            }
            add(i, fa[i]); add(fa[i], i);
        }
        solve();
    }
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdalign>
#define MAXN 100005
#define MAXM 1200005
#define INF 2100000000
using namespace std;

int e, n, m;
int head[MAXN], val[MAXN];
int dp[MAXN], q[MAXN];
int ind[MAXN], outd[MAXN];
struct Edge
{
    int v, next;
}edge[MAXM];
void insert(int x, int y)
{
    edge[e].v = y;
    edge[e].next = head[x];
    head[x] = e++;
}
void init()
{
    e = 0;
    memset(head, -1, sizeof(head));
    memset(ind, 0, sizeof(ind));
    memset(outd, 0, sizeof(outd));
}
void topsort()
{
    int h = 0, t = 0;
    for(int i = 1; i <= n; i++)
        if(ind[i] == 0) q[t++] = i;
    while(h < t)
    {
        int u = q[h++];
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            dp[v] = max(dp[v], dp[u] + val[v]);
            ind[v]--;
            if(ind[v] == 0) q[t++] = v;
        }
    }
}

int main()
{
    int x, y;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        init();
        for(int i = 1; i <= n; i++) scanf("%d", &val[i]);
        while(m--)
        {
            scanf("%d%d", &x, &y);
            insert(x, y);
            ind[y]++;
            outd[x]++;
        }
        for(int i = 1; i <= n; i++) dp[i] = -INF;
        for(int i = 1; i <= n; i++)
            if(ind[i] == 0) dp[i] = val[i];
        topsort();
        int ans = -INF;
        for(int i = 1; i <= n; i++)
            if(outd[i] == 0) ans = max(ans, dp[i]);
        printf("%d\n", ans);
    }
    return 0;
}

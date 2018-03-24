/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 101
#define MaxM 3001*2
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)
int n,m;
typedef pair<int,int> pii;
struct cmp
{
    bool operator()(pii a, pii b)
    {
        return a.first > b.first;
    }
};

int Map[MaxN][MaxN];
int flag[MaxN][MaxN][MaxN];

struct Edge
{
    int u,v,w;
    int next;
    
}edge[MaxM];

int cont;
int head[MaxN];

inline void add(int u, int v)
{
    edge[cont].u = u;
    edge[cont].v = v;
    edge[cont].w = 1;
    edge[cont].next = head[u];
    head[u] = cont++;
}

int dis[MaxN];
int vis[MaxN];

int Dijkstra(int s,int tip)
{
    for(int i=0;i<=n;i++) dis[i] = INF;
    dis[s] = 0;
    CLR(vis);
    
    priority_queue<pii, vector<pii>, cmp> Q;
    Q.push(make_pair(0,s));

    while(!Q.empty())
    {
        pii tmp = Q.top();
        Q.pop();
        int u = tmp.second;
        vis[u] = 1;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            if(vis[v]) continue;
            if(dis[v] > dis[u]+ edge[i].w )
            {
                dis[v] = dis[u] + edge[i].w;
                Q.push(make_pair(dis[v],v));
                if(tip) flag[s][u][v] = flag[s][v][u] = 1;
            }
        }
    }

    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        if(dis[i]==INF)
        {
            ans = INF;
            break;
        }
        ans += dis[i];
    }
    return ans;
}

int sum[MaxN];

inline void init()
{
    cont = 0;
    MST(head,-1);
    MST(Map,0);
    CLR(flag);
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        init();
        for(int i=1;i<=m;i++)
        {
            int a,b;
            scanf("%d%d", &a, &b);
            add(a, b);
            add(b, a);
            Map[a][b]++;
            Map[b][a]++;
        }
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            sum[i] = Dijkstra(i,1);
            if(sum[i] == INF) 
            {
                ans = INF;
                break;
            }
            ans += sum[i];
        }
        for(int i=1;i<=m;i++)
        {
            if(ans == INF) 
            {
                printf("INF\n");
                continue;
            }
            int u = edge[2*i-1].u;
            int v = edge[2*i-1].v;
            if(Map[u][v] > 1) 
            {
                printf("%d\n", ans);
                continue;
            }
            int cnt = ans;
            for(int j=1;j<=n;j++)
            {
                if(flag[j][u][v])
                {
                    edge[2*i-1].w = edge[2*i-2].w = INF;
                    int tmp = Dijkstra(j,0);
                    if(tmp==INF)
                    {
                        cnt = INF;
                        break;
                    }
                    cnt = cnt + tmp - sum[j];
                }
            }
            if(cnt!=INF) printf("%d\n", cnt);
            else printf("INF\n");
            edge[2*i-1].w = edge[2*i-2].w = 1;
        }
    }
}
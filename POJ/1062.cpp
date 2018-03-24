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

#define MaxN 100000
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

typedef pair<int,int> pii;

struct cmp
{
    bool operator()(pii a, pii b)
    {
        return a.first > b.first;
    }
};

struct Edge
{
    int u,v,w;
    int next;
}edge[MaxM];

int cont;
int head[MaxN];

void add(int u, int v, int w)
{
    edge[cont].u = u;
    edge[cont].v = v;
    edge[cont].w = w;
    edge[cont].next = head[u];
    head[u] = cont++;
}

int n;
int dis[MaxN];
int level[MaxN];
int vis[MaxN];
int limit,M;
int Dijkstra(int s, int t)
{
    CLR(vis);
    for(int i=0;i<=n;i++) dis[i] = INF;
    dis[s] = 0;
    priority_queue<pii,vector<pii>,cmp> q;
    q.push(make_pair(0,s));
    while(!q.empty())
    {
        pii u = q.top();
        q.pop();
        if(vis[u.second]) continue;
        vis[u.second] = 1;
        for(int i=head[u.second];i!=-1;i=edge[i].next)
        {
            int to = edge[i].v;
            if( level[to] < limit || level[to] > limit+M ) continue;
            if(dis[to] > u.first + edge[i].w)
            {
                dis[to] = u.first + edge[i].w;
                q.push(make_pair(dis[to], to));
            }
        }
    }
    return dis[t];
}

void init()
{
    MST(head, -1);
    cont = 0;
}

int main()
{
    int P,L,X;
    while(~scanf("%d%d", &M, &n))
    {
        init();
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d", &P, &L, &X);
            level[i] = L;
            add(0,i,P);
            while(X--)
            {
                int T,V;
                scanf("%d%d", &T, &V);
                add(T,i,V);
            }
        }
        int ans = INF;
        for(int i=1;i<=n;i++)
        {
            limit = level[i];
            ans = MIN(ans, Dijkstra(0,1));
        }
        printf("%d\n", ans);
    }
    system("pause");
}
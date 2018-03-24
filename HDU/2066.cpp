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

#define MaxN 1001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

int T,S,D,N;
int Begin[MaxN];
int End[MaxN];
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

inline void add(int u, int v, int w)
{
    edge[cont].u = u;
    edge[cont].v = v;
    edge[cont].w = w;
    edge[cont].next = head[u];
    head[u] = cont++;
}
inline void Add(int u, int v, int w)
{
    add(u,v,w);
    add(v,u,w);
}

int dis[MaxN];
int vis[MaxN];

int Dijkstra(int s)
{
    for(int i=1;i<=N;i++) dis[i] = INF;
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
            if( dis[v] > dis[u] + edge[i].w)
            {
                dis[v] = dis[u] + edge[i].w;
                Q.push(make_pair(dis[v],v));
            }
        }
    }
    int ans = INF;
    for(int i=0;i<D;i++)
    {
        ans = MIN(ans, dis[End[i]]);
    }
    return ans;
}

inline void init()
{
    cont = 0;
    MST(head, -1);
    N = 0;
}

int main()
{
    while(~scanf("%d%d%d", &T, &S, &D))
    {
        init();
        while(T--)
        {
            int a,b,c;
            scanf("%d%d%d", &a, &b, &c);
            N = MAX(N,a);
            N = MAX(N,b);
            Add(a,b,c);
        }
        for(int i=0;i<S;i++) scanf("%d", &Begin[i]);
        for(int i=0;i<D;i++) scanf("%d", &End[i]);
        int ans = INF;
        for(int i=0;i<S;i++) 
        {
            ans = MIN(ans, Dijkstra(Begin[i]) );
        }
        printf("%d\n", ans);
    }
    //system("pause");
}
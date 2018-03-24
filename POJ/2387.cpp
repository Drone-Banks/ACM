/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
#include <climits>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 1001
#define MaxM MaxN*4
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x;
//不能处理负权图
int T,n;
typedef pair<int,int> pii;   //S集合，first保存到源点距离，second保存点序号。

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

struct cmp
{                        //将优先队列改为小根堆
    bool operator()(pii a,pii b)
    {
        return a.first>b.first;
    }
};
int vis[MaxN];
int dis[MaxN];   //存储起点到每一个点的最短路

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
            if(dis[to] > u.first + edge[i].w)
            {
                dis[to] = u.first + edge[i].w;
                q.push(make_pair(dis[to], to));
            }
        }
    }
    return dis[t];
}

void init()      //记得建图前init()
{
    memset(head,-1,sizeof(head));
    cont=0;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &T, &n))
    {
        init();
        int a,b,c;
        while(T--)
        {
            scanf("%d%d%d", &a, &b, &c);
            add(a,b,c);
            add(b,a,c);
        }
        printf("%d\n", Dijkstra(1,n));
    }
    //system("pause");
}

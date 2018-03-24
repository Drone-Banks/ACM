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

#define MaxN 250010
#define MaxM MaxN*4
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x<<endl;
int n,m;
int Map[501][501];
typedef pair<int,int> pii;   //S集合，first保存到源点距离，second保存点序号。

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
    for(int i=0;i<=n*m+1;i++) dis[i] = INF;
    dis[s] = 0;
    priority_queue<pii,vector<pii>,cmp> q;
    q.push(make_pair(0,s));
    while(!q.empty())
    {
        pii u = q.top();
        q.pop();
        debug(u.first);debug(u.second);
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
    if(dis[t]==INF) return -1;
    else return dis[t];
}

void init()      //记得建图前init()
{
    memset(head,-1,sizeof(head));
    cont=0;
}
char str[600];
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &m))
    {   
        init();
        for(int i=1;i<=n;i++)
        {
            scanf("%s",str);
            for(int j=1;j<=m;j++)
            {
                char ch = str[j-1];
                int x = ch - '0';
                Map[i][j] = x;
                //cout << x << endl;
                if(x==0) continue;
                if(j-Map[i][j]>=1) add( (i-1)*m+j, (i-1)*m+j-Map[i][j], 1);
                if(j+Map[i][j]<=m) add( (i-1)*m+j, (i-1)*m+j+Map[i][j], 1);
                if(i-Map[i][j]>=1) add( (i-1)*m+j, (i-1-Map[i][j])*m+j, 1);
                if(i+Map[i][j]<=n) add( (i-1)*m+j, (i-1+Map[i][j])*m+j, 1);
            }
        }
        printf("%lld\n", Dijkstra(1,n*m));
    }
    //system("pause");
}

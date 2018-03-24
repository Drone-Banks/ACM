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

#define MaxN 200005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;

int N,M,C;
int lay[MaxN];
int flag[MaxN];
struct Edge
{
    int u,v;
    int cost;
    int next;
}edge[MaxM];


int head[MaxN];
int cont;

void add(int u, int v, int cost)
{
    edge[cont].v = v;
    edge[cont].u = u;
    edge[cont].cost = cost;
    edge[cont].next = head[u];
    head[u] = cont++;
}

void Add(int u, int v, int cost)   //添加u-v，权重为cost的边，这个建的是双向，可以改
{
    add(u, v, cost);  
    add(v, u, cost);   
}

void init()                 //!!!!!!!!每次建图前记得init!!!
{
    cont = 0;
    MST(head,-1);
    CLR(lay);
    CLR(flag);
}

bool vis [MaxN];
int dis [MaxN];

int SPFA(int s, int t)
{
    int n = MaxN;         //n赋值为图中点数
    int k, p, V;
    queue<int> q;
    CLR(vis);
    for(int i=1;i<=n;i++)
        dis[i] = INF;
    q.push(s);
    vis[s] = 1;
    dis[s] = 0;
    while(!q.empty())
    {
        k = q.front();
        q.pop();
        vis[k] = 0;
        for(p = head[k]; p!=-1; p = edge[p].next)
        {
            V = edge[p].v;
            if(edge[p].cost + dis[k] < dis[V])
            {
                dis[V] = edge[p].cost + dis[k];
                if(!vis[V])
                {
                    q.push(V);
                    vis[V] = 1;
                }
            }
        }
    }
    if(dis[t] == INF) return -1;   //表示有负权
    return dis[t];
}


int main()
{
    int T;
    cin >> T;
    int tt = 1;
    while(T--)
    {
        init();
        scanf("%d%d%d", &N, &M, &C);
        
        for(int i=1;i<=N;i++)
        {
            int x;
            scanf("%d", &x);
            lay[i] = x;   
            flag[x] = 1;   
        }

        for(int i=1;i<N;i++)
        {
            if( flag[i]==1 && flag[i+1]==1 )
            {
                Add(N+i, N+i+1, C);
            }
        }

        for(int i=1; i<=N; i++)     // 层到点建边  点到相邻层建边
        {
            add(N+lay[i], i, 0);
            if(lay[i]>1) add(i,N+lay[i]-1,C);  
            if(lay[i]<N) add(i,N+lay[i]+1,C);  
        }

        int u,v,w;
        for(int i=0;i<M;i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            Add(u,v,w);
        }
        int ans = SPFA(1,N);
        cout << "Case #" << tt++ << ": " << ans << endl;
        
    }
    system("pause");
}
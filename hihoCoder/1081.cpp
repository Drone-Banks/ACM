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

#define MaxN 100005
#define MaxM MaxN*20
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)
int N, M, S, T;
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
}

bool vis [MaxN];
int dis [MaxN];

int SPFA(int s, int t)
{
    int n = N;         //n赋值为图中点数
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
    while(~scanf("%d%d%d%d", &N, &M, &S, &T))
    {
        init();
        int u, v, w;
        while(M--)
        {
            scanf("%d%d%d", &u, &v, &w);
            Add(u, v, w);
        }
        SPFA(S,T);
        cout << dis[T] << endl;
    }
    system("pause");
}
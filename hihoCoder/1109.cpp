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

#define MaxN 100001
#define MaxM MaxN*20
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)
int N,M;
struct Edge
{
    int u,v,w;
    int next;
    bool operator<(const Edge &a) const
    {
        return w>a.w;
    }
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

int vis[MaxN];
priority_queue<Edge> Q;

int prim()
{
    for(int i = head[1];i!=-1;i=edge[i].next)
    {
        Q.push(edge[i]);
    }
    CLR(vis);
    int ans = 0;
    vis[1] = 1;
    while(N>1 && !Q.empty())
    {
        Edge tmp = Q.top();
        Q.pop();
        if(vis[tmp.v]) continue;
       
        ans += tmp.w;
        N--;
        int u = tmp.v;
        vis[u] = 1;
        for(int k = head[u];k!=-1;k=edge[k].next)
        {
            int v = edge[k].v;
            if(!vis[v]) Q.push(edge[k]);
        }
    }
    return ans;
}

void init()
{
    cont = 0;
    MST(head,-1);
}

int main()
{
    while(~scanf("%d%d", &N, &M))
    {
        init();
        for(int i=0;i<M;i++)
        {
            int a,b,c;
            scanf("%d%d%d", &a,&b,&c);
            add(a,b,c);add(b,a,c);
        }
        printf("%d\n",prim());
    }
    system("pause");
}
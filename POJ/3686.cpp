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

#define MaxN 3000
#define MaxM MaxN*100
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x;
int T;
int N,M;
int n;
struct Edge
{
    int u,v,flow,cost;
    int next;
}edge[MaxM];
int cont;
int head[MaxN];
void add(int u, int v, int flow, int cost)
{
    edge[cont].u = u;
    edge[cont].v = v;
    edge[cont].flow = flow;
    edge[cont].cost = cost;
    edge[cont].next = head[u];
    head[u] = cont++;
}
void Add(int u, int v, int flow, int cost)
{
    add(u,v,flow,cost);
    add(v,u,0,-cost);
}
bool vis[MaxN];
int dist[MaxN];
int pre[MaxN];
int s,t,aug;
int ans;
int KK;
bool SPFA()
{
    int k,p,V;
    queue<int> Q;
    MST(pre,-1);
    CLR(vis);
    fill_n(dist, n+1, INF);
    Q.push(s);
    vis[s] = true;
    dist[s] = 0;
    while(!Q.empty())
    {
        k = Q.front();
        Q.pop();
        vis[k] = 0;
        for(p=head[k];p!=-1;p=edge[p].next)
        {
            V = edge[p].v;
            if(edge[p].flow && (edge[p].cost + dist[k] < dist[V]))
            {
                dist[V] = edge[p].cost + dist[k];
                pre[V] = p;
                if(!vis[V])
                {
                    Q.push(V);
                    vis[V] = 1;
                }
            }
        }
    }
    if(dist[t] == INF) return false;
    aug = INF+1;
    for(p=pre[t];p!=-1;p=pre[edge[p].u]) aug = min(aug, edge[p].flow);
    for(p=pre[t];p!=-1;p=pre[edge[p].u])
    {
        edge[p].flow -= aug;
        edge[p^1].flow += aug;
    }
    ans += dist[t]*aug;
    KK += aug;
    return true;
}
void init()
{
    MST(head,-1);
    cont = 0;
    n = 0;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &T);
    while(T--)
    {
        init();
        scanf("%d%d", &N, &M);
        for(int i=1;i<=N;i++)
        {
            Add(0,i,1,0);
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                int x;
                scanf("%d", &x);
                for(int k=1;k<=N;k++)
                {
                    Add(i, N+(j-1)*N+k, 1, k*x);
                }
            }
        }
        for(int j=1;j<=M;j++)
        {
            for(int k=1;k<=N;k++)
            {
                Add(N+(j-1)*N+k, (M+1)*N+1, 1, 0);
            }
        }
        n = (M+1)*N+1;
        s = 0;
        t = n;
        ans = 0;
        KK = 0;
        while(SPFA());
        printf("%.6f\n", ans*1.0/N*1.0);
    }
    //system("pause");
}

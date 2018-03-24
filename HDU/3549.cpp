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
int T;
int N, M;
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
int pre[MaxN];
int cur[MaxN];
queue<int> Q;
bool BFS(int src, int des)
{
    while(!Q.empty()) Q.pop();
    for(int i=1;i<=N;i++) pre[i] = -1;
    pre[src] = 0;
    Q.push(src);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if(u == des) break;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            if(pre[v] == -1 && edge[i].w)
            {
                pre[v] = u;
                cur[v] = i;
                Q.push(v);
            }
        }
        if(pre[des] != -1) break;
    }
    if(pre[des] == -1) return false;
    else return true;
}
int EK(int src, int des)
{
    int maxflow = 0;
    while( BFS(src, des) )
    {
        int aug = INF;
        for (int v = des; v != src; v = pre[v]) 
        {
            aug = MIN(aug, edge[cur[v]].w);
        }
        for (int v = des; v != src; v = pre[v]) 
        {
            edge[cur[v]].w -= aug;
            edge[cur[v]^1].w += aug;
        }
        maxflow += aug;
    }
    return maxflow;
}
void init()
{
    cont = 0;
    MST(head, -1);
}
int main()
{
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
    {
        init();
        scanf("%d%d", &N, &M);
        for(int i=0;i<M;i++)
        {
            int a,b,c;
            scanf("%d%d%d", &a, &b, &c);
            if(a==b) continue;
            add(a,b,c);
            add(b,a,0);
        }
        int ans = EK(1,N);
        printf("Case %d: %d\n", t, ans);
    }
    system("pause");
}   
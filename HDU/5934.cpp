/*************************************************************************
    > File Name: B.cpp
    > Author: Akira
    > Mail: qaq.febr2.qaq@gmail.com
    > Created Time: 2017年05月05日 星期五 19时37分48秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<cmath>
#include<vector>
#include<set>
#include<list>
#include<ctime>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))

using namespace std;

#define MaxN 1010
#define MaxM MaxN*1000
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1e9+7;
const int eps = 1e-8;
#define bug cout << 88888888 << endl;

struct Node
{
    int x,y,r,c;
}node[MaxN];

int T,N;

struct Edge
{
    int u,v,next;
}edge[MaxM],e[MaxM];
int cont, head[MaxN];
void add(int u, int v)
{
    edge[cont].u = u;
    edge[cont].v = v;
    edge[cont].next = head[u];
    head[u] = cont++;
}

int low[MaxN], dfn[MaxN];
int Stack[MaxN], top;
int belong[MaxN];
int vis[MaxN];
int Index, cnt;
int cost[MaxN];
void init()
{
    cont = 0;
    MST(head,-1);
    
    MST(cost,INF);
    MST(dfn, -1);
    CLR(low);
    CLR(vis);
    Index = cnt = 1;
    top = 0;
}
void Tarjan(int x)
{
    low[x] = dfn[x] = Index;
    Index++;
    Stack[++top] = x;
    vis[x] = true;
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(dfn[v] == -1)
        {
            Tarjan(v);
            low[x] = min(low[x], low[v]);
        }
        else if(vis[v])
        {
            low[x] = min(low[x], dfn[v]);
        }
    }
    if( low[x] == dfn[x] )
    {
        for(int v = -1;v!=x;top--)
        {
            v = Stack[top];
            vis[v] = false;
            belong[v] = cnt;
            cost[cnt] = min(cost[cnt], node[v].c);
        }
        cnt++;
    }
}
int in[MaxN];

void solve(int t)
{
    init();
    for(int i=1;i<=N;i++)
    {
        int xi = node[i].x;
        int yi = node[i].y;
        int ri = node[i].r;
        for(int j=1;j<=N;j++)
        {
            if(i==j) continue;
            LL dis = Sqr((LL)(node[j].x-xi)) + Sqr((LL)(node[j].y-yi));
            if( dis<=Sqr((LL)ri) ) 
            {
                add(i,j);
                //cout << i << " " << j << endl;
            }
        }
    } 
    for(int i=1;i<=N;i++) 
        if(dfn[i]==-1)
            Tarjan(i);

    CLR(in);
    for(int i=0;i<cont;i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        if(belong[u] != belong[v])
        {
            //cout << u << ": " << belong[u] << endl;
            //cout << v << ": " << belong[v] << endl; 
            in[belong[v]]++;
        }
    }
    int ans = 0;
    for(int i=1;i<cnt;i++)
    {
        //cout << in[i] << endl;
        if(in[i]==0) ans += cost[i];
    }
    printf("Case #%d: %d\n",  t, ans);

}

int main()
{
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d", &N);
        for(int i=1;i<=N;i++) scanf("%d%d%d%d", &node[i].x, &node[i].y, &node[i].r, &node[i].c);
        solve(t);
    }
}
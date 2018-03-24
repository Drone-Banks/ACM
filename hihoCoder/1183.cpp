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

int N,M;

struct Edge
{
    int from, to, next;
}edge[MaxM];
int head[MaxN],cont;
int vis[MaxN];
int low[MaxN];
int dfn[MaxN];
int parent[MaxN];
int Index;
vector<pair<int,int> > E;
int Vertex[MaxN];


bool cmp(pair<int,int> a,pair<int,int> b)
{
	if(a.first==b.first)
		return a.second<b.second;
	return a.first<b.first;
}

void init()
{
    MST(head,-1);
    cont=0;
    CLR(parent);
    
    MST(dfn,-1);
    CLR(vis);
    CLR(low);
    Index = 1;
    CLR(Vertex);
}

void add(int u,int v)
{
    edge[cont].from = u;
    edge[cont].to=v;
    edge[cont].next=head[u];
    head[u]=cont++;
}
int NIL;

void Tarjan(int u)  //DFS
{
    vis[u] = 1;
    low[u] = dfn[u] = Index++;                // 刚搜到一个节点时low = dfn
    int children = 0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(!vis[v])
        {
            children++;
            parent[v] = u;
            Tarjan(v);

            low[u]=MIN(low[u], low[v]);     // 回溯的时候改变当前节点的low值
            
            if(parent[u] == NIL && children > 1)
            {
                Vertex[u] = 1;
            }

            if(parent[u] != NIL && low[v] >= dfn[u])
            {
                Vertex[u] = 1;
            }

            if( low[v] > dfn[u] )
            {
                E.push_back(make_pair(min(u,v), max(u,v)));
                //cout << v << " " << u << endl;
            }
        }
        else if( v!=parent[u])
        {
            low[u] = MIN(low[u], dfn[v]); 
        }
    }
}

int main()
{
    while(~scanf("%d%d", &N, &M))
    {
        init();     
        int u,v;
        while(M--)
        {
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }
        NIL = 0;
        Tarjan(3);
        int flag=0;
	    for(int i=1;i<=N;i++) 
		{
            if(Vertex[i])
            {
                if(flag) printf(" ");
                flag++;
                printf("%d",i);
            } 
        }         
        if(!flag) printf("Null");
	    printf("\n");       
        sort(E.begin(),E.end(),cmp);
        for(int i=0;i<E.size();i++)
            printf("%d %d\n",E[i].first, E[i].second);
    }
    system("pause");
}

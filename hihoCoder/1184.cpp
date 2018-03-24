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

struct Edge{
    int u,v,next;
}edge[MaxM];

int cont;
int head[MaxN];

int dfn[MaxN];
int low[MaxN];

int Stack[MaxN], top;
int belong[MaxN];
int parent[MaxN];
int vis[MaxN];
int Index,cnt;
map<int, int> Map;

void init()
{
    cont = 0;
    MST(head, -1);

    MST(dfn, -1);
    CLR(low);
    CLR(vis);
    CLR(parent);
    cont = 0;
    Index = cnt = 1;
    top = 0;
    Map.clear();
}

void add(int u, int v){
    edge[cont].u = u;
    edge[cont].v = v;
    edge[cont].next = head[u];
    head[u] = cont++;
}

void Add(int u, int v){
    add(u, v);
    add(v, u);
}

void Tarjan(int u){
    low[u] = dfn[u] = Index++;
    Stack[++top] = u;
    vis[u] = 1;
    
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        
        if(!vis[v]){
            parent[v] = u;
            Tarjan(v);
            
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]){
                cnt++;
            }
        }
        else if( v != parent[u]){
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]){
        for( int v=-1;v!=u;top--){
            v = Stack[top];
            vis[v] = 0;
            belong[v] = cnt;
            if(Map[cnt] == 0) Map[cnt] = v;
            else{
                if(v<Map[cnt]) Map[cnt] = v;
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d", &N, &M))
    {
        init();
        int u,v;
        while(M--){
            scanf("%d%d", &u, &v);
            Add(u, v);
        }

        for(int i=1;i<=N;i++)
        {
            if( dfn[i] == -1){
                Tarjan(i);
            }
        }
        cout << cnt << endl;
        for(int i=1;i<=N;i++)
        {
            //cout << i << ":" << belong[i] << endl;
            cout << Map[belong[i]];
            if(i!=N) cout << " ";
        }
    }
    system("pause");
}
/*************************************************************************
	> File Name: 1050.cpp
	> Author: Akira 
	> Mail: qaq.febr2.qaq@gmail.com 
	> Created Time: 2016年10月07日 星期五 13时16分45秒
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

int N;
struct Edge
{
    int u,v;
    int next;
}edge[MaxM];

int head[MaxN];
int cont;

void init()
{
    MST(head, -1);
    cont = 0;
}

void add(int u, int v)
{
    edge[cont].u = u;
    edge[cont].v = v;
    edge[cont].next = head[u];
    head[u] = cont++;
}

void Add(int u, int v)
{
    add(u, v);
    add(v, u);
}

int vis[MaxN];
int node;
int level;
void dfs(int x, int lel)
{
    vis[x] = 1;
    //cout << x << "---" << lel << endl;
    if(lel > level)
    {
        node = x;
        level = lel;
    }

    for(int i = head[x]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].v;
        //cout << v << "::" << vis[v] << endl;
        if(!vis[v]) dfs(v, lel+1);
    }
}

int main()
{
    while(~scanf("%d", &N))
    {
        init();
        int a,b;
        for(int i=1;i<N;i++)
        {
            scanf("%d%d", &a, &b);
            Add(a, b);
        }
        CLR(vis);
        level = 0;
        dfs(1, 0);
        //cout << level << "-" << node << endl;
        
        CLR(vis);
        level = 0;
        dfs(node, 0);
        cout << level << endl;
    }
}

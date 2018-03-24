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

#define MaxN 300001
#define MaxM MaxN*2
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

struct Edge
{
    int u,v,w;
    int next;
}edge[MaxM];


int head[MaxN];
int cont;

void add(int u, int v, int w)
{
    edge[cont].v = v;
    edge[cont].u = u;
    edge[cont].w = w;
    edge[cont].next = head[u];
    head[u] = cont++;
}

void Add(int u, int v, int w)   //添加u-v，权重为cost的边，这个建的是双向，可以改
{
    add(u, v, w);  
    add(v, u, w);   
}

void init()                 //!!!!!!!!每次建图前记得init!!!
{
    cont = 0;
    MST(head,-1);
}


bool vis [MaxN];
int dis [MaxN];
int cnt [MaxN];
int Min;
int Max;

bool SPFA(int s)
{
    int n = Max - Min+1;         //n赋值为图中点数
    CLR(vis);
    CLR(cnt);

    for(int i=Min;i<=Max;i++) dis[i] = INF;
    dis[s] = 0;

    queue<int> q;
    q.push(s);
    vis[s] = 1;
    cnt[s] = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = head[u]; i!=-1; i=edge[i].next)
        {
            int v= edge[i].v;
            if(dis[v] > edge[i].w + dis[u] )
            {
                dis[v] = edge[i].w + dis[u];
                if(!vis[v])
                {
                    if(cnt[i]>=n) return true;
                    q.push(v);
                    cnt[v]++;
                    vis[v] = 1;
                }
            }
        }
    }
    return false;
}

int main()
{
    int x;
    while(~scanf("%d", &x))
    {
        init();
        Min = INF;
        Max = 0;
        while(x--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            Min = MIN(Min,MIN(b+1, a));
            Max = MAX(Max,MAX(a, b+1));
            //add(a,b+1,2);
           add(b+1,a,-2);
        }
        for(int i=0;i<Max;i++)
        {
            //add(i+1,i,-1);
            //add(i,i+1,0);
            add(i,i+1,1);
            add(i+1,i,0);
        }
        SPFA(Min);
        printf("%d\n", dis[Max]-dis[Min]);
    }
    system("pause");
}
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

#define MaxN 120
#define MaxM MaxN*100
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

typedef pair<int,int> pii;  
struct cmp
{                        //将优先队列改为小根堆
    bool operator()(pii a,pii b)
    {
        return a.first>b.first;
    }
};

int n,k;
int N=110;
int T[MaxN];
int cost[MaxN][MaxN];


int vis[MaxN];
int dis[MaxN];

void Dijkstra(int s, int t)
{
    CLR(vis);
    for(int i=0;i<=N;i++) dis[i] = INF;
    dis[s] = 0;
    priority_queue<pii,vector<pii>,cmp> q;
    q.push(make_pair(0,s));
    while(!q.empty())
    {
        pii tmp = q.top();
        q.pop();
        int u = tmp.second;
        if(vis[u]) continue;
        vis[u] = 1;
        for(int v=0; v<=N; v++)
        {
            if(dis[v] > dis[u]+cost[u][v]+60)
            {
                dis[v] = dis[u] + cost[u][v]+60;
                q.push(make_pair(dis[v], v));
            }
        }
    }
    if(dis[t] == INF)
    {
        printf("IMPOSSIBLE\n");
    }
    else
    {
        if(t) printf("%d\n", dis[t]-60);
        else printf("0\n");
    }
}

void init()
{
    for(int i=0;i<=110;i++)
        for(int j=0;j<=110;j++)
            cost[i][j] = INF;
}
int main()
{
    while(~scanf("%d%d" , &n , &k))
    {
        init();      
        for(int i=1; i<=n; i++) scanf("%d" , &T[i]);
        for(int i=1; i<=n; i++)
        {
            int floor[MaxM];
            int num = 0;
            do{scanf("%d" , &floor[num++]);}while(getchar()!='\n') ;
            for(int j=0; j<num; j++)
            {
                for(int k=j; k<num; k++)
                {
                    int a = floor[j], b = floor[k];
                    int tmp = MIN(abs(a-b)*T[i], cost[a][b]);
                    cost[a][b] = cost[b][a] = tmp;
                }
            }
        }
        Dijkstra(0,k);        
    }
    system("pause");
}
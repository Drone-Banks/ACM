/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <iomanip>
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

#define MaxN 1000010
#define MaxM MaxN*2
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}

int N,M;
struct Edge
{
    int u,v,w;
    int next;
}edge[MaxM];

int head[MaxN];
int cont;

void add(int u, int v, int w)
{
    edge[cont].u = u;
    edge[cont].v = v;
    edge[cont].w = w;
    edge[cont].next = head[u];
    head[u] = cont++;
}

void Add(int u, int v, int w)
{
    add(u, v, w);
    add(v, u, w);
}

int vis[MaxN];
int node;
int level;
int dis[MaxN];
void DFS(int x, int lel)
{
    vis[x] = 1;
    dis[x] = max(lel, dis[x]);
    //cout << x << "---" << lel << endl;
    if(lel >= level)
    {
        node = x;
        level = lel;
    }

    for(int i = head[x]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].v;
        //cout << v << "::" << vis[v] << endl;
        if(!vis[v]) DFS(v, lel+edge[i].w);
    }
}

int Q_Max[MaxN], Q_Min[MaxN];

void solve()
{
    int ans = 0;
    int Max_front,Max_tail,Min_front,Min_tail,i,j;
    Max_front = Min_front = 1, Max_tail = Min_tail = 0;
    for(i=1,j=1;i<=N;i++)
    {
        while(Max_tail >= Max_front && dis[Q_Max[Max_tail]] <= dis[i] ) Max_tail--;
        Q_Max[++Max_tail] = i;

        while(Min_tail >= Min_front && dis[Q_Min[Min_tail]] >= dis[i] ) Min_tail--;
        Q_Min[++Min_tail] = i;

        if( dis[Q_Max[Max_front]] - dis[Q_Min[Min_front]] > M) 
        {
            ans = max(ans, i - j);
            while (dis[Q_Max[Max_front]] - dis[Q_Min[Min_front]] > M)
            {
                j = min(Q_Max[Max_front], Q_Min[Min_front]) + 1;
                while (Max_tail >= Max_front && Q_Max[Max_front] < j) Max_front++;
                while (Min_tail >= Min_front && Q_Min[Min_front] < j) Min_front++;
                //bug;
            }
        }
        //debug(dis[i])
    }
    ans = max(ans, i - j);
    printf("%d\n", ans);
}

void init()
{
    MST(head, -1);
    cont = 0;
    CLR(dis);
}

int main()
{
    while(~scanf("%d%d", &N, &M))
    {
        init();
        int a,b;
        for(int i=1;i<N;i++)
        {
            scanf("%d%d", &a, &b);
            Add(i+1, a, b);
        }
        CLR(vis);
        level = 0;
        DFS(1, 0);
        
        CLR(vis);
        level = 0;
        DFS(node, 0);

        CLR(vis);
        DFS(node, 0);

        solve();
    }
}

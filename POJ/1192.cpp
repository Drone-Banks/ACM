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

#define MaxN 1001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
int N;
struct Node
{
    int x,y,c;
}node[MaxN];
struct Edge
{
    int u,v,next;
}edge[MaxM];
int cont, head[MaxN];
void add(int u,int v)
{
    edge[cont].u=u, edge[cont].v=v, edge[cont].next=head[u], head[u]=cont++;
}
bool check(Node a, Node b)
{
    if(abs(a.x-b.x)+abs(a.y-b.y) == 1) return true;
    else return false;
}
bool vis[MaxN];
int ans, DP[MaxN];
void DFS(int u, int pre)
{
    DP[u] = node[u].c;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(v==pre) continue;
        DFS(v,u);
        if(DP[v]>0) DP[u]+=DP[v];
    }
}
void init()
{
    cont = 0,ans=-101;
    MST(head,-1);CLR(vis);CLR(DP);
}
void solve()
{
    init();
    for(int i=1;i<=N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            if(check(node[i],node[j])) add(i,j),add(j,i);
        }
    }
    for(int i=1;i<=N;i++)
    {
        if(!vis[i]) DFS(i,i);
    }
    for(int i=1;i<=N;i++) ans=max(ans,DP[i]);
    printf("%d\n", ans);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &N))
    {
        
        int a,b,c;
        for(int i=1;i<=N;i++)
        {
            scanf("%d%d%d", &node[i].x, &node[i].y, &node[i].c);
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

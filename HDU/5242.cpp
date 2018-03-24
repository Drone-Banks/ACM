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

#define MaxN 100010
#define MaxM MaxN
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
struct Edge
{
    int u,v,next;
}edge[MaxM];
int cont,head[MaxN];
void add(int u, int v)
{
    edge[cont].u = u;
    edge[cont].v = v; 
    edge[cont].next = head[u]; 
    head[u] = cont++;
}
struct Node
{
    int id;
    int son;
    LL MAX;
    bool operator < (const Node &a ) const
    {
        return MAX < a.MAX ;
    }
}node[MaxN],tmp;
int n,k,vis[MaxN];
LL val[MaxN];

void dfs(int u)
{
    LL mm=-1;
    node[u].id = u;
    node[u].MAX = val[u];
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        dfs(v);
        if(mm < node[v].MAX) 
        {
            mm = node[v].MAX;
            node[u].son = v;
        }
    }
    if(mm>=0) node[u].MAX += mm;
}
priority_queue<Node> Q;
void split(int u)
{
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(v==node[u].son) split(v);
        else 
        {
            if(!vis[v])
            {
                Q.push(node[v]);
                vis[v] = 1;
            }
        }
    }
}
void solve(int t)
{
    dfs(1);
    vis[1] = 1; 
    Q.push(node[1]);
    LL ans = 0;
    while(k&&!Q.empty())
    {
        k--;
        tmp = Q.top();
        Q.pop();
        ans += tmp.MAX;
        int u = tmp.id;
        split(u);
        
    }
    printf("Case #%d: %lld\n", t, ans);
}
void init()
{
    cont = 0;
    MST(head,-1);
    CLR(node);
    CLR(vis);
    while(!Q.empty()) Q.pop();
}
int main()
{
    //std::ios::sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
    {
        init();
        scanf("%d%d", &n, &k);
        for(int i=1;i<=n;i++) scanf("%lld", val+i);
        int a,b;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d", &a, &b);
            add(a,b);
        }
        solve(t);
    }
    //system("pause");
}

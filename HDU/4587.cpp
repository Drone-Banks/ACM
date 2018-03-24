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

#define MaxN 5001
#define MaxM MaxN*2
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;

struct Edge
{
    int u, v, next;
}edge[MaxM];
int cont,head[MaxN];
int n,m;
void add(int u, int v)
{
    edge[cont].u = u; 
    edge[cont].v = v; 
    edge[cont].next = head[u]; 
    head[u] = cont++;
}

int dfn[MaxN],low[MaxN],vis[MaxN];
int sum[MaxN],ans,ret,del,tot,tmp;

void dfs(int u, int fa)
{
    dfn[u] = low[u] = tmp++;
    vis[u] = 1;
    sum[u] = 0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(v!=del && v!=fa)
        {
            if(!vis[v])
            {
                dfs(v,u);
                low[u] = min(low[v], low[u]);
                if(low[v] >= dfn[u]) sum[u]++;
            }
            else low[u] = min(low[u],dfn[v]);
        }
    }
    if(u==fa) sum[u]--;
    if(ans<sum[u]) ans=sum[u];
    return;
}

void solve()
{
    ans = -1;tot=0;
    CLR(vis);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i] && i!=del)
        {
            tmp = 0;
            dfs(i,i); 
            tot++;
        }
    }
    if(ret < ans + tot) 
        ret = ans+tot;
    return;
}

void init()
{
    MST(head,-1);
    cont = 0;
    CLR(dfn),CLR(low),CLR(sum);
    ret = 0;
}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &m))
    {
        init();
        int a,b;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d", &a, &b);
            a++,b++; 
            add(a,b),add(b,a);
        }
        for(int i=1;i<=n;i++)
        {
            del = i; 
            solve();
        }
        printf("%d\n", ret);
    }
    //system("pause");
}
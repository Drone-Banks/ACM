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

#define MaxN 2000
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
int N;
struct Edge
{
    int u, v, next;
}edge[MaxM];
int cont, head[MaxN];
void add(int u, int v)
{
    edge[cont].u = u, edge[cont].v = v, edge[cont].next = head[u], head[u] = cont++;
}

int dfn[MaxN],low[MaxN],index;
int sum[MaxN];
int node[MaxN],rnode[MaxN];
void Tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++index;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(v==fa) continue;
        if(!dfn[v] )
        {
            Tarjan(v,u);
            if(low[v] < low[u]) low[u] = low[v];
            if( low[v] >= dfn[u]) sum[u]++;
        }
        else if(  dfn[v] < low[u]) low[u] = dfn[v];
    }
    if(u==fa) sum[u]--;
}
int ans[MaxN];
void solve(int t)
{
    for(int i=1;i<=N;i++)
    {
        //debug(dfn[i])
        if(!dfn[i]) Tarjan(i,i);
        //debug(dfn[i])
    }
    bool flag = false;
    for(int i=1;i<=N;i++)
    {
        if(sum[i])
        {
            ans[rnode[i]] = sum[i]+1;
            if(!flag) flag = true;
        }
        //debug(i) debug(sum[i])
    }
    cout << "Network #" << t << endl;
    if(flag)
    {
        for(int i=1;i<=1000;i++)
        {
            if(ans[i])
            {
                cout << "  SPF node " << i << " leaves " << ans[i] << " subnets\n";
            }
        }
    }
    else cout << "  No SPF nodes" << endl;
    cout << endl;
}
void init()
{
    N = 0;
    cont = 0;
    MST(head,-1);
    CLR(node);
    CLR(sum);
    CLR(dfn);
    CLR(low);
    index = 0;
    CLR(ans);
}
int main()  
{  
    //fread();  
    //fwrite();  
  
    int u,v; 
    int t = 0;
    bool flag = false; 
    while(~scanf("%d",&u) && u)  
    {  
        if(u)
        {
            t++;
            flag = false;
            scanf("%d",&v);
            init();  
            if(!node[u]) 
            {
                node[u] = ++N;
                rnode[N] = u;
            }
            if(!node[v]) 
            {
                node[v] = ++N;
                rnode[N] = v;
            }
            add(node[u],node[v]), add(node[v],node[u]);  
            while(~scanf("%d",&u) && u)  
            {  
                scanf("%d",&v);  
                if(!node[u]) 
                {
                    node[u] = ++N;
                    rnode[N] = u;
                }
                if(!node[v]) 
                {
                    node[v] = ++N;
                    rnode[N] = v;
                }
                add(node[u],node[v]), add(node[v],node[u]);  
            }
            solve(t);
        }
        else   
        {
            if(flag) break;
            if(!flag) flag = true;
        }
    }  
  
    return 0;  
} 
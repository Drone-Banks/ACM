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

#define MaxN 1005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}

int N,M;
int Map[MaxN][MaxN];

int dfn[MaxN],low[MaxN],index;
int ans;
void Tarjan(int u,int fa)
{
    //debug(u);
    dfn[u] = low[u] = ++index;
    for(int v = 1;v<=N;v++)
    {
        if(Map[u][v]==-1) continue;
        if(!dfn[v])
        {
            Tarjan(v,u);
            if(low[v]<low[u]) low[u] = low[v];
            if(low[v] > dfn[u]) 
            {
                ans = min(ans, Map[u][v]);
            }
        }
        else if( dfn[v] < low[u] && v!=fa) low[u] = dfn[v];
    }
}

void solve()
{
    bool flag = false;
    Tarjan(1,1);
    for(int i=1;i<=N;i++)
    {
        if(!dfn[i]) 
        {
            flag = true;
            break;
        }
    }
    if(flag) puts("0");
    else if(ans==INF) puts("-1");
    else if(ans==0) puts("1");
    else printf("%d\n", ans);
}
void init()
{
    MST(Map,-1);
    CLR(dfn);
    CLR(low);
    index = 0;
    ans = INF;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &N, &M) && (N+M))
    {
        init();
        int u,v,w;
        while(M--)
        {
            scanf("%d%d%d", &u, &v, &w);
            if(Map[u][v]!=-1) Map[u][v] = Map[v][u] = INF;
            else Map[u][v] = Map[v][u] = w;
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

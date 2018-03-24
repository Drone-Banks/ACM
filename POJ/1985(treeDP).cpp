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
#define ALL(a) a.begin(), a.end()
using namespace std;

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
inline int max2(int a, int b) {return ((a > b)? a : b);}
inline int min2(int a, int b) {return ((a < b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}
inline int min3(int a, int b, int c) {return min2(a, min2(b, c));}

int N,M;
struct Edge
{
    int u,v,w,next;
}edge[MaxM];
int cont, head[MaxN];

void add(int u, int v, int w)
{
    edge[cont].u = u, edge[cont].v = v, edge[cont].w = w, edge[cont].next = head[u], head[u] = cont++;
}

int DP[MaxN][2];

void DFS(int u, int fa)
{
    //debug(u)
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(v==fa) continue;
        DFS(v, u);
        //debug(v)
        int cnt = edge[i].w + DP[v][1];
        if( cnt > DP[u][1])
        {
            DP[u][0] = DP[u][1];
            DP[u][1] = cnt;
        }
        else if( cnt == DP[u][1] || cnt > DP[u][0] )
        {
            DP[u][0] = cnt;
        }
        //debug(DP[u][1]) debug(DP[u][0])
    }
}

void solve()
{
    CLR(DP);
    DFS(1, 1);
    int ans = 0;
    for(int i=1;i<=N;i++)
    {
        // debug(i)
        // debug(DP[i][1]) debug(DP[i][0])
        ans = max(ans, DP[i][1]+DP[i][0]);
    }
    printf("%d\n", ans);
}
void init()
{
    cont = 0, MST(head,-1);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &N, &M))
    {
        init();
        int u,v,w;
        char ch;
        while(M--)
        {
            scanf("%d %d %d %c", &u, &v, &w, &ch);
            add(u,v,w);
            add(v,u,w);
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x+mod)%mod );
}

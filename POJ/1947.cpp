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

#define MaxN 166
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
int N, P;
vector<int> G[MaxN];
int dsize[MaxN], DP[MaxN][MaxN],ans;
void DFS(int u)
{
    dsize[u] = 1;
    for(int i=0;i<G[u].size();i++)
    {
        int v = G[u][i];
        DFS(v);
        dsize[u]+=dsize[v];
    }
    DP[u][1] = G[u].size();
    for(int i=0;i<G[u].size();i++)
    {
        int v = G[u][i];
        for(int j=dsize[u];j>=1;j--)
        {
            for(int k=1;k<j && k<=dsize[v]; k++) 
            {
                DP[u][j] = min(DP[u][j], DP[u][j-k]+DP[v][k]-1); //DP[u][j-k]为u子树保留j-k个节点最少要删除的边,DP[v][k]为v子树保留k个要删除的边，将他们连在一块需要增加一条边，所以减1
            }
        }
    }
    if(dsize[u]>=P) ans = min(ans, DP[u][P]+ (u!=1) ); //如果不是根节点，需要再删除一条与父节点的边
}
void solve()
{
    DFS(1);
    printf("%d\n",ans);
}
void init()
{
    ans = INF;
    MST(DP,INF);
    for(int i=1;i<=N;i++) G[i].clear();
    CLR(dsize);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &N, &P))
    {
        init();
        int a,b;
        for(int i=1;i<N;i++)
        {
            scanf("%d%d", &a, &b);
            G[a].push_back(b);
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

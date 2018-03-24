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

#define MaxN 200001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
int T;
int n,m,k;
vector<int> V[MaxN];
LL DFS(int pre, int u, int x)
{
    if(x==4) return 1LL;
    LL ans = 0;
    for(int i=0;i<V[u].size();i++)
    {
        int v = V[u][i];
        if( v!=pre)
        {
            ans += DFS(u, v, x+1);
        }
    }
    return ans;
}
void solve()
{
    LL ans = 0;
    for(int i=1;i<=(n+m);i++)
    {
        ans +=  DFS(0, i, 1);
    }
    printf("%I64d\n", ans);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m, &k);
        for(int i=1;i<=(n+m);i++) V[i].clear();
        int a,b;
        while(k--)
        {
            scanf("%d%d", &a, &b);
            V[a].push_back(b+n);
            V[n+b].push_back(a);
        }
        solve();
        getchar();
    }
    //system("pause");
}

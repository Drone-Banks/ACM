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

#define MaxN 10010
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}

int V,n;
int c[MaxN];
double w[MaxN],DP[MaxN];
void ZeroOnePack(int cost, double weight)  //O(N*V)
{
    for(int v=V;v>=cost;v--)            //逆序遍历，保证每种物品只能被选择一次
        DP[v] = max(DP[v], 1-(1-DP[v-cost])*(1-weight)); 
}

void solve()
{
    for(int i=0;i<=V;i++) DP[i] = 0;
    for(int i=1;i<=n;i++)
        ZeroOnePack(c[i],w[i]);
    printf("%.1lf%%\n", 100*DP[V]);
}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(scanf ("%d%d", &V, &n)!=EOF && V+n)
    {
        for(int i=1;i<=n;i++) scanf ("%d%lf", &c[i], &w[i]);
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}
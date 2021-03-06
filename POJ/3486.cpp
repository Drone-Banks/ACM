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
int c,n;
int Map[MaxN][MaxN];
int dp[MaxN];
void solve()    
{
    MST(dp,INF);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i] = min(dp[i], dp[j-1]+c+Map[j][i]);
        }
    }
    printf("%d\n", dp[n]);
}
int main()
{
    //std::ios::sync_with_stdio(false);
        while(scanf("%d",&c)!=EOF)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                scanf("%d",&Map[i][j]);
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

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
int n;
int t[MaxN];
int dp[MaxN];
void solve()    
{
    sort(t+1,t+1+n);
    MST(dp,INF);
    dp[1]=t[1];
    dp[2]=t[2];
    for(int i=3;i<=n;i++)
    {
        dp[i] = min(dp[i-1]+t[1]+t[i], dp[i-2]+t[1]+t[i]+2*t[2]);
    }
    printf("%d\n", dp[n]);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&t[i]);
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

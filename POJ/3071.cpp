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

int n;
double p[130][130];
double dp[130][10];

void solve()
{
    CLR(dp);
    for(int i=0;i<(1<<n);i++) dp[i][0] = 1;
    for(int i=1;i<=n;i++) //ju
    {
        //debug(i)
        for(int j=0;j<(1<<n);j++)
        {
            //debug(j)
            for(int k=(j&(~(1<<(i-1)))+1)^(1<<(i-1)),c=0;c<(1<<(i-1));c++)
            {
                //debug(k)
                //debug(k+c)
                dp[j][i] += dp[j][i-1]*dp[k+c][i-1]*p[j+1][k+c+1];
                //debug(dp[j][i])
            }
        }
    }
    double tmp = 0.0;
    int ans;
    for(int i=0;i<(1<<n);i++) 
    {
        //debug(i) debug(dp[i][n])
        double cnt = dp[i][n] - 0.01 - tmp;
        //debug(cnt)
        if( cnt >= 0 ) 
        {
            tmp = dp[i][n];
            ans = i+1;
            //debug(tmp)
        }
    }
    printf("%d\n", ans);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &n) && n!=-1)    
    {
        for(int i=1;i<=(1<<n);i++)
        {
            for(int j=1;j<=(1<<n);j++)
            {
                scanf("%lf", &p[i][j]);
            }
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x+mod)%mod );
}

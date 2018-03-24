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

int M,T,N;
double p[1010][33];
double dp[1010][33][33];
double sum[1010][33];
void solve()
{
    CLR(dp);
    for(int i=1;i<=T;i++)
    {
        dp[i][0][0] = 1;
        for(int j=1;j<=M;j++)
        {
            dp[i][j][0] = dp[i][j-1][0]*(1-p[i][j]);
            for(int k=1;k<=j;k++)
            {
                dp[i][j][k] += dp[i][j-1][k-1]*p[i][j] + dp[i][j-1][k]*(1-p[i][j]);
            }
        }
        sum[i][0] = dp[i][M][0];
        for(int j=1;j<=M;j++)
        {
            sum[i][j] = sum[i][j-1] + dp[i][M][j];
        }
    }
    double tmp = 1, pmt = 1;
    for(int i=1;i<=T;i++)
    {
        tmp *= (sum[i][N-1]-sum[i][0]);
        pmt *= (1-sum[i][0]);
    }
    //debug(pmt) debug(tmp)
    printf("%.3f\n", pmt-tmp);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d%d", &M, &T, &N) && (M+T+N) )    
    {
        for(int i=1;i<=T;i++)
        {
            for(int j=1;j<=M;j++)
            {
                scanf("%lf", &p[i][j]);
            }
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x+mod)%mod );
}

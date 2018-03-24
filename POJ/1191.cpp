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

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
int n;
int matrix[10][10];
LL s[10][10],sf[10][10][10][10],dp[15][10][10][10][10];
LL sum;
void init()
{
    CLR(s);CLR(sf);MST(dp,INF);sum=0;
    for(int i=1;i<=8;i++)
    for(int j=1;j<=8;j++)
    {
        s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + matrix[i][j];
        sum+=matrix[i][j];
    }
    for(int x1=1;x1<=8;x1++)
    for(int y1=1;y1<=8;y1++)
    for(int x2=x1;x2<=8;x2++)
    for(int y2=y1;y2<=8;y2++)
    {
        dp[0][x1][y1][x2][y2] = sf[x1][y1][x2][y2] = Sqr(s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1]);
    }
}
void solve()
{
    init();
    for(int k=1;k<n;k++)
    {
        for(int x1=1;x1<=8;x1++)
        for(int y1=1;y1<=8;y1++)
        for(int x2=x1;x2<=8;x2++)
        for(int y2=y1;y2<=8;y2++)
        {
            for(int i=x1;i<x2;i++)
            {
                dp[k][x1][y1][x2][y2] = min(dp[k][x1][y1][x2][y2], min(dp[k-1][x1][y1][i][y2]+sf[i+1][y1][x2][y2], dp[k-1][i+1][y1][x2][y2]+sf[x1][y1][i][y2]) );
            }
            for(int i=y1;i<y2;i++)
            {
                dp[k][x1][y1][x2][y2] = min(dp[k][x1][y1][x2][y2], min(dp[k-1][x1][y1][x2][i]+sf[x1][i+1][x2][y2], dp[k-1][x1][i+1][x2][y2]+sf[x1][y1][x2][i]) );
            }
        }
    } 
    //debug(dp[n-1][1][1][8][8])
    printf("%.3f\n", sqrt((float)((float)dp[n-1][1][1][8][8]/(n*1.0)-1.0*Sqr(sum*1.0/(n*1.0)))) );
}

int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &n);
    for(int i=1;i<=8;i++)
    for(int j=1;j<=8;j++)
    scanf("%d", &matrix[i][j]);
    solve();
    system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

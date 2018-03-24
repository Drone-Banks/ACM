/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 110
#define MaxM 
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;

LL N,W;
LL w[MaxN], v[MaxN];
LL DP[MaxN][4*MaxN][MaxN];
void solve()
{
    LL W1 = w[1];
    for(int i=1;i<=N;i++) w[i] = w[i] - W1;
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<=300;j++)
        {
            for(int k=1;k<=N;k++)
            {
                if( j >= w[i] ) 
                    DP[i][j][k] = max( DP[i-1][j][k], DP[i-1][j-w[i]][k-1]+v[i]);
                else 
                    DP[i][j][k] = DP[i-1][j][k];
            }
        }
    }
    LL ans = 0;
    for(int j=0;j<=300;j++)
    {
        for(int k=0;k<=N;k++)
        {
            if( k*W1+j<=W)
            {
                ans = max(ans, DP[N][j][k]);
            }
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%lld%lld", &N, &W);
    for(int i=1;i<=N;i++) scanf("%lld%lld", &w[i], &v[i]);
    solve();
    system("pause");
}

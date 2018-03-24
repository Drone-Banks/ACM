#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define N 1000000
#define INF 0x7fffffff

int a[N+10];
int dp[N+10],Max[N+10];
// DP[j]表示一定取a[j]时，分成i组的最大值，Max[j]就表示前j个数分成i-1组时的最大值
int main()
{
    int T;
    scanf("%d", &T);
    int n,m,mmax;
    while (T--)
    {
        scanf("%d",&n);
        m = 2;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        memset(dp,0,sizeof(dp));
        memset(Max,0,sizeof(Max));
        for (int i=1;i<=m;i++)//分成几组
        {
            mmax=-INF;
            for (int j=i;j<=n;j++)//j个数分成i组，至少要有i个数
            {
                dp[j]=max(dp[j-1]+a[j],Max[j-1]+a[j]);
                Max[j-1]=mmax;//在使用完前j-1个数分成i-1段后更新为j-1个数分成i段的最大值
                mmax=max(mmax,dp[j]);
            }
        }
        printf ("%d\n",mmax);
    }
    return 0;
}

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
#define ll __int64
#define mem(a,t) memset(a,t,sizeof(a))
#define N 12

const int inf=0x3fffffff;
int g[N][N];
int dp[1<<11][N];//dp[state][i]表示在当前状态下，从起点0到达i点的最短距离
void floyd(int n)
{
    int i,j,k;
    for(k=0; k<=n; k++)   //Floyd求最短路
        for(i=0; i<=n; i++)
            for(j=0; j<=n; j++)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}
int main()
{
    //freopen("in.txt","r",stdin);
    int n,i,j,k,s;
    while(scanf("%d",&n),n)
    {
        for(i=0; i<=n; i++)
            for(j=0; j<=n; j++)
                scanf("%d",&g[i][j]);
        floyd(n);
        for(i=0;i<(1<<(n+1));i++)
            for(j=0;j<=n;j++)
            dp[i][j]=inf;
        dp[0][0]=0;
        for(s=0; s<(1<<(n+1)); s++) //枚举每一个状态
        {
            for(i=0; i<=n; i++)     //枚举中间点。看能否使距离变短
            {
                if(!(s&(1<<i)))
                    continue;
                for(k=0; k<=n; k++)
                    dp[s][i]=min(dp[s][i],dp[s^(1<<i)][k]+g[k][i]);
            }
        }
        printf("%d\n",dp[(1<<(n+1))-1][0]);
    }
    return 0;
}
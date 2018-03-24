/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 101
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;

int C,N;
int tower[MaxN][MaxN];
int dp[MaxN][MaxN]; //dp[i][j]表示以第i层第j个结束时的最大和

void solve()
{
    dp[0][1] = dp[0][0] = 0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=i;j++)
        {
            //bug;
            if(j == 1) dp[i][j] = dp[i-1][j] + tower[i][j];
            else if(j == i) dp[i][j] = dp[i-1][j-1] + tower[i][j];
            else
            {
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + tower[i][j];
            }
        }
    }
    int ans = dp[N][1];
    for(int i=2;i<=N;i++)
    {
        ans = max(ans, dp[N][i]);
    }
    cout << ans << endl;
}

int main()
{
    scanf("%d", &C);
    while(C--)
    {
        scanf("%d", &N);
        for(int i=1;i<=N;i++)
            for(int j=1;j<=i;j++)
                scanf("%d", &tower[i][j]);

        solve();
    }
    system("pause");
}
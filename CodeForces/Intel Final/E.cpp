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

#define MaxN 100000
#define MaxM MaxN*10
#define INF (LL)(1e18)
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

int n;
LL c;
LL P[MaxN];
LL S[MaxN];
LL dp[2][MaxN];

int main()
{
    while(~scanf("%d%d", &n, &c))
    {
        for(int i=1;i<=n;i++) scanf("%I64d", &P[i]);
        for(int i=1;i<=n;i++) scanf("%I64d", &S[i]);
        for(int i=0;i<=n;i++) dp[0][i] = INF;
        dp[0][0] = 0;
        int now = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=n;j++) dp[now^1][j] = INF;
            for(LL j=0;j<i;j++)
            {
                dp[now^1][j] = min(dp[now^1][j], dp[now][j]+P[i]+j*1ll*c);
                dp[now^1][j+1] = min(dp[now^1][j+1], dp[now][j]+S[i]);
            }
            now^=1;
        }
        LL ans = *min_element(dp[now], dp[now]+n+1);
        printf("%I64d\n",ans);

    }

    system("pause");
}

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

#define MaxN 3123
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;

int n;
int a[MaxN],b[MaxN];//a为原数组，b为将a数组离散化处理（即排序后重新存储）的数组

LL dp[MaxN][MaxN]; //dp[i][j]表示前i个数以j结尾的递增序列的最小操作数, j为a数组排序后的序号。
LL ans;
void solve()
{
    for(int i=1;i<=n;i++)
    {
        LL Min = dp[i-1][1];
        for(int j=1;j<=n;j++)
        {
            Min = min(Min, dp[i-1][j]);
            dp[i][j] = abs(a[i]-b[j]) + Min;
        }
    }
    ans = dp[n][1];
    for(int i=2;i<=n;i++)
        ans = min(ans, dp[n][i]);
}

int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
        a[i]-=i;
        b[i] = a[i];
    }
    sort(b+1, b+n+1);
    solve();
    cout<< ans << endl;
    //system("pause");
}
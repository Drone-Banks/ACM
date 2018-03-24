/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
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

int T,cas;
int n,m,cnt;
char str[110];
int loc[110];
int DP[110][110][110];
//DP[i][j][k]放置了i个2且最后一个2在j位置，总共构成k个233的最小花费
void solve()
{
    DP[cnt][n+1][0] = 0;
    for(int i=cnt;i>=1;i--)
    {
        for(int j=1;j<=n+1;j++)
        {
            for(int k=0;k<=n/3;k++)
            {
                if(DP[i][j][k]<=m)
                {
                    for(int l=j-1;l>=1;l--)
                    {
                        DP[i-1][l][k+(l+2<j)] = min(DP[i-1][l][k+(l+2<j)], DP[i][j][k]+abs(loc[i-1]-l));
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int j=1;j<=n+1;j++)
    {
        for(int k=0;k<=n/3;k++)
        {
            if(DP[1][j][k]<=m)
            ans = max(k, ans);
        }
    }
    printf("%d\n", ans);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        MST(DP,INF);
        m/=2;
        scanf("%s", str+1);
        cnt = 0;
        for(int i=1;i<=n;i++)
            if(str[i]=='2') loc[++cnt] = i;
        loc[++cnt] = n+1;
        if(cnt==0) 
        {
            puts("0");
            continue;
        }
        solve();
    }
}

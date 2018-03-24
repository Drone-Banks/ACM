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

#define MaxN 10000001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;

int n;
LL x,y;

LL dp[MaxN];
void Min(LL &x, LL y){x = min(x,y);}
int main()
{
    while(~scanf("%d%I64d%I64d",&n,&x,&y))
    {
        dp[1] = x;
        for(int i=2;i<=n;i++)
        {
            if(i&1)
                dp[i] = min(dp[i-1]+x, min(dp[i/2]+y+x, dp[i/2+1]+x+y));
            else 
                dp[i] = min(dp[i-1]+x, dp[i/2]+y);
        }
        cout << dp[n]<<endl;
    }
    //system("pause");
}
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
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;

int n;
LL dp[50];
LL ss[50];
void solve()
{
    dp[1] = 3;
    dp[2] = 8;
    ss[1] = 1;
    ss[2] = 2;
    for(int i=3;i<=40;i++)
    {
        dp[i] = dp[i-1]*3-ss[i-1];
        ss[i] = dp[i-1] - ss[i-1];
    }
}

int main()
{
    solve();
    while(~scanf("%d", &n))
    {
        cout << dp[n] << endl;
    }
    //system("pause");
}
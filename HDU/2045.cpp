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
LL dp[60];
LL ss[60];
void solve()
{
    dp[1] = 1;
    dp[2] = 2;
    ss[1] = ss[2] = 0;
    for(int i=3;i<=50;i++)
    {
        dp[i] = dp[i-1]*2;
        ss[i] = dp[i-1] - ss[i-1];
    }

}
int main()
{
    solve();
    while(~scanf("%d", &n))
    {
        cout << 3*(dp[n]-ss[n]) << endl;
    }
    //system("pause");
}
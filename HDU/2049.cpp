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

int n,m;
LL dp[30][30];
LL a[25];
void init()
{
    a[0] = a[1] = 0;
    a[2] = 1;
    a[3] = 2;
    for(int i=4;i<25;i++)
    {
        a[i] = (i-1)*(a[i-1]+a[i-2]);
    }
    for(int i=0;i<=20;i++)
    {
        for(int j=0;j<=i;j++)
         {
            if(!j || i==j)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                 //cout << i << "  " << j << ":  " << dp[i][j] << endl;
         }
    }
    return;
}

int main()
{
    init();
    int C;
    scanf("%d", &C);
    while(C--)
    {
        scanf("%d%d", &n, &m);
        cout << a[m] << endl;
        cout << dp[n][n-m]*a[m] << endl;
    }
    system("pause");
}
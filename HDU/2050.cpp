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

int C;
int N;
LL dp[11234];

void init()
{
    dp[1] = 2;
    for(int i=2;i<=10000;i++)
    {
        dp[i] = dp[i-1] + 4*(i-1) + 1;
    }
}

int main()
{
    init();
    scanf("%d", &C);
    while(C--){
        cin >> N;
        cout << dp[N] << endl;
    }
    //system("pause");
}
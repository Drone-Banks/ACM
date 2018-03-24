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

#define MaxN 1005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
#define bug cout<<88888888<<endl;

int n;
int Map[MaxN][MaxN];
int lab[MaxN][MaxN];
LL DP[MaxN][MaxN];

void solve()
{
    for(int i=1;i<=n;i++) lab[1][i] = lab[i][1] = 1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i>1 && j>1 && Map[i-1][j]+1==Map[i][j] && Map[i][j-1]+1==Map[i][j]) lab[i][j] = 1;
    int ans = 0;
    CLR(DP);
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=n;j++)
        {
            if(lab[i][j]) DP[i][j] = min(DP[i-1][j-1], min(DP[i-1][j], DP[i][j-1]))+1;
            if(DP[i][j]>ans) ans = DP[i][j];
        }
    }
    printf("%d\n", ans+1);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &n))
    { 
        CLR(lab);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d", &Map[i][j]);
        solve();
	} 
}
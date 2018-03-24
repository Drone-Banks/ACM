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
#define debug(x) cout << #x" = " << x << endl;
int T,n,x;
double p;
double DP[MaxN];
void solve(int t)
{ 
    for(int i=1;i<=n;i++)
    {
        DP[i] = (DP[i-1]+1)/(1-p);
    }
    double ans = INF;
    for(int i=1;i<=n;i++)
    {
        int cnt = n%i;
        ans = min(ans, DP[n/i+1]*cnt+DP[n/i]*(i-cnt)+i*x); 
    }
    printf("Case #%d: %.6lf\n", t, ans);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%lf%d", &n, &p, &x);
        solve(t);
    }
    //system("pause");
}
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

#define MaxN 10001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
int A,B,F; 
int digits[10];
int DP[10][MaxN];
int dfs(int pos, int sum, bool limit)
{
    if(pos==0) return sum>=0;
    if(sum<0) return 0;
    if(!limit&&DP[pos][sum]!=-1) return DP[pos][sum];
    int Max = limit ? digits[pos] : 9;
    int ans = 0;
    for(int i=0;i<=Max;i++)
    {
        ans += dfs(pos-1, sum-i*(1<<(pos-1)), limit&&i==digits[pos]);
    }
    if(!limit) DP[pos][sum] = ans;
    return ans;
}
int find()
{
    F = 0;
    int cnt = 1;
    while(A)
    {
        F+=(A%10)*cnt;
        A/=10;
        cnt<<=1;
    }
    int pos = 0;
    while(B)
    {
        digits[++pos] = B%10;
        B/=10;
    }
    return dfs(pos,F,true);
}

void solve(int t)
{
    printf("Case #%d: %d\n", t, find());
}

int main()
{
    //std::ios::sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    MST(DP,-1);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d", &A, &B);
        solve(t);
    }
    //system("pause");
}

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
int L,R;
int digits[10];
int DP[10][10][2][2];

int dfs(int pos, int num, bool no62, bool no4, bool limit)
{
    if(pos==0) return no62&&no4;
    if(!limit && DP[pos][num][no62][no4]!=-1) return DP[pos][num][no62][no4];
    int Max = limit ? digits[pos] : 9;
    int ans = 0;
    for(int i=0;i<=Max;i++)
    {
        ans += dfs(pos-1, i, no62&&(num*10+i)!=62, no4&&i!=4, limit&&i==digits[pos]);
    }
    if(!limit) DP[pos][num][no62][no4] = ans;
    return ans;
}

int find(int x)
{
    int pos = 0;
    while(x)
    {
        digits[++pos] = x%10;
        x/=10;
    }
    return dfs(pos,0,true,true,true);
}

void solve()
{
    printf("%d\n", find(R)-find(L-1));
}
int main()
{
    //std::ios::sync_with_stdio(false);
    MST(DP,-1);
    while(~scanf("%d%d", &L, &R)&&(L+R))
    {
        solve();
    }
    //system("pause");
}

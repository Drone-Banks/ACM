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
LL L,R;
int digits[100];
LL DP[100][2][100][100];

LL dfs(int pos, int num, int one, int zero, bool qz, bool limit)
{
    if(pos==0) return one<=zero;
    if(!limit && DP[pos][num][one][zero]!=-1) return DP[pos][num][one][zero];
    int Max = limit ? digits[pos] : 1;
    LL ans = 0;
    for(int i=0;i<=Max;i++) 
    {
        if(qz) ans+=dfs(pos-1, i, (i==1), 0, qz&&i==0, limit&&i==digits[pos]);
        else ans += dfs(pos-1, i, one+(i==1), zero+(i==0), false, limit&&i==digits[pos] );
    }
    if(!limit) DP[pos][num][one][zero] = ans;
    return ans;
}

LL find(LL x)
{
    int pos = 0;
    while(x)
    {
        digits[++pos] = x&1;
        x>>=1;
    }
    return dfs(pos, 0, 0, 0,true, true);
}
void solve()
{
    printf("%lld\n", find(R)-find(L-1));
}
int main()
{
    //std::ios::sync_with_stdio(false);
    MST(DP,-1);
    while(~scanf("%lld%lld", &L, &R))
    {
        solve();
    }
    //system("pause");
}

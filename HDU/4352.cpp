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
int T,K;
LL L,R;
int digits[20];
LL DP[20][1<<10][11];
int Next[1<<10][10];
int LIS[1<<10];

LL dfs(int pos, int stat, bool zero, bool limit)
{
    if(pos==0)
    {
        if(LIS[stat] == K) return 1;
        else return 0;
    }
    if( !limit && DP[pos][stat][K] !=-1) return DP[pos][stat][K];
    int Max = limit ? digits[pos] : 9;
    LL ans = 0;
    for(int i=0;i<=Max;i++)
    {
        ans += dfs(pos-1, (zero&&i==0) ? 0 :Next[stat][i], zero&&i==0, limit&&Max==i);
    }
    if(!limit) DP[pos][stat][K] = ans;
    return ans;
}

LL find(LL x)
{
    int pos = 0;
    while(x)
    {
        digits[++pos] = x%10;
        x/=10;
    }
    return dfs(pos,0,true,true);
}
void solve(int t)
{
    printf("Case #%d: %lld\n",t, find(R)-find(L-1));
}

int find_next(int stat, int x)
{
    for(int i=x;i<10;i++)
    {
        if( stat & (1<<i) ) return ( stat^(1<<i) | (1<<x) );
    }
    return stat|(1<<x) ;
}

void init()
{
    for(int i=0;i<(1<<10);i++)
    {
        LIS[i] = 0;
        for(int j=0;j<10;j++)
        {
            if( i & (1<<j))  LIS[i]++;
            Next[i][j] = find_next(i,j);
        }
    }
}

int main()
{
    //std::ios::sync_with_stdio(false);
    MST(DP,-1);
    scanf("%d", &T);
    init();
    for(int i=1;i<=T;i++)
    {
        scanf("%lld%lld%d", &L, &R, &K);
        solve(i);
    }
    //system("pause");
}

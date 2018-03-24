/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <iomanip>
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
template<typename T> T abs(T val){return val>0?val:-val;}

int N,M;
LL DP[2][1<<13]; // DP[i][s]表示第i行的状态，0表示这一格未占据，1表示这一格被占据
vector<int> stat[2];
void dfs(int col, int s1, int s2)
{
    if(col==M)
    {
        stat[0].push_back(s1);
        stat[1].push_back(s2);
        return;
    }
    dfs(col+1, s1<<1|1, s2<<1);  //竖放，必要条件是s2未被占
    dfs(col+1, s1<<1, s2<<1|1);  //不放，必要条件是s2已被占
    if(col<M-1) dfs(col+2, s1<<2|3, s2<<2|3);  //横放，必要条件是s2的两格已被占
}
void init()
{
    CLR(DP);
    DP[0][(1<<M)-1] = 1;
    for(int i=0;i<2;i++) stat[i].clear();
    dfs(0,0,0); 
}
void solve()
{
    init();
    bool flag = false;
    for(int i=1;i<=N;i++)
    {
        flag^=1;
        for(int j=0;j<stat[0].size();j++)
        {
            DP[flag][stat[0][j]] += DP[flag^1][stat[1][j]];
        }
        CLR(DP[flag^1]);
    }
    printf("%lld\n", DP[flag][(1<<M)-1]);
}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &N, &M) && (N+M))
    {
        if((N*M) & 1) 
        {
            puts("0");
            continue;
        }
        else solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

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
LL DP[15][1<<13],stat[150],cnt; // DP[i][s]表示第i行的状态，0表示这一格被横条占据，1表示这一格被竖条占据
bool check(int s) //因为只有1*2的条，所以0肯定是两个两个的出现，其他情况都是非法的
{
    int x = 0;
    while(x<M)
    {
        if(s & (1<<x)) x++;
        else
        {
            if( s & (1<<(x+1))) return 0;  //出现了单个的0，非法
            if( x == M-1) return 0;  //出现了单个的0，非法
            x += 2;
        }
    }
    return 1;
}
void init()
{
    for(int s=0;s<(1<<M);s++)  //先检查出可能的合法状态
    {
        if(check(s)) stat[cnt++] = s;
    }
}
void solve()
{
    CLR(DP);    
    cnt = 0;
    init();
    //debug(cnt)
    for(int i=0;i<cnt;i++) DP[0][stat[i]] = 1;
    for(int i=1;i<N;i++)
    {
        for(int j=0;j<cnt;j++)
        {
            for(int now=0;now<(1<<M);now++)
            {
                if( (now & stat[j]) != now) continue;  //判断当前状态now能否由上一个状态stat转换过来，即当前有1的地方上一个状态肯定有
                else DP[i][now^stat[j]] += DP[i-1][now]; //now^stat为填充1之后的状态
            }
        }
    }
    printf("%lld\n", DP[N-1][0]);
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

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
#include <fstream>
#include <iomanip>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 2005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
#define bug cout<<88888888<<endl;
int T,N,M;
double ans;
LL DP[MaxN*2][MaxN]; // len = i, N = j
LL dp[MaxN*2][MaxN];
//sum =  C (n+m) (n);
//DP[i][x] = DP[i-1][x-1];
void init()
{
    for(int i=0;i<=32;i++)
        for(int j=0;j<=i;j++)
         {
            if(!j || i==j)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];

         }
    return;
}

void solve()
{
    CLR(DP);
    DP[0][0] = 1;
    int len = N+M;
    for(int i=1;i<=len;i++)
    {
        for(int j=i/2+1;j<=min(N,i);j++)
        {
            DP[i][j] = DP[i-1][j] + DP[i-1][j-1];
        }
    }
	cout << DP[len][N] << endl;
    ans = DP[len][N]*1.0/dp[M+N][N]*1.0;
}
int main()
{
    std::ios::sync_with_stdio(false);
    //freopen("B-small-attempt1.in","r",stdin);
	//freopen("B.out","w",stdout);
	/********************************************/
    init();
    cin >> T;
    for(int t=1;t<=T;t++)
    {
        cin >> N >> M;
        //正解
        cout << "Case #" << t << ": " << fixed << setprecision(8) << (N-M)/(N+M) << endl;
        //之前的做法
        if(N<=M) cout << "Case #" << t << ": " << fixed << setprecision(8) << 0.0 << endl; 
        else if(N>0 &&M==0) cout << "Case #" << t << ": " << fixed << setprecision(8) << 1.0 << endl; 
        else
        {
            solve();
            cout << "Case #" << t << ": " << fixed << setprecision(8) << ans << endl; 
        }
    }
    /********************************************/
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

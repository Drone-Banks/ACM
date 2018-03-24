/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
#define ALL(a) a.begin(), a.end()
using namespace std;

#define MaxN 1000010
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
inline int max2(int a, int b) {return ((a > b)? a : b);}
inline int min2(int a, int b) {return ((a < b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}
inline int min3(int a, int b, int c) {return min2(a, min2(b, c));}
int n,A[MaxN];
int dp[5][MaxN];
void cal()
{
    stack<int> S;

    dp[0][1] = 1;
    S.push(1);
    for(int i=2;i<=n;i++)
    {
        while( S.size()>=1 && A[i]>=A[S.top()])
        {
            S.pop();
        }
        if(S.size()) dp[0][i] = S.top()+1;
        else dp[0][i] = 1;
        S.push(i);
    }
    while(S.size()) S.pop();

    dp[1][n] = n;
    S.push(n);
    for(int i=n-1;i>=1;i--)
    {
        while( S.size()>=1 && A[i]>A[S.top()])
        {
            S.pop();
        }
        if(S.size()) dp[1][i] = S.top()-1;
        else dp[1][i] = n;
        S.push(i);
    }
    while(S.size()) S.pop();

    dp[2][1] = 1;
    S.push(1);
    for(int i=2;i<=n;i++)
    {
        while( S.size()>=1 && A[i]<A[S.top()])
        {
            S.pop();
        }
        if(S.size()) dp[2][i] = S.top()+1;
        else dp[2][i] = 1;
        S.push(i);
    }
    while(S.size()) S.pop();

    dp[3][n] = n;
    S.push(n);
    for(int i=n-1;i>=1;i--)
    {
        while( S.size()>=1 && A[i]<=A[S.top()])
        {
            S.pop();
        }
        if(S.size()) dp[3][i] = S.top()-1;
        else dp[3][i] = n;
        S.push(i);
    }
    while(S.size()) S.pop();
}
void solve()
{
    cal();
    LL ans = 0;
    for(int i=1;i<=n;i++)
    {
        ans += (LL)(i+1-dp[0][i])*(dp[1][i]+1-i)*A[i];
        ans -= (LL)(i+1-dp[2][i])*(dp[3][i]+1-i)*A[i];
        //debug(dp[0][i]) debug(dp[1][i]) debug(dp[2][i]) debug(dp[3][i])

    }
    printf("%lld\n", ans);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &n))
    {
        CLR(dp);
        for(int i=1;i<=n;i++) scanf("%d", &A[i]);
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

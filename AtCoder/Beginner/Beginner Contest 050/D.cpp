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
using namespace std;

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
LL N; 
map<LL,LL> DP; 
LL dp(LL x)
{
    if(DP[x]) return DP[x];
    else
    {
        return DP[x] = ( dp(x/2) + dp((x-1)/2) + dp((x-2)/2) )%mod;
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    DP[0] = 1;
    DP[1] = 2;
    cin >> N;
    cout << dp(N) << endl;
    system("pause");
}

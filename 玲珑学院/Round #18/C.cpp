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

#define MaxN 100001
#define MaxM MaxN*30
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

int T,n;
LL a,x[MaxN];
LL dp[MaxN];   //存储起点到每一个点的最短路
LL calc(int len, int a){
	if(len > 62) return -1;
	return (1ll<<len)+a;
}
void solve()
{
    for(int i=1;i<=n;i++) dp[i] = INF;
    dp[1] = 0;
    for(int i=2;i<=n;i++)
    {
        dp[i] = dp[i-1] + calc(x[i]-x[i-1], a);
        for(int j=i;j>0 && j>=i-60;j--)
        {
            LL cc = calc(x[i]-x[j],a);
            if(cc == -1)break;
            if(1.0*cc + 1.0*dp[j] < 1.0*dp[i]){
                dp[i] = cc + dp[j];
            }
        }
    }
    printf("%lld\n", dp[n]);
}

int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%lld", &n, &a);
        for(int i=1;i<=n;i++) scanf("%lld", &x[i]);
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

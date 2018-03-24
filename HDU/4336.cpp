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
int N;
double p[22],p0;

double dp[(1<<20)+10];

void solve()
{
    p0 = 1 - p0;
    //debug(p0)
    dp[(1<<N)-1] = 0;
    for(int s = (1<<N)-2;s>=0;s--)
    {
        double pp = 0;
        dp[s] = 1;
        for(int j=0;j<N;j++)
        {
            if( (s & (1<<j)) == 0 )
            {
                dp[s] += dp[s|(1<<j)]*p[j+1];
            }
            else pp+=p[j+1];
        }
        //debug(pp)
        double fenmu = 1-p0-pp;
        //debug(fenmu)
        dp[s] /= (fenmu);
    }
    printf("%f\n", dp[0]);
}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &N))
    {
        p0 = 0;
        CLR(dp);
        for(int i=1;i<=N;i++) scanf("%lf", &p[i]), p0+=p[i];
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x+mod)%mod );
}

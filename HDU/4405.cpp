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

#define MaxN 100010
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

int N,M,flight[MaxN];
double DP[MaxN];

void solve()
{
    DP[N] = 0;
    for(int i=N-1;i>=0;i--)
    {
        if(flight[i]) 
        {
            DP[i] = DP[flight[i]];
            continue;
        }
        DP[i] = 1;
        double tmp = 0;
        for(int j=1;i+j<=N && j<=6;j++)
        {
            tmp += DP[i+j];
        }
        DP[i] += tmp/6.0;
    }
    printf("%.4f\n", DP[0]);
}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &N, &M) && (N+M))
    {
        CLR(flight), CLR(DP);
        int x,y;
        while(M--)
        {
            scanf("%d%d", &x, &y);
            flight[x] = y;
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x+mod)%mod );
}

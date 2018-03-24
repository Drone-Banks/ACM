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
template<typename T> T abs(T val){return val>0?val:-val;}
int T;
int N, M;
int A[20];
LL ans;
LL lcm(LL a, LL b)
{
    LL x = __gcd(a,b);
    return a/x*b;
}
void LCM(int loc, int dep, LL last)
{
    if(dep&1) ans += (1<<(dep-1))*(N/last);
    else ans -= (1<<(dep-1))*(N/last);
    for(int i=loc+1;i<=M;i++)
    {
        LCM(i, dep+1, lcm(last, A[i]));
    }
}

void solve()
{
    ans = 0;
    for(int i=1;i<=M;i++)    
    {
        LCM(i,1,A[i]);
    }
    printf("%lld\n", ans);
}

int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &N, &M);
        for(int i=1;i<=M;i++) scanf("%d", &A[i]);
        solve();
    }
    //system("pause"A);
}

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

LL m,b;
LL cal(LL x, LL y)
{
    LL tmp = 0;
    for(LL i=0;i<=y;i++)
    {
        tmp += ( (x+i+i)*(x+1)/2 );
    }
    //cout << x << "," << y << ": " << tmp << endl;
    return tmp;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%lld%lld", &m, &b);
    LL x = m*b;
    LL y = b;
    LL detx = m, dety = 1;
    LL sx = 0, sy = b;
    LL ans = 0;
    while(sx<=x)
    {
        ans = max(ans, cal(sx,sy));
        sx+=detx;
        sy-=dety;
    }
    printf("%lld\n", ans);
    system("pause");
}

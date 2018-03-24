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

LL n,s;
bool check(LL x)
{
    LL tmp = x,cnt=0;
    while(x)
    {
        cnt += x%10;
        x/=10;
    }
    if(tmp-cnt>=s) return true;
    else return false;
}
void solve()
{
    LL L = 0, R = n;
    LL ans = R+1;
    while(L<=R)
    {
        LL mid = (L+R)>>1;
        if(check(mid))
        {
            ans = min(mid,ans);
            //debug(mid) 
            R = mid-1;
        }
        else L = mid+1;
    }
    printf("%lld\n", n-ans+1);
}
int main()
{
    while(~scanf("%lld%lld", &n,&s))
    solve();
    //system("pause");
}
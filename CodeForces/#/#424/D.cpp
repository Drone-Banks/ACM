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
inline int max2(int a, int b) {
	return ((a > b)? a : b);
}
inline int min2(int a, int b) {
	return ((a < b)? a : b);
}
inline int max3(int a, int b, int c) {
	return max2(a, max2(b, c));
}
inline int min3(int a, int b, int c) {
	return min2(a, min2(b, c));
}
LL a,b,c,A[MaxN],B[MaxN];
bool check(LL x)
{
    //debug(x) 
    bool flag = false;
    int i=1,j=1;
    while(j<=b)
    {
        if(i>a) break;
        if( abs(A[i]-B[j])+abs(B[j]-c) <= x) i++,j++;
        else j++; 
    }
    if(i>a) flag = true;
    return flag;
}
void solve()
{
    sort(A+1,A+1+a);
    sort(B+1,B+1+b);
    LL l=0, r = 4E12;
    LL ans = r;
    while(l<=r)
    {
        LL mid = (l+r)>>1;
        if(check(mid))
        {
            ans = min(ans,mid);
            r = mid-1;
        }
        else l = mid+1;
    }
    printf("%lld\n", ans);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%lld%lld%lld",&a,&b,&c))
    {
        for(int i=1;i<=a;i++) scanf("%lld", A+i);
        for(int i=1;i<=b;i++) scanf("%lld", B+i);
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}
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

#define MaxN 2010
#define MaxM MaxN*MaxN
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
int a,b,A[MaxN],B[MaxN],sum[MaxN];
void solve()
{
    sum[0] = 0;
    for(int i=1;i<=a;i++) sum[i] = sum[i-1] + A[i];
    sort(sum+1,sum+1+a);
    int n = unique(sum+1,sum+1+a)-(sum+1); 
    int ans = n;
    for(int i=1;i<=n;i++)
    {
        int ori = B[1] - sum[i];
        for(int j=1;j<=b;j++) if(!binary_search(sum+1,sum+1+n,  B[j]-ori))
        {
            ans--;
            break;
        }
    }
    printf("%d\n", ans);    
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &a, &b))
    {
        for(int i=1;i<=a;i++) scanf("%d", &A[i]);
        for(int i=1;i<=b;i++) scanf("%d", &B[i]);
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

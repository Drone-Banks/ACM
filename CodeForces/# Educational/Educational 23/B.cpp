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
int n,A[MaxN];

void solve()
{
    int num1,num2,num3;
    num1 = num2 = num3 = 0;
    for(int i=1;i<=n;i++)
    {
        if(A[i] == A[1]) num1++;
        if(A[i] == A[2]) num2++;
        if(A[i] == A[3]) num3++;
    }
    LL ans;
    if(A[1]==A[2] && A[1] == A[3]) 
    {
        ans = (LL)num1*(num1-1)*(num1-2)/6LL;
    }
    else if( A[1]==A[2] && A[2]!=A[3])
    {
        ans = (LL)num1*(num1-1)/2LL*num3;
    }
    else if( A[1]!=A[2] && A[2]==A[3])
    {
        ans = (LL)num2*(num2-1)/2LL*num1;
    }
    else if (A[1]!=A[2] && A[2]!=A[3])
    {
        ans = (LL)num1*num2*num3;
    }
    printf("%lld\n", ans);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &n))
    {
        for(int i=1;i<=n;i++) scanf("%d", A+i);
        sort(A+1,A+1+n);
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

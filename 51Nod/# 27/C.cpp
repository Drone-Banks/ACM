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
#define mp make_pair
#define pb push_back
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

int T,k;
LL n;
LL tmp;
bool check(LL x)
{
    LL rt = sqrt(x);
    while( Sqr(rt) < x)
    {
        rt++;
    }
    tmp = rt-1;
    if(Sqr(rt)==x) 
        return true;
    else 
        return false;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld%d", &n, &k);
        if(k==1)
        {
            if(n==4) puts("3");
            else if(n==3||n==2) puts("2");
            else if(n==1||n==0) printf("%d\n", n);
            else 
            {
                LL ans = 0;
                if( check(n) )
                {
                    ans += 1;
                }
                ans += 2*tmp;
                printf("%lld\n", ans);
            }
        }
        else
        {   
            if(n==5) puts("3");
            else if(n==4 ) puts("2");
            else if(n==2) puts("1");
            else if(n==1||n==3) puts("-1");
            else if(n==0) puts("0"); 
            else 
            {
                LL ans = -1;
                if( check(n) || check(n-1) )
                {
                    ans += 1;
                }
                //debug(ans)
                ans += 2*tmp;
                printf("%lld\n", ans);
            }
        }
    }
    //system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

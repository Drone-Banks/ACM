/*************************************************************************
> File Name: test.cpp
> Author: Akira 
> Mail: qaq.febr2.qaq@gmail.com 
************************************************************************/

//#pragma comment(linker, "/STACK:102400000,102400000")
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

#define MaxN 100005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}

LL a,b,f,k;

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%lld%lld%lld%lld", &a, &b, &f, &k))    
    {
        if(b>=k*a) puts("0");
        else if( ( k>=1 && (b<f||b<(a-f)) ) || ( k >=2 && b<2*(a-f) ) ||  ( k >=3 && b<2*f )  ) puts("-1");
        else
        {
            LL x = b, dis = f;
            x -= f;
            bool flag = true;
            int cnt = 0;
            while(true)
            {
                if(flag) 
                {
                    if(x < min(2*(a-f), k*a-dis)) cnt++, x = b;
                    x -= 2*(a-f);dis += 2*(a-f);
                }
                else
                {
                    if( x < min(2*f, k*a-dis) ) cnt++, x = b;
                    x -= 2*f;dis += 2*f;
                }
                flag ^= 1;
                // debug(x)
                if(dis>=k*a) break;
            }
            printf("%d\n", cnt);
        }
    }
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

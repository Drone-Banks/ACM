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

#define MaxN 10000005
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
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}

int mu[MaxN],prime[MaxN],g[MaxN],sum[MaxN];
bool not_prime[MaxN];

void Mobius()
{
    int tot = 0;
    mu[1] = 1;
    for(int i=2;i<=1E7;i++)
    {
        if(!not_prime[i])
        {
            prime[++tot] = i;
            mu[i] = -1;
            g[i] = 1;
        }
        for(int j=1;prime[j]*i<=1E7;j++)
        {
            not_prime[prime[j]*i] = 1;
            if(i%prime[j]==0)
            {
                mu[prime[j]*i] = 0;
                g[i*prime[j]] = mu[i];
                break;
            }
            mu[prime[j]*i] = -mu[i];
            g[prime[j]*i] = mu[i] - g[i];
        }
    }
    sum[0] = 0;
    for(int i=1;i<=1E7;i++) sum[i] = sum[i-1] + g[i];
}

LL cal(int n, int m)
{
    LL ans = 0;
    if(n>m) swap(n,m);
    for(int t=1,last=1;t<=n;t=last+1)
    {
        last = min(n/(n/t), m/(m/t));
        ans += 1LL*(sum[last]-sum[t-1])*(n/t)*(m/t);
    }
    return ans;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    Mobius();
    int t, a, b;
    read(t);
    while(t--)
    {
        read(a);read(b);
        printf("%lld\n", cal(a,b));
    }
    //system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

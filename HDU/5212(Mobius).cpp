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

#define MaxN 10005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 10007;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
inline int max2(int a, int b) {return ((a > b)? a : b);}
inline int min2(int a, int b) {return ((a < b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}
inline int min3(int a, int b, int c) {return min2(a, min2(b, c));}

int mu[MaxN],prime[MaxN];
bool not_prime[MaxN];
void Mobius()
{
    int tot = 0;
    mu[1] = 1;
    for(int i=2;i<=MaxN;i++)
    {
        if(!not_prime[i])
        {
            prime[++tot] = i;
            mu[i] = -1;
        }
        for(int j=1;prime[j]*i<=MaxN;j++)
        {
            not_prime[prime[j]*i] = 1;
            if(i%prime[j]==0)
            {           
                mu[prime[j]*i] = 0;
                break;
            }
            mu[prime[j]*i] = -mu[i];
        }
    }
}

int a[MaxN],cnt[MaxN],F[MaxN];
int main()
{
    //std::ios::sync_with_stdio(false);
    Mobius();
    int n;
    while(~scanf("%d", &n))
    {
        CLR(cnt);CLR(F);
        
        int limit = 0;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d", a+i); 
            cnt[a[i]]++;
            limit = max(limit, a[i]);
        }
        for(int i=1;i<=limit;i++) for(int j=i;j<=limit;j+=i) F[i] += cnt[j];
        LL ans = 0;
        for(int i=1;i<=limit;i++)
        {
            LL tmp = 0;
            for(int j=i;j<=limit;j+=i)
            {
                tmp += 1LL*mu[j/i]*F[j]*F[j];
            }
            ans = ans + ((1LL*tmp*(i)%mod)*(i-1)%mod)%mod;
        }
        printf("%lld\n", ans%mod);
    }
}

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

#define MaxN 100005
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

int mu[MaxN],prime[MaxN];
LL K;
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

LL find(LL x)
{
    LL ans = 0;
    for(LL i=1;i*i<=(x);i++)
    {
        ans += mu[i]*(x/Sqr(i));
    }
    return ans;
}

int main()
{
    //std::ios::sync_with_stdio(false);
    Mobius();
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld", &K);
        LL L = 1, R = 2E9+5, ans;
        while(L<=R)
        {
            LL mid = (L+R)>>1;
            LL tmp = find(mid);
            if(tmp<K) L = mid+1;
            else  ans = mid,R = mid-1;
        }
        printf("%lld\n", ans);
    }
    //system("pause")
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

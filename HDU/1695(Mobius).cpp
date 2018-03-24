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

int mu[MaxN],prime[MaxN],sum[MaxN];
int a,b,c,d,k;
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
    sum[0] = 0;
    for(int i=1;i<MaxN;i++) sum[i] = sum[i-1]+mu[i];
}

LL find(int n, int m, int k)
{
    if(n>m) swap(n,m);
    n/=k, m/=k;         
    LL ans = 0;
    for(int i=1,last=1;i<=n;i=last+1)
    {
        last = min( n/(n/i), m/(m/i));
        ans += 1LL*(sum[last]-sum[i-1])*(n/i)*(m/i);
    }
    return ans;
}

int main()
{
    //std::ios::sync_with_stdio(false);
    Mobius();
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++) 
    {
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        if(b>d) swap(b,d);
        if(k==0) printf("Case %d: 0\n", t);
        else
        {
            LL ans = find(b,d,k)-find(b,b,k)/2;
            printf("Case %d: %lld\n",t, ans);
        }
    }
    //system("pause")
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

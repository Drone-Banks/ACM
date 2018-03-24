/*************************************************************************
> File Name: test.cpp
> Author: Akira 
> Mail: qaq.febr2.qaq@gmail.com 
************************************************************************/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
#include <climits>
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
#define MaxM 1E7
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

int mu[MaxN],prime[MaxN],sum[MaxN];
bool not_prime[MaxN];
int p,q;
void Mobius()
{
    int tot = 0;
    mu[1] = 1;
    for(int i=2;i<=MaxM;i++)
    {
        if(!not_prime[i])
        {
            prime[++tot] = i;
            mu[i] = -1;
        }
        for(int j=1;prime[j]*i<=MaxM;j++)
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
    //deal with factor
    vector<int> fac;
    for(int i=1;i*i<=p;i++)
    {
        if(p%i==0)
        {
            fac.pb(i);
            if(i!=p/i) fac.pb(p/i);
        }
    }
    for(int i=0;i<fac.size();i++)
    {
        int k = fac[i];
        for(int d=1;d*k<=MaxM;d++)
        {
            sum[d*k]+=mu[d];
        }
    }
    for(int i=1;i<=MaxM;i++) sum[i] += sum[i-1];
}

LL find(int n, int m)
{
    if(n>m) swap(n,m);
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
    scanf("%d%d", &p, &q);
    Mobius();
    int a,b;
    while(q--)
    {
        scanf("%d%d" , &a , &b);
        printf("%lld %lld\n", find(a,b), (LL)(a/p)*(b/p));
    }
}
 
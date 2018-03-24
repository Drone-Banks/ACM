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

#define MaxN 1000001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
int n,m;
ULL e = 1;
ULL BASE = 1234577;
ULL Hash[MaxN];
LL fac[MaxN];
void init()
{
    fac[0] = fac[1] = 1;
    for(int i=2;i<=1000000;i++) fac[i] = fac[i-1] *i %mod;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    init();
    while(~scanf("%d%d", &n, &m))
    {
        CLR(Hash);
        int x,y;
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &x);
            unordered_map<int,ULL> M;
            while(x--)
            {
                scanf("%d", &y);
                M[y]++;
            }
            for(auto &kv : M)
            {
                Hash[kv.first] += kv.second*e;
            }
            e*=BASE;
        }
        unordered_map<ULL,int> M;
        for(int i=1;i<=m;i++)
        {
            M[Hash[i]]++;
        }
        LL ans = 1;
        for(auto kv : M)
        {
            ans = ans * fac[kv.second] % mod;
        }
        printf("%lld\n", ans);
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

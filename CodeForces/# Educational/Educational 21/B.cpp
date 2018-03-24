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
#define ps push_back
using namespace std;

#define MaxN 200010
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

int n,k,a[MaxN];

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &k))
    {
        for(int i=1;i<=n;i++) scanf("%d", &a[i]);
        
        LL ans = 0;
        LL tmp = 0;
        int i=1, j=1;
        while(true)
        {
            if( j-i+1 <= k && j<=n ) 
            {
                tmp+=a[j];
                j++;
               
            }
            else 
            {
                tmp -= a[i];
                i++;
            }
             if(j-i==k) ans += tmp;
            if(i>n && j>n) break;
            
            // debug(i) debug(j)
            // debug(tmp)
            // debug(ans)
            
        }
        printf("%.10f\n", ans*1.0/(1.0*(n-k+1)));
    }
    //system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

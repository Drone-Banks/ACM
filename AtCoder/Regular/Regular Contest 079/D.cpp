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

LL K;
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%lld",&K))
    {
        if(K==0)
        {
            puts("4");
            printf("3 3 3 3\n");
        }
        else if(K==1)
        {
            puts("3");
            printf("1 0 3\n");
        }
        else if( K <= 50)
        {
            printf("%lld\n", K);
            for(int i=1;i<=K;i++)
            {
                printf("%lld%c", i, i==K?'\n':' ');
            }
        }
        else
        {   
            LL base = K/50;
            LL res = K%50;
            puts("50");
            for(int i=1;i<=50;i++)
            {
                printf("%lld%c", base+(i-1)+((50-i)<res?1:0), i==50?'\n':' ');
            }
        }
        
    }
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

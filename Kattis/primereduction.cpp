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

int cnt = 0;
int prime_factor(int n)
{
    cnt++;
    int sum = 0;
    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            sum += i;
            n/=i;
        }
    }
    if(n!=1) sum+=n;
    return sum;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    int x;
    while(~scanf("%d", &x) && x!=4)
    {
        cnt = 0;
        int pre, tmp=x;
        do
        {
            pre = tmp;
            tmp = prime_factor(pre);
        }while(tmp!=pre);
        printf("%d %d\n", tmp, cnt);
        
    }
    //system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

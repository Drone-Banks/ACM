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
#define Tqr(a) ((a)*(a)*(a))
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
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}
const int MAXN = 1E6+10;
int primes[MAXN],tot=0;
bool isPrime[MAXN];
void getPrime()
{
    memset(isPrime,true,sizeof(isPrime));
    for(int i=2;i<MAXN;i++)
    {
        if(isPrime[i])
            primes[++tot]=i;
        for(int j=1;j<=tot;j++)
        {
            if(i*primes[j]>=MAXN) break;
            isPrime[i*primes[j]]=false;
            if(i%primes[j]==0) break;
        }
    }
}
vector<int> ans;
void init()
{
    getPrime();
    LL i = 1;
    int tmp = int(Tqr(i+1)-Tqr(i));
    while( tmp <= 1E6)
    {
        if(isPrime[tmp])
        {
            ans.push_back(tmp);
        }
        i++;
        tmp = Tqr(i+1)-Tqr(i);
    }
}
int main()
{
    init();
    int L;
    while(~scanf("%d", &L))
    {
        int loc = upper_bound(ans.begin(), ans.end(), L) - ans.begin();
        if(loc==0) puts("No Special Prime!");
        else printf("%d\n", loc);
    }
}

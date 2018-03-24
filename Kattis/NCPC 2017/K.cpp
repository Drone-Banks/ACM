/*************************************************************************
> File Name: test.cpp
> Author: Akira 
> Mail: qaq.febr2.qaq@gmail.com 
************************************************************************/

//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define pb emplace_back
using namespace std;                                                                                              

#define MaxN 50005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}

int b,n,e,sb,sn,se, tot;
int c[MaxN];

bool check(int limit){
    int S = b, N = n, E = e;
    for(int i=1;i<=tot;i++)
    {
        if(  S>1 && c[i]*2*sb >= limit )
            S-=2;
        else if( S && N && c[i]*(sb+sn) >= limit)
            S--, N--;
        else if( N>1 && c[i]*2*sn >= limit)
            N-=2;
        else if( S && E && c[i]*(sb+se) >= limit)
            S--, E--;
        else if( N && E && c[i]*(sn+se) >= limit)
            N--, E--;
        else if(E>1 && c[i]*2*se >= limit)
            E-=2;
        else break;
    }
    S = b, N = n, E = e;
    for(int i=1;i<=tot;i++)
    {
        if(  S>1 && c[i]*2*sb >= limit )
            S-=2;
        else if( S && N && c[i]*(sb+sn) >= limit)
            S--, N--;
        else if( S && E && c[i]*(sb+se) >= limit)
            S--, E--;
        else if( N>1 && c[i]*2*sn >= limit)
            N-=2;
        else if( N && E && c[i]*(sn+se) >= limit)
            N--, E--;
        else if(E>1 && c[i]*2*se >= limit)
            E-=2;
        else return false;
    }
    return true;
}
void solve()
{
    sort(c+1,c+1+tot);
    int L = 0, R = 200000000,ans=0;
    while(L<=R)
    {
        int mid = (L+R)>>1;
        if(check(mid))
            L = mid+1, ans = mid;
        else 
            R = mid-1;
    }
    printf("%d\n", ans);
}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d%d%d%d%d", &b, &n, &e, &sb, &sn, &se))
    {
        tot = (b + n + e)/2;
        for(int i=1;i<=tot;i++) scanf("%d", &c[i]);
        solve();
    }
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}
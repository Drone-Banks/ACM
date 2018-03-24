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

int n,x;
vector<int> ans;
int limit = 1000000;
bool solve()
{
    random_shuffle(ans.begin(), ans.end());
    int tmp = 0;
    for(int i=0;i<n-1;i++) tmp ^= ans[i];
    tmp^=x;
    for(int i=0;i<n-1;i++) 
    {
        if(tmp == ans[i]) return false;
    }
    if(tmp>limit) return false;
    return true;
}

int main()
{
    //std::ios::sync_with_stdio(false);
    srand(time(NULL));
    for(int i=0;i<=limit;i++) ans.pb(i);
    while(~scanf("%d%d", &n, &x))
    {
        if(n==2 && x==0) puts("NO");
        else if(n==1) printf("YES\n%d\n", x);
        else
        {
            puts("YES");
            while(!solve());
            for(int i=0;i<n-1;i++) printf("%d ", ans[i]),x^=ans[i];
            printf("%d\n", x);
        }

    }
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}
close
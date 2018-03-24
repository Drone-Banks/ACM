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

vector<LL> ANS;
LL base2[71], base3[71];
void dfs(LL val, LL ans)
{
    // cout << val << " " << ans << endl;
    int x = 0, y = 0;
    while(val%2==0){
        x++;
        val/=2;
        ans*=2;
    }
    while(val%3==0){
        y++;
        val/=3;
        ans*=3;
    }
    if(val==1) {
        ANS.push_back(ans);
        return;
    }
    LL n = 1;
    while(n<val){
        n*=3;
    }
    n/=3;
    val -= n;
    ANS.push_back(ans*n);
    dfs(val, ans);
}

int main()
{
    //std::ios::sync_with_stdio(false);
    freopen("distribution.in", "r", stdin);
    freopen("distribution.out", "w", stdout);
    int t;
    scanf("%d", &t);
    LL val;
    while(t--)
    {
        scanf("%lld", &val);
        ANS.clear();
        dfs(val, 1);
        int n = ANS.size();
        printf("%d\n", n);
        for(int i=0;i<n;i++)
        {
            printf("%lld%c", ANS[i], " \n"[i==n-1]);
        }
    }
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}
close
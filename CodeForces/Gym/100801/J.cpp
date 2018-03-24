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

int n,limit,p[MaxN],d[MaxN];
int que[MaxN];
LL dp[MaxN];
bool check(int len)
{
    if(len==0) return false;
    dp[1] = 0;
    int head = 1, tail = 0;
    que[++tail] = 1;
    for(int i=2;i<=n;i++)
    {
        dp[i] = dp[que[head]] + d[i];
        while( tail>=head && dp[que[tail]] >= dp[i]) 
            tail--;
        que[++tail] = i;
        while( head<=tail && i-que[head] >= len ) 
            head++;
    }
    if(dp[n]>limit) return false;
    else return true;
}

void solve()
{
    int L = 0, R = n-1;
    while(L<=R)
    {
        int mid = (L+R)>>1;
        if(check(mid))
            R = mid-1;
        else
            L = mid+1;
    }
    int ans = p[L];
    for(int i=L+1;i<n;i++) ans = min(ans, p[i]);
    printf("%d\n", ans);
}

int main()
{
   freopen("journey.in", "r", stdin);
   freopen("journey.out", "w", stdout);
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &limit))
    {
        limit -= (n-1);
        for(int i=1;i<n;i++) scanf("%d", &p[i]);
        for(int i=2;i<n;i++) scanf("%d", &d[i]);
        solve();
    }
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}
close
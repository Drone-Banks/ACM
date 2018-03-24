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
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}

int n;
char str[1005];
int num[29];

int dp[1005];
int cnt[1005];
int len[1005];
void solve()
{
    CLR(dp);MST(cnt,INF);CLR(len);
    for(int i=1;i<=n;i++)
    {
        int limit = num[str[i]-'a'];
        if(i==1) 
        {
            dp[1] = len[1] = 1, cnt[1] = 1;
            continue;
        }
        for(int j=i-1;j>=1;j--)
        {   
            if(limit<(i-j)) break;
            dp[i] = (dp[i]+dp[j])%mod;
            len[i] = max(len[i], max(len[j], (i-j)));
            cnt[i] = min(cnt[i],cnt[j]+1);
            limit = min(limit, num[str[j]-'a']);
        }
        if(i<=limit)
        {
            dp[i] = (dp[i]+1)%mod;
            len[i] = i;
            cnt[i] = 1;
        }
    }
    int ans = dp[n]%mod, MaxL = len[n], MinN = cnt[n];
    printf("%d\n%d\n%d\n", ans, MaxL, MinN);
}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &n))
    {
        scanf("%s", str+1);
        for(int i=0;i<26;i++) scanf("%d", &num[i]);
        solve();
    }
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

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

#define MaxN 500005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const LD eps = 1e-13;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}

LL l, a, b, t, r, loc[MaxN];
int n,nxt[MaxN];
LD DP[MaxN];
bool Less(LD x, LD y)
{
    // cout << x << "<" << y << endl;
    if( x-y >= eps) return false;
    else return true;
}
vector<int> ans;
void solve()
{
    for(int i=1;i<=n;i++) DP[i] = (LD)(1000000000000), nxt[i] = n+1;
    DP[n+1] = 0;
    LD dis,res;
    for(int i=n;i>=1;i--)
    {
        LL sb = loc[i]+a*t+b*r;
        int id = i+1;
        dis = loc[id]-loc[i]; 
        if( dis <= a*t ) {
            LD tar = DP[id] + dis/a;
            if(Less(tar, DP[i])) {
                DP[i] = tar;
                nxt[i] = id;
            }
        }
        id = lower_bound(loc+1, loc+2+n, sb) - (loc);
        dis = loc[id-1]-loc[i]; 
        if( dis>=a*t && dis<=a*t+b*r ){
            LD tar = DP[id-1] + t + (dis-a*t)/b;
            if(Less(tar, DP[i])) {
                DP[i] = tar;
                nxt[i] = id-1;
            }
        } 
        dis = loc[id]-loc[i];
        if( dis>=a*t+b*r ){
            LD tar = DP[id] + t + r + (dis-a*t-b*r)/a;
            if(Less(tar, DP[i])) {
                DP[i] = tar;
                nxt[i] = id;
            }
        } 
    }
    ans.clear();
    int now = 1;
    while(now!=n+1)
    {
        ans.pb(now-1);
        now = nxt[now];
    }
    printf("%d\n", ans.size());
    for(int i=0;i<ans.size();i++) printf("%d%c", ans[i], " \n"[i==ans.size()-1]);
}
int main()
{
    while(~scanf("%lld%lld%lld%lld%lld", &l, &a, &b, &t, &r))
    {
        scanf("%d", &n);
        for(int i=1;i<=n;i++) scanf("%lld", &loc[i]);
        loc[n+1] = l;
        solve();
    }
}

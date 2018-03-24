/*************************************************************************
    > File Name: vioA.cpp
    > Author: HandsomeHow
    > Mail: handsomehowyxh@gmail.com 
    > Created Time: 2017年07月09日 星期日 14时07分41秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define mp make_pair
#define cl(a) memset((a),0,sizeof(a))
#ifdef HandsomeHow
#define dbg(x) cerr << #x << " = " << x << endl
#else
#define dbg(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
const int inf=0x3f3f3f3f;
const double eps=1e-8;
const int mod=1000000007;
const double pi=acos(-1.0);
inline void gn(long long&x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;}
inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
ll gcd(ll a,ll b){return a? gcd(b%a,a):b;}
ll powmod(ll a,ll x,ll mod){ll t=1ll;while(x){if(x&1)t=t*a%mod;a=a*a%mod;x>>=1;}return t;}
// (づ°ω°)づe★------------------------------------------------
const int maxn = 5e4+5;
int x[maxn], y[maxn], z[maxn];
ll ans[33];
int calc(int i, int j){
	return abs(x[i]-x[j]) + abs(y[i]-y[j]) + abs(z[i]-z[j]);
}
int main(){
#ifdef HandsomeHow
	freopen("/home/handsomehow/contest/data/A/A3.in","r",stdin);
	freopen("/home/handsomehow/contest/data/A/vioA3.out","w",stdout);
#endif
	int T;gn(T);
	while(T--){
		cl(ans);
		dbg(T);
		int n, q;gn(n);gn(q);
		rep(i,1,n){
			gn(x[i]);gn(y[i]);gn(z[i]);
		}
		rep(i,1,n)rep(j,i+1,n){
			int dd = calc(i,j);
			ans[dd]++;
		}	
		rep(i,1,30)ans[i]+=ans[i-1];
		//rep(i,1,30)cerr<<i<<" "<<ans[i]<<endl;
		while(q--){
			int d;gn(d);
			if(d>30)d=30;
			printf("%lld\n",ans[d]);
		}
	}
	return 0;
}

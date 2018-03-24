/*************************************************************************
    > File Name: std.cpp
    > Author: HandsomeHow
    > Mail: handsomehowyxh@gmail.com 
    > Created Time: 2017年07月09日 星期日 13时48分51秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long ll;
ll powmod(ll a,ll x,ll mod){ll t=1ll;while(x){if(x&1)t=t*a%mod;a=a*a%mod;x>>=1;}return t;}

bool in(long long x, long long l, long long r){ return x >= l && x <= r; }
int main(){
#ifdef HandsomeHow
	freopen("/home/handsomehow/contest/data/B/B5.in","r",stdin);
	freopen("/home/handsomehow/contest/data/B/vioB5.out","w",stdout);
#endif
	int T;scanf("%d",&T);
	//cerr<<T<<endl;
	assert(in(T,1,1000));
	while(T--){
		long long n, k, p;
		scanf("%lld%lld%lld",&n,&k,&p);
		assert(in(n,1,1000000000000000000));
		assert(in(k,0,1000000000000000000));
		assert(in(p,1,1000000000000000000));
		assert(in(n-p,0,100));
		long long ans = 0;
		rep(i,1,n){
			ans += powmod(i,k,p);
			ans %= p;
		}
		//cerr<<n<<" "<<k<<" "<<p<<" "<<ans<<endl;
		cout<<ans<<endl;
	}
	return 0;
}

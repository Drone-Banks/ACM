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
ll mul(ll a, ll b, ll p){
	ll ret = 0ll;
	ll t = a;
	while(b){
		if(b&1)ret=(ret+t)%p;
		b>>=1;
		t=(t*2ll)%p;
	}
	return ret;
}
ll powmod(ll a,ll x,ll mod){
	ll t=1ll;
	while(x){
		if(x&1)t=mul(t,a,mod);
		a=mul(a,a,mod);
		x>>=1;
	}
	return t;
}

bool in(long long x, long long l, long long r){ return x >= l && x <= r; }
long long solve(long long n, long long k, long long p){
	if(p==2) {
		if(k==0)return n%2;
		long long has = (n + 1ll) / 2;
		return has % 2;
	}
	long long ans = 0;
	if((k % (p-1) )== 0ll)ans = p - 1;
	for(long long i = p; i <= n; ++i){
		ans = (ans + powmod(i,k,p))%p;
		if(ans<0)assert(0);
	}
	return ans;
}
int main(){
#ifdef HandsomeHow
	freopen("/home/handsomehow/contest/data/B/B5.in","r",stdin);
	freopen("/home/handsomehow/contest/data/B/B5.out","w",stdout);
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
		cout<<solve(n,k,p)<<endl;
	}
	return 0;
}

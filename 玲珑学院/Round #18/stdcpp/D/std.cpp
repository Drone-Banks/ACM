/*************************************************************************
    > File Name: std.cpp
    > Author: HandsomeHow
    > Mail: handsomehowyxh@gmail.com 
    > Created Time: 2017年07月09日 星期日 13时48分51秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#ifdef HandsomeHow
#define dbg(x) cerr << #x << " = " << x << endl
#else
#define dbg(x)
#endif
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)


bool in(long long x, long long l, long long r){ return x >= l && x <= r; }

const int maxn = 1e5+5;
int dis[maxn];
long long dp[maxn];
int n, a;
long long calc(int len, int a){
	if(len > 62) return -1;
	return (1ll<<len)+a;
}
int main(){
#ifdef HandsomeHow
	freopen("/home/handsomehow/contest/data/D/D4.in","r",stdin);
	freopen("/home/handsomehow/contest/data/D/D4.out","w",stdout);
#endif
	int T;scanf("%d",&T);
	//cerr<<T<<endl;
	assert(in(T,1,10));
	while(T--){
		memset(dp,0x3f,sizeof(dp));
		scanf("%d%d",&n,&a);
		assert(in(n,1,100000));
		assert(in(a,0,1000000));
		rep(i,1,n)scanf("%d",dis+i);
		rep(i,1,n)assert(in(dis[i],0,3000000));
		rep(i,2,n)assert(in(dis[i]-dis[i-1],0,30));
		dp[1] = 0ll;
		rep(i,2,n){
			dp[i] = dp[i-1] + calc(dis[i]-dis[i-1],a);
			for(int j = i; j > 0 && j >= i - 60; j--){
				long long cc = calc(dis[i]-dis[j],a);
				if(cc == -1)break;
				if(1.0*cc + 1.0*dp[j] < 1.0*dp[i]){
					dp[i] = cc + dp[j];
				}
			}
		}
		printf("%lld\n",dp[n]);
	}
	return 0;
}

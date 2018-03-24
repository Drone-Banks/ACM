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

long long cnt[11][11][11], ans[44];

int dis(int xa, int ya, int za, int xb, int yb, int zb){
	return abs(xa - xb) + abs(ya - yb) + abs(za - zb);
}
bool in(int x, int l, int r){ return x >= l && x <= r; }
int main(){
#ifdef HandsomeHow
	freopen("/home/handsomehow/contest/data/A/A3.in","r",stdin);
	freopen("/home/handsomehow/contest/data/A/A3.out","w",stdout);
#endif
	int T;scanf("%d",&T);
	assert(in(T,1,10));
	while(T--){
		memset(cnt,0,sizeof(cnt));
		memset(ans,0,sizeof(ans));
		int n, q;scanf("%d%d",&n,&q);
		assert(in(n,1,50000) && in(q,1,1000));
		for(int i = 0; i < n; ++i){
			int x, y, z;
			scanf("%d%d%d",&x,&y,&z);
			assert(in(x,0,10)); assert(in(y,0,10)); assert(in(z,0,10));
			cnt[x][y][z]++;
		}
		for(int xa = 0; xa <= 10; ++xa){
			for(int ya = 0; ya <= 10; ++ya){
				for(int za = 0; za <= 10; ++za){
					for(int xb = 0; xb <= 10; ++xb){
						for(int yb = 0; yb <= 10; ++yb){
							for(int zb = 0; zb <= 10; ++zb){
								int d = dis(xa,ya,za,xb,yb,zb);
								if(d == 0){
									long long c = cnt[xa][ya][za];
									ans[d] += c * (c - 1) / 2;
								}else{
									ans[d] += cnt[xa][ya][za] * cnt[xb][yb][zb];
								}
							}
						}
					}
				}
			}
		}
		rep(i,1,30)ans[i]/=2;
		for(int i = 1; i <= 30; ++i)ans[i] += ans[i-1];
		while(q--){
			int d;scanf("%d",&d);
			assert(in(d,0,1000000000));
			if(d > 30) d = 30;
			printf("%lld\n",ans[d]);
		}
	}
	return 0;
}

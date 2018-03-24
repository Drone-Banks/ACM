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
bool in(long long x, long long l, long long r){ return x >= l && x <= r; }
const int maxn = 1e5+5;
vector<int>color[maxn];
bool has[333];
int main(){
#ifdef HandsomeHow
	freopen("/home/handsomehow/contest/data/C/C5.in","r",stdin);
	freopen("/home/handsomehow/contest/data/C/vioC5.out","w",stdout);
#endif
	int T;scanf("%d",&T);
	//cerr<<T<<endl;
	assert(in(T,1,5));
	rep(kase,1,T){
		cerr<<kase<<endl;
		int n, m,q;scanf("%d%d%d",&n,&m,&q);
		rep(i,1,n)color[i].resize(m+1);
		rep(i,1,n)rep(j,1,m)scanf("%d",&color[i][j]);
		rep(_,1,q){
			int op;
			scanf("%d",&op);
			//cerr<<op<<endl;
			if(op==1){
				int x, y;
				scanf("%d%d",&x,&y);
				printf("%d\n",color[x][y]);
			}else if(op==2){
				memset(has,0,sizeof(has));
				int k,l,r;
				scanf("%d%d%d",&k,&l,&r);
				for(int i = l; i <= r; ++i)has[color[k][i]]=true;
				int ans = 0;
				for(int i = 0; i < 256; ++i)ans += has[i];
				printf("%d\n",ans);
			}else if(op == 3){
				int z, l, r, k;
				scanf("%d%d%d%d",&k,&l,&r,&z);
				z %= 256;
				for(int i = l; i <= r; ++i){
					color[k][i] += z;
					color[k][i] %= 256;
				}
			}else{
				int k, l, r;
				scanf("%d%d%d",&k,&l,&r);
				for(;l<r;l++,r--){
					swap(color[k][l],color[k][r]);
				}
			}
		}
	}
	return 0;
}

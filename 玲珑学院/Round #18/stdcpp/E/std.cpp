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
struct EDGE{
	int to, len, nxt;
}edge[maxn*2];
int head[maxn];
int tot, n, a;
void ae(int u, int v, int len){
	tot++;edge[tot].to=v;edge[tot].len=len;edge[tot].nxt=head[u];head[u]=tot;
}

long long ans;
int mx[maxn], c[maxn], idx;

int sz[maxn];
int dfs(int u, int p){
	sz[u]=1;
	for(int i = head[u]; ~i; i = edge[i].nxt){
		int to = edge[i].to;
		if(to==p)continue;
		int here = dfs(to, u);
		sz[u]+=here;
		mx[++idx]=min(here,n-here);
		ans += 1ll*edge[i].len*mx[idx];
	}
	return sz[u];
}
int main(){
#ifdef HandsomeHow
	freopen("/home/handsomehow/contest/data/E/E3.in","r",stdin);
	freopen("/home/handsomehow/contest/data/E/E3.out","w",stdout);
#endif
	int T;scanf("%d",&T);
	//cerr<<T<<endl;
	assert(in(T,1,10));
	while(T--){
		tot=0;memset(head,-1,sizeof(head));
		scanf("%d%d",&n,&a);
		assert(in(n,1,100000));
		assert(in(a,0,n-1));
		rep(i,2,n){
			int x, y, z;
			scanf("%d%d%d",&x,&y,&z);
			assert(in(x,1,n));
			assert(in(y,1,n));
			assert(in(z,1,100000));
			ae(x,y,z); ae(y,x,z);
		}
		rep(i,1,a)scanf("%d",&c[i]);
		rep(i,1,a)assert(in(c[i],1,100000));
		ans=0; idx=0;
		dfs(1,-1);
		sort(mx+1,mx+1+idx);
		reverse(mx+1,mx+1+idx);
		sort(c+1,c+1+a);
		reverse(c+1,c+1+a);
		rep(i,1,a)ans+=1ll*mx[i]*c[i];
		cout<<ans<<endl;
	}
	return 0;
}

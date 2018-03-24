#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
#include<cassert>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int a[114514],b[114514];
lint c[114514],cap[114514];
int ch[114514];
bool ng[114514];
vector<pint> gr[114514];
int n;
void dfs(int v,int u){
	ch[v]=1;
	rep(i,gr[v].size()){
		pint p=gr[v][i];
		if(p.se==u) continue;
		dfs(p.fi,p.se);
		ch[v]+=ch[p.fi];
	}
	if(u>=0) cap[u]=min(ch[v],n-ch[v]);
}
int main()
{
	cin>>n;
	rep(i,n-1){
		cin>>a[i]>>b[i]>>c[i];
		a[i]--;b[i]--;
		gr[a[i]].pb(mp(b[i],i));
		gr[b[i]].pb(mp(a[i],i));
	}
	dfs(0,-1);
	//rep(i,n-1) cout<<a[i]<<' '<<b[i]<<' '<<c[i]<<' '<<cap[i]<<endl;
	rep(i,n){
		if(gr[i].size()==1) continue;
		lint su=0,ma=0;int maj;
		rep(j,gr[i].size()){
			pint p=gr[i][j];
			su+=cap[p.se];
			if(ma<cap[p.se]) maj=p.se,ma=cap[p.se];
		}
		//cout<<i<<' '<<ma<<' '<<su<<' '<<maj<<endl;
		if(ma*2>su){
			rep(j,gr[i].size()){
				pint p=gr[i][j];
				if(p.se!=maj) ng[p.se]=true;
			}
		}
	}
	lint out=0,ma2=1145141919;
	rep(i,n-1){
		out+=2*cap[i]*c[i];
		if(!ng[i]) ma2=min(ma2,c[i]);
		//if(ng[i]) cout<<a[i]<<' '<<b[i]<<endl;
	}
	cout<<out-ma2<<endl;
}
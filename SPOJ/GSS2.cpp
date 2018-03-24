#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)

const int maxn=100010;
const int maxv=1000010;
const int zero=1000010;

struct query_ele
{
	int l,r,id;
	inline bool operator<(const query_ele &t)const{ return r<t.r; }
}q[maxn];

int max_v[maxn<<2],max_o[maxn<<2],add[maxn<<2],add_o[maxn<<2],ans[maxn],num[maxn];
int last[maxv<<1|1];

inline void up(int rt){
	max_v[rt]=max(max_v[ls],max_v[rs]);
	max_o[rt]=max(max_o[ls],max_o[rs]);
}

inline void down(int rt){
	if (add[rt]||add_o[rt])
	{
		add_o[ls]=max(add_o[ls],add[ls]+add_o[rt]);
		add_o[rs]=max(add_o[rs],add[rs]+add_o[rt]);
		add[ls]+=add[rt];add[rs]+=add[rt];
		max_o[ls]=max(max_o[ls],max_v[ls]+add_o[rt]);
		max_o[rs]=max(max_o[rs],max_v[rs]+add_o[rt]);
		max_v[ls]+=add[rt];
		max_v[rs]+=add[rt];
		add[rt]=add_o[rt]=0;
	}
}
void ins(int rt,int l,int r,int L,int R,int v){
	if (L<=l&&r<=R){
		add[rt]+=v,add_o[rt]=max(add[rt],add_o[rt]);
		max_v[rt]+=v;
		max_o[rt]=max(max_o[rt],max_v[rt]);
		return;
	}
    down(rt);
    if(L<=mid) ins(ls,l,mid,L,R,v);
    if(mid<R)  ins(rs,mid+1,r,L,R,v);
    up(rt);
}
int query(int rt,int l,int r,int L,int R){
	if (L<=l&&r<=R) return max_o[rt];
    down(rt);
    int ans=0;
    if(L<=mid) ans=max(ans,query(ls,l,mid,L,R));
    if(mid<R)  ans=max(ans,query(rs,mid+1,r,L,R));
	return ans;
}

int main()
{
	int now,m,n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	sort(q+1,q+m+1),now=1;
	for (int i=1;i<=m;i++){
		for (;now<=q[i].r;now++){
            ins(1,1,n,last[num[now]+zero]+1,now,num[now]);
			last[num[now]+zero]=now;
		}
        ans[q[i].id]=query(1,1,n,q[i].l,q[i].r);
	}
	for (int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}
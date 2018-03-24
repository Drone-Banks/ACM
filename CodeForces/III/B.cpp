/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define pb push_back
using namespace std;

#define MaxN 200010
#define MaxM MaxN
#define INF 2E12
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
inline int max2(int a, int b) {return ((a > b)? a : b);}
inline int min2(int a, int b) {return ((a < b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}
inline int min3(int a, int b, int c) {return min2(a, min2(b, c));}
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}
struct Node
{
    int L,R;
    LL sum, add;
    int mid(){return (L+R)/2;}
    Node (){}
    Node (int l, int r, LL sum, LL add):L(l),R(r),sum(sum),add(add){}
}tr[MaxN<<3];
struct Seg {
	LL val[MaxN];      //线段树信息
	Node UP(Node rt, Node ls, Node rs)
	{
		Node tmp = Node(rt.L, rt.R, min2( ls.sum, rs.sum) ,rt.add);
		return tmp;
	}
    void Push(int rt)
    {
        if(tr[rt].add!=0)
        {
            LL add = tr[rt].add; tr[rt].add = 0;
            Node ls = tr[rt<<1], rs = tr[rt<<1|1];
            ls.add += add; rs.add += add; 
            ls.sum += add, rs.sum += add;
        }
    }
	void build(int rt, int L, int R)
	{
		tr[rt] = Node(L, R, 0, 0);
		if(L == R){
			tr[rt] = Node(L, R, val[L], 0);
			return;
		}
		build(rt<<1, L, tr[rt].mid());
		build(rt<<1|1, tr[rt].mid()+1, R);
		tr[rt] = UP(tr[rt], tr[rt<<1], tr[rt<<1|1]);
	}
	void update(int rt, int l, int r, LL det) //区间
	{
		if( l <= tr[rt].L && tr[rt].R <= r )
		{
            tr[rt].sum += det;
            tr[rt].add += det;
			return;
		}
        Push(rt);
        if( r <= tr[rt].mid()) update(rt<<1, l, tr[rt].mid(), det);
        else if( l>tr[rt].mid()) update(rt<<1|1, tr[rt].mid()+1, r, det);
		else
        {
            update(rt<<1, l, tr[rt].mid(), det);
            update(rt<<1|1, tr[rt].mid()+1, r, det);
        }
		tr[rt] = UP(tr[rt], tr[rt<<1], tr[rt<<1|1]); 
	}
	LL query(int rt, int L, int R)
	{
		if( L <= tr[rt].L && tr[rt].R <= R)
		{
            // debug(L) debug(R) debug(tr[rt].sum)
			return tr[rt].sum;
		}
        Push(rt);
		if(R<=tr[rt].mid()) return query(rt<<1, L, tr[rt].mid());
		else if( L > tr[rt].mid() ) return query(rt<<1|1, tr[rt].mid()+1, R);
		else
		{
			return min( 
				query(rt<<1, L, tr[rt].mid() ),
				query(rt<<1|1, tr[rt].mid()+1, R) );
		}
	}
} T;
int n,q;
struct Edge
{
    int u,v,next,w;
    Edge(){}
    Edge(int u, int v, int w, int next):u(u),v(v),w(w),next(next){}
}edge[MaxM];int cont,head[MaxN];
void add(int u, int v, int w){edge[cont] = Edge(u,v,w,head[u]), head[u] = cont++;}

int id[MaxN*2];
LL toto[MaxN], back[MaxN];
int L[MaxN],R[MaxN],dfn;

void dfs(int u, LL w)
{
    L[u] = ++dfn; T.val[dfn] = w + back[u];  
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        dfs(v, w+edge[i].w);
    }
    R[u] = dfn;
}

void solve()
{
    dfn = 0;
    dfs(1, 0);
    T.build(1,1,n);
    int op,a,b;
    while(q--)
    {
        scanf("%d%d%d",&op,&a,&b);
        if(op==1)
        {
            if(a>=n)
            {
                LL det = b - back[id[a]];
                back[id[a]] = b;
                // debug(L[id[a]]) debug(det)
                T.update(1, L[id[a]], L[id[a]], det);
            }
            else
            {   
                LL det = b - toto[id[a]];
                toto[id[a]] = b;
                // debug(L[id[a]]) debug(det)
                T.update(1, L[id[a]], R[id[a]], det);
            }
        }
        else
        {
            LL ans;
            if(a==b) ans = 0;
            else 
            {
                LL toa = (T.query(1,L[a],L[a])-back[a]), tob = (T.query(1,L[b],L[b])-back[b]);
                // debug(toa) debug(tob)
                ans = tob-toa;
                if(L[a]<= L[b] && L[b]<=R[a]) ;
                else 
                    ans += T.query(1,L[a],R[a]);
            }
            printf("%lld\n",ans);
        }
    }
}

void init(){cont = 0, MST(head, -1);}
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d%d", &n, &q);
    {
        init();
        int u,v,w;
        for(int i=1;i<=n-1;i++) 
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            toto[v] = w;
            id[i] = v;
        }
        for(int i=n;i<=2*n-2;i++) 
        {
            scanf("%d%d%d",&u,&v,&w);
            back[u] = w;
            id[i] = u;
        }   
        solve();
    }
    //system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}


///
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define debug(x) cout << #x" = " << x << endl;

struct Node{
	int v,num,next;
}edge[200010];
int cnt,head[200010];
void add(int x,int y,int v){
	edge[cnt].num=y;
	edge[cnt].next=head[x];
	edge[cnt].v=v;
	head[x]=cnt++;
}
struct Node1{
	int x,y,v;
}a[400200];
int now;
int f[200100],st[200100],ed[200100];
long long v[200100];
long long t[200100<<3],fl[200100<<3];
int sav[200100];
void dfs(int x,long long d){
	v[now]=d+sav[x];
	st[x]=now;
	f[x]=now++;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].num;
		dfs(v,d+edge[i].v);
	}
	ed[x]=now-1;
}

void build(int rt,int l,int r){
	if(l==r){
		fl[rt]=0;
		t[rt]=v[l];
		return ;
	}
	int ls=rt<<1,rs=ls|1,mid=l+r>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[rt]=min(t[ls],t[rs]);
	fl[rt]=0;
}

void add(int L,int R,int rt,int l,int r,long long v){
	if(l==L&&r==R){
		fl[rt]+=v;
		t[rt]+=v;
		return;
	}
	int ls=rt<<1,rs=ls|1,mid=l+r>>1;
	if(fl[rt]){
		t[ls]+=fl[rt];
		t[rs]+=fl[rt];
		fl[ls]+=fl[rt];
		fl[rs]+=fl[rt];
		fl[rt]=0;
	}
	if(R<=mid) add(L,R,ls,l,mid,v);
	else if(L>mid) add(L,R,rs,mid+1,r,v);
	else add(L,mid,ls,l,mid,v),add(mid+1,R,rs,mid+1,r,v);
	t[rt]=min(t[ls],t[rs]);
}

long long query(int L,int R,int rt,int l,int r){
	if(L==l&&R==r){
        // debug(L) debug(R) debug(t[rt])
		return t[rt];
	}
	int ls=rt<<1,rs=ls|1,mid=l+r>>1;
	if(fl[rt]){
		t[ls]+=fl[rt];
		t[rs]+=fl[rt];
		fl[ls]+=fl[rt];
		fl[rs]+=fl[rt];
		fl[rt]=0;
	}
	if(R<=mid) return query(L,R,ls,l,mid);
	else if (L>mid) return query(L,R,rs,mid+1,r);
	else return min(query(L,mid,ls,l,mid),query(mid+1,R,rs,mid+1,r));
}


int main(){
	int n,q;
	int op,x,y;
	while(~scanf("%d%d",&n,&q)){
		cnt=0;
		memset(head,-1,sizeof(head));
		for(int i=1;i<n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
			add(a[i].x,a[i].y,a[i].v);
		}
		for(int i=n;i<n+n-1;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
			sav[a[i].x]=a[i].v;
		}
		now=1;
		dfs(1,0);
		// for(int i=n;i<n+n-1;i++){
		// 	v[f[a[i].x]]+=a[i].v;
		// }
		build(1,1,n);
		for(int i=0;i<q;i++){
			scanf("%d%d%d",&op,&x,&y);
			if(op==1){
				if(x<n){
                    // debug(st[a[x].y]) debug(y-a[x].v)
					add(st[a[x].y],ed[a[x].y],1,1,n,y-a[x].v);
					a[x].v=y;
				}
				else{
                    // debug(st[a[x].x]) debug(y-a[x].v)
					add(st[a[x].x],st[a[x].x],1,1,n,y-a[x].v);
					a[x].v=y;
					sav[a[x].x]=y;
				}
			}
			else{
				long long  ans;
				ans=query(st[x],st[x],1,1,n)-query(st[y],st[y],1,1,n)-sav[x]+sav[y];
				ans=-ans;
				if(st[y]>=st[x]&&st[y]<=ed[x]);
				else{
					ans+=query(st[x],ed[x],1,1,n);
				}
				printf("%I64d\n",ans);
			}
		}
	}
}
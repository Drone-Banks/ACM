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

int n, m,q;
const int inf=0x3f3f3f3f;

bool first;
const int maxn = 1e5+5;
int oriv[maxn];

void move(bitset<256>&a, int step){ a = (a<<step) | (a>>(256-step)); }
#define ls(n) node[(n)].ch[0]
#define rs(n) node[(n)].ch[1]
struct splayTree{
    struct Node{
        int fa, ch[2];
        int val, add,  size;
		bool rev;
		bitset<256>su;
        void init(int _val){
			rev=0;
			su.reset();
            val =  _val;
            size = 1;
            add =  ch[0] = ch[1] = 0;
			if(_val >= 0 && _val <256)su[_val] = 1;
        }
    }node[maxn];
    int root;

    void up(int n){
		node[n].su = node[ls(n)].su | node[rs(n)].su;
		if(node[n].val >=0 && node[n].val < 256) node[n].su[node[n].val] = 1;
        node[n].size = node[ls(n)].size + node[rs(n)].size + 1;
    }

    void down(int n){
        if(n == 0) return;
        if(node[n].add){
            int ad = node[n].add;
            node[n].add = 0;
            if(ls(n)){
                node[ls(n)].val += ad;
                node[ls(n)].val %= 256;
				move(node[ls(n)].su,ad);
                node[ls(n)].add += ad;
                node[ls(n)].add %= 256;
            }
            if(rs(n)){
                node[rs(n)].val += ad;
                node[rs(n)].val %= 256;
				move(node[rs(n)].su,ad);
                node[rs(n)].add += ad;
                node[rs(n)].add %= 256;
            }
        }
		if(node[n].rev){
			if(ls(n)) node[ls(n)].rev ^= 1;
			if(rs(n)) node[rs(n)].rev ^= 1;
			swap(ls(n),rs(n));
			node[n].rev = 0;
		}
    }

    void rotate(int n, bool kind){
        int fn = node[n].fa;
        int ffn = node[fn].fa;
        node[fn].ch[!kind] = node[n].ch[kind];
        node[node[n].ch[kind]].fa = fn;

        node[n].ch[kind] = fn;
        node[fn].fa = n;

        node[ffn].ch[rs(ffn) == fn] = n;
        node[n].fa = ffn;
        up(fn);
    }

    void splay(int n, int goal){ 
        //make n the son of goal
        while(node[n].fa != goal){
            int fn = node[n].fa;
            int ffn = node[fn].fa;
            down(ffn); down(fn); down(n);
            bool rotate_n = (ls(fn) == n);
            bool rotate_fn = (ls(ffn) == fn);
            if(ffn == goal) rotate(n,rotate_n);
            else{
                if(rotate_n == rotate_fn) rotate(fn,rotate_fn);
                else rotate(n, rotate_n);
                rotate(n, rotate_fn);
            }
        }
        up(n);
        if(goal == 0) root = n;
    }

    int select(int pos){
        int u = root;
        down(root);
        while(node[ls(u)].size != pos){
            if(pos < node[ls(u)].size)
                u = ls(u);
            else{
                pos -= node[ls(u)].size + 1;
                u = rs(u);
            }
            down(u);
        }
        return u;
    }

    int query(int l, int r){
        int u = select(l - 1), v = select(r + 1);
        splay(u,0);
        splay(v,u);
        return node[ls(v)].su.count();
    }
	void reverse(int l, int r){
		int u = select(l - 1), v = select(r + 1);
		splay(u, 0); splay(v, u);
		node[ls(v)].rev ^= 1;
	}

    void update(int l, int r, int val){
        int u = select(l - 1), v = select(r + 1);
        splay(u, 0); splay(v, u);
        node[ls(v)].val += val;
		node[ls(v)].val %= 256;
		move(node[ls(v)].su,val);
        node[ls(v)].add += val;
        node[ls(v)].add %= 256;
    }

    int build(int l, int r){
        if(l > r)
            return 0;
        if(l == r)
            return l;
        int mid = (l + r) >> 1;
        int rl, rr;
        ls(mid) = rl = build(l, mid-1);
        rs(mid) = rr = build(mid + 1, r);
        node[rl].fa = node[rr].fa = mid;
        up(mid);
        return mid;
    }

    void init(int n){
        node[0].init(-inf); node[0].size = 0;
        node[1].init(-inf);
        //put tow virtual at the begin and the end
        node[n + 2].init(-inf);
        rep(i,2,n+1)
            node[i].init(oriv[i-1]);

        root = build(1,n+2);
        node[root].fa = 0;

        node[0].fa = 0;
        ls(0) = root;
    }

    void travel(int u){
        down(u);
        if(ls(u))
            travel(ls(u));
        if(node[u].val != -inf){
            if(!first)
                putchar(' ');
            first = false;
            printf("%d",node[u].val);
        }//the first and the last node is virtual

        if(rs(u))
            travel(rs(u));
    }


}spt;

bool in(long long x, long long l, long long r){ return x >= l && x <= r; }

inline int gid(int x, int y){ return (x-1)*m+y; }
int main(){
#ifdef HandsomeHow
	freopen("/home/handsomehow/contest/data/C/C5.in","r",stdin);
	freopen("/home/handsomehow/contest/data/C/C5.out","w",stdout);
#endif
	int T;scanf("%d",&T);
	//cerr<<T<<endl;
	assert(in(T,1,5));
	while(T--){
		scanf("%d%d%d",&n,&m,&q);
		assert(in(n*m,1,100000));
		assert(in(q,0,100000));
		rep(i,1,n*m)scanf("%d",oriv+i);
		spt.init(n*m);
		//spt.travel(0);
		//puts("");
		rep(_,1,q){
			int op;scanf("%d",&op);
			if(op==1){
				int x, y;
				scanf("%d%d",&x,&y);
				int id = gid(x,y);
				assert(in(x,1,n));
				assert(in(y,1,m));
				int u = spt.select(id);
				printf("%d\n",spt.node[u].val);
			}else if(op==2){
				int k, l, r;
				scanf("%d%d%d",&k,&l,&r);
				assert(in(k,1,n));
				assert(in(l,1,m)); assert(in(r,1,m));
				assert(l<=r);
				printf("%d\n",spt.query(gid(k,l),gid(k,r)));
			}else if(op==3){
				int k,l,r,z;
				scanf("%d%d%d%d",&k,&l,&r,&z);
				assert(in(k,1,n));
				assert(in(l,1,m)); assert(in(r,1,m));
				assert(l<=r);
				assert(in(z,1,1000000000));
				z %= 256;
				if(z) spt.update(gid(k,l),gid(k,r),z);
			}else{
				int k, l, r;
				scanf("%d%d%d",&k,&l,&r);
				assert(in(k,1,n));
				assert(in(l,1,m)); assert(in(r,1,m));
				assert(l<=r);
				spt.reverse(gid(k,l),gid(k,r));
			}
			//spt.travel(0);
			//puts("");
		}
	}
	return 0;
}

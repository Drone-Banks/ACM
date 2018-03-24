/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
    区间查询注意 l,r 的大小关系
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

#define MaxN 100005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
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

int N,M;
struct Node
{
    int L,R;
    LL sum;
    bool one;
    int mid(){return (L+R)/2;}
    Node (){}
    Node (int l, int r, LL s, bool one):L(l),R(r),sum(s),one(one){}
}tr[MaxN<<4];

struct Seg {
	LL val[MaxN];      //线段树信息
	Node UP(Node rt, Node ls, Node rs)
	{
		Node tmp = Node(ls.L, rs.R, ls.sum+rs.sum, ls.one && rs.one );
		return tmp;
	}
    void Push(int rt)
    {
        if(tr[rt].one)
        {
            tr[rt<<1].one = tr[rt<<1|1].one = true;
        } 
    }
	void build(int rt, int L, int R) 
	{
		tr[rt].L = L, tr[rt].R = R;
		if(L == R){
            //debug(rt) debug(L) debug(val[L])
			tr[rt] = Node(L,R,val[L],val[L]==1);
			return;
		}
		build(rt<<1, L, tr[rt].mid());
		build(rt<<1|1, tr[rt].mid()+1, R);
		tr[rt] = UP(tr[rt], tr[rt<<1], tr[rt<<1|1]);
	}
	void update(int rt, int l, int r)
	{
        if( tr[rt].one) return;
		if(tr[rt].L == tr[rt].R && l <= tr[rt].L && tr[rt].R <= r )
		{
			tr[rt].sum = sqrt(tr[rt].sum);
            tr[rt].one = (tr[rt].sum==1);
			return;
		}
        Push(rt);
        if( r <= tr[rt].mid()) update(rt<<1, l, r);
        else if( l>tr[rt].mid()) update(rt<<1|1, l, r);
        else 
        {
            update(rt<<1, l, tr[rt].mid());
            update(rt<<1|1, tr[rt].mid()+1, r);
        }
		tr[rt] = UP(tr[rt], tr[rt<<1], tr[rt<<1|1]); 
	}
	Node query(int rt, int L, int R)
	{
        if(tr[rt].one) return Node(L,R,(R-L+1),true);
		if( L <= tr[rt].L && tr[rt].R <= R) 
		{
			return tr[rt];
		}
        Push(rt);
		if(R<=tr[rt].mid()) return query(rt<<1, L, R);
		else if( L > tr[rt].mid() ) return query(rt<<1|1, L, R);
		else
		{
			return UP(tr[rt], 
				query(rt<<1, L, tr[rt].mid() ),
				query(rt<<1|1, tr[rt].mid()+1, R) );
		}
	}
} T;

int main()
{
    //std::ios::sync_with_stdio(false);
    int t = 1;
    while(~scanf("%d", &N))
    {
        printf("Case #%d:\n", t++);
        for(int i=1;i<=N;i++) scanf("%lld", &T.val[i]);
        T.build(1,1,N);
        scanf("%d", &M);
        int a, b, c;
        while(M--)
        {
            scanf("%d%d%d", &a,&b,&c);
            if(b>c) swap(b,c);
            if(a==1)
            {
                LL ans = T.query(1,b,c).sum;
                printf("%lld\n", ans);
            }   
            else
            {
                T.update(1,b,c);
            }
        }
        puts("");
    }

    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

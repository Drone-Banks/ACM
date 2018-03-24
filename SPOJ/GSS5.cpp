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
struct Node
{
    int L,R,Mmax,Lmax,Rmax;
    int mid(){return (L+R)/2;}
    Node (){}
    Node (int l, int r, int Mmax, int Lmax, int Rmax):L(l),R(r),Mmax(Mmax),Lmax(Lmax),Rmax(Rmax){}
}tr[MaxN<<2];

LL sum[MaxN];
struct Seg {
	int val[MaxN];      //线段树信息
	Node UP(Node rt, Node ls, Node rs)
	{
		Node tmp = Node(ls.L, rs.R, max3(ls.Rmax+rs.Lmax, ls.Mmax, rs.Mmax), 
                                    max2(ls.Lmax, sum[ls.R]-sum[ls.L-1]+rs.Lmax), 
                                    max2(rs.Rmax, sum[rs.R]-sum[rs.L-1]+ls.Rmax)  );
		return tmp;
	}
	void build(int rt, int L, int R)
	{
		tr[rt].L = L, tr[rt].R = R;
		if(L == R){
			tr[rt] = Node(L,R,val[L], val[L], val[L]);
			return;
		}
		build(rt<<1, L, tr[rt].mid());
		build(rt<<1|1, tr[rt].mid()+1, R);
		tr[rt] = UP(tr[rt], tr[rt<<1], tr[rt<<1|1]);
	}
	Node query(int rt, int L, int R)
	{
        //debug(rt) debug(L) debug(tr[rt].L)
        if(L>R) return tr[0];
		if( L == tr[rt].L && tr[rt].R == R)
		{
			return tr[rt];
		}
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
    int t,N,M,x1,y1,x2,y2;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &N);
        for(int i=1;i<=N;i++) scanf("%d", &T.val[i]), sum[i] = sum[i-1] + T.val[i];
        T.build(1,1,N);
        scanf("%d", &M);
        while(M--)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if( y1<x2)  
            {
                LL ans = sum[x2-1] - sum[y1];
                ans += (T.query(1,x1,y1).Rmax + T.query(1,x2,y2).Lmax);
                printf("%lld\n", ans);
            }
            else
            {
                LL ans = max3(T.query(1, x2, y1).Mmax, T.query(1, x1, x2-1).Rmax+T.query(1,x2,y2).Lmax, T.query(1, x1, y1).Rmax+T.query(1, y1+1, y2).Lmax);
                printf("%lld\n", ans);
            }
        }
    }
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

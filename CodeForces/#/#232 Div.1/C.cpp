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
using namespace std;

#define MaxN 300010
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
inline int max2(int a, int b) {returnz ((a > b)? a : b);}
inline int min2(int a, int b) {return ((a < b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}
inline int min3(int a, int b, int c) {return min2(a, min2(b, c));}

int n;
struct Edge
{
    int u, v, next;
}edge[MaxM];
int cont, head[MaxN];
void add(int u, int v)
{
    edge[cont].u = u, edge[cont].v = v, edge[cont].next = head[u], head[u] = cont++;
}
int dep[MaxN],L[MaxN],R[MaxN],dfn;
void DFS(int u, int fa,int d)
{
    dep[u] = d;
    L[u] = ++dfn;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(v==fa) continue;
        DFS(v, u, d+1);
    }
    R[u] = dfn;
}
struct BIT{
	int n;
	LL tree[MaxN];
	void init( int n ){
		this->n = n ;
		CLR(tree);
	}
	
	int lowbit( int x ){
		return x & ( -x );
	}
	
	LL sum( int n ){
		LL ans = 0;
		for( int i = n; i ; i -= lowbit(i) ){
			ans = ( ans + tree[i] ) % mod ;
		}
		return ans;
	}
	
	void update( int x, LL val ){
		for( int i = x; i <= n; i += lowbit( i ) ){
			tree[i] = ( tree[i] + val ) % mod ;
		}
	}
}Add,Sub;
void solve()
{
    dfn = 0;
    DFS(1,1,1);
    Add.init(dfn);
    Sub.init(dfn);
}

void init()
{
    cont = 0, MST(head, -1);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &n))
    {
        init();
        int f,op,v,x,k;
        for(int i=2;i<=n;i++)
        {
            scanf("%d", &f);
            add(f, i);
            add(i, f);
        }
        solve();
        scanf("%d", &f);
        while(f--)
        {
            scanf("%d", &op);
            if(op==1)
            {
                scanf("%d%d%d", &v, &x, &k);
                LL val = 1LL*dep[v]*k+x;
                Add.update(L[v],   val);
                Add.update(R[v]+1,-val);

                Sub.update(L[v],   k);
                Sub.update(R[v]+1,-k);
            }
            else 
            {
                scanf("%d", &v);
                LL ans = (Add.sum(L[v]) - (LL)dep[v]*Sub.sum(L[v])%mod);
                printf("%lld\n", ((ans%mod)+mod)%mod );
            }
        }

    }
    //system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
}

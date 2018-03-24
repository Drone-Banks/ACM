/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
#include <climits>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
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
struct BIT{
	int n;
	int tree[MaxN];
	void init( int n ){
		this->n = n ;
		CLR(tree);
	}
	
	int lowbit( int x ){
		return x & ( -x );
	}
	
	int sum( int n ){
		int ans = 0;
		for( int i = n; i ; i -= lowbit(i) ){
			ans = ( ans + tree[i] ) % mod ;
		}
		return ans;
	}
	
	void update( int x, int val ){
		for( int i = x; i <= n; i += lowbit( i ) ){
			tree[i] = ( tree[i] + val ) % mod ;
		}
	}
}bit;
int N;
struct Node
{
    int s,e,loc;
    bool operator < (const Node &a) const
    {
        if(s==a.s) return e>a.e;
        return s<a.s;
    }
}node[MaxN];
int ans[MaxN];
void solve()
{
    sort(node,node+N);
    bit.init(100001);
    for(int i=0;i<N;i++)
    {
        //debug(node[i].e)
        int num = i - bit.sum(node[i].e);
        bit.update(node[i].e+1, 1);
        int loc = i-1;
        while(loc>=0 && node[loc].s == node[i].s && node[loc].e==node[i].e) num--,loc--; 
        //debug(num)
        ans[node[i].loc] = num;
    }
    for(int i=0;i<N;i++)
    {
        printf("%d%c", ans[i], i==N-1 ? '\n' : ' ');
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &N) && N)
    {
        int a,b;
        for(int i=0;i<N;i++) 
        {
            scanf("%d%d", &a, &b);
            node[i].s = a+1, node[i].e = b+1;
            node[i].loc = i;
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

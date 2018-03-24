/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
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
const LL INF = 10000000000;
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;

#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1

int T;
int n,m;
struct Node
{
	LL jj,jo,oj,oo;
}node[MaxN*3];
inline Node Sum(Node l, Node r)
{
	Node ss;
    ss.jj = max(l.jj, r.jj); 
    ss.jj = max(ss.jj, l.jj+r.oj);
    ss.jj = max(ss.jj, l.jo+r.jj);
    ss.jo = max(l.jo, r.jo);
    ss.jo = max(ss.jo, l.jj+r.oo);
    ss.jo = max(ss.jo, l.jo+r.jo);
    ss.oo = max(l.oo, r.oo); 
    ss.oo = max(ss.oo, l.oj+r.oo);
    ss.oo = max(ss.oo, l.oo+r.jo);
    ss.oj = max(l.oj, r.oj);
    ss.oj = max(ss.oj, l.oj+r.oj);
    ss.oj = max(ss.oj, l.oo+r.jj);
	return ss;
}
inline void PushUP(int rt)
{
	node[rt] = Sum(node[rt<<1], node[rt<<1|1]);
}
void build(int l, int r, int rt)
{
	if(l==r)
	{
		LL x;
		scanf("%lld",&x);
		//cout << l << " " << x << endl;
		if(l&1)
		{
			node[rt].jj = x;
			node[rt].jo = -INF;
			node[rt].oj = -INF;
			node[rt].oo = -INF;
		}
		else
		{
			node[rt].oo = x;
			node[rt].jo = -INF;
			node[rt].oj = -INF;
			node[rt].jj = -INF;
		}
		return;
	}
	int m = (l+r)>>1;
	build(lson);build(rson);
	PushUP(rt);
} 
void update(int pos, LL val, int l, int r, int rt)
{
	if(l==r && l==pos) 
	{
		if(pos&1)
		{
			node[rt].jj = val;
			node[rt].jo = -INF;
			node[rt].oj = -INF;
			node[rt].oo = -INF;
		}
		else
		{
			node[rt].oo = val;
			node[rt].jo = -INF;
			node[rt].oj = -INF;
			node[rt].jj = -INF;
		}
		return;
	}
	int m = (l+r)>>1;
	if(pos <= m) update(pos,val,lson);
	else update(pos,val,rson);
	PushUP(rt);
}

Node query(int L, int R, int l, int r, int rt)
{
	//bug;
	if(L<=l && R>=r)
	{
		return node[rt];
	}
	int m = (l+r)>>1;
	if(R<=m) return query(L,R,lson);
	else if(L>m) return query(L,R,rson);
	else return Sum(query(L,R,lson),query(L,R,rson));
}

int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &T);
    while(T--)
    {
		scanf("%d%d", &n, &m);
		build(1,n,1);
		int a,b,op;
		while(m--)
		{
			scanf("%d", &op);
            if(op == 0)
            {
				int x,y;
                scanf("%d %d",&x, &y);
                if(n == 0)
                {
                    puts("0");continue;
                }
				LL sum;
                Node tmp = query(x, y, 1, n, 1);
                sum = max(tmp.jj, tmp.jo);
                sum = max(sum, tmp.oo);
                sum = max(sum, tmp.oj);
                printf("%lld\n", sum);
            }
            else 
            {
				int x;
				LL v;
                scanf("%d %lld", &x, &v);
                update(x, v, 1, n, 1);
            }
		}
    }
    //system("pause");
}

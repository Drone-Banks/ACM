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

#define MaxN 262144
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
int n;
double Lx[32767], Ly[32767], Rx[32767], Ry[32767];
struct Event
{
    double x, yl,yr;
    int val;
    Event(double a=0, double b=0, double c=0, int d=0):
    x(a), yl(b), yr(c), val(d) {} 
    bool operator<(const Event &a) const {
        return x < a.x;
    }
};

struct Node
{
    int L,R;
    double ll, rr, len;
    int cover;
    int mid(){return (L+R)/2;}
    Node (){}
    Node (int l, int r, double ll, double rr, double len, int cover):L(l),R(r),ll(ll),rr(rr),len(len),cover(cover){}
}tr[MaxN<<2];

struct Seg {
	double val[MaxN];      //线段树信息
	Node UP(Node rt, Node ls, Node rs)
	{
        if(rt.cover>0) return Node(rt.L, rt.R, rt.ll, rt.rr, rt.rr-rt.ll, rt.cover);
        else if(rt.L==rt.R) return Node(rt.L, rt.R, rt.ll, rt.rr, 0, rt.cover);
        else return Node(rt.L, rt.R, rt.ll, rt.rr, rs.len + ls.len, rt.cover);
	}
	void build(int rt, int L, int R)
	{
		tr[rt] = Node(L, R, val[L], val[R+1], 0, 0);
		if(L == R){
			return;
		}
		build(rt<<1, L, tr[rt].mid());
		build(rt<<1|1, tr[rt].mid()+1, R);
		tr[rt] = UP(tr[rt], tr[rt<<1], tr[rt<<1|1]);
	}
	void update(int rt, int l, int r, int val) //区间
	{
		if(l <= tr[rt].L && tr[rt].R <= r )
		{
            tr[rt].cover += val;
            tr[rt] = UP(tr[rt], tr[rt<<1], tr[rt<<1|1]);
			return;
		}
        if( r <= tr[rt].mid()) update(rt<<1, l, r, val);
        else if( l>tr[rt].mid()) update(rt<<1|1, l, r, val);
        else 
        {
            update(rt<<1, l, tr[rt].mid(), val);
            update(rt<<1|1, tr[rt].mid()+1, r,val);
        }
		tr[rt] = UP(tr[rt], tr[rt<<1], tr[rt<<1|1]); 
	}
	Node query(int rt, int L, int R)
	{
		if( L <= tr[rt].L && tr[rt].R <= R)
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

double solve()
{
    vector<Event> events;
    vector<double> Vy;
    map<double, int> M;
    for(int i=0;i<n;i++)
    {
        double x1,x2,y1,y2;
        x1 = Lx[i], x2 = Rx[i]; 
        y1 = Ly[i], y2 = Ry[i]; 
        events.push_back(Event(x1, y1, y2,  1));
        events.push_back(Event(x2, y1, y2, -1));
        Vy.push_back(y1), Vy.push_back(y2);
    }
    sort(events.begin(), events.end() );
    sort(Vy.begin(), Vy.end());
    Vy.resize(unique(Vy.begin(), Vy.end())-Vy.begin());
    for(int i=0;i<Vy.size();i++)
    {
        T.val[i] = Vy[i];
        M[Vy[i]] = i;
    }
    T.build(1,0,Vy.size()-2);
    double ans = 0, prex = 0;
    for(int i=0,j;i<events.size();)
    {
        if(i>0)
        {
            double tmp = T.query(1,0,Vy.size()-2).len;
            ans += tmp*(events[i].x-prex);
        }
        j = i;
        while (j < events.size() && events[j].x <= events[i].x) {
            T.update(1, M[events[j].yl], M[events[j].yr] - 1, events[j].val);
            j++;
        }
        prex = events[i].x;
        i = j;
    }
    return ans;
}

int main()
{
    //std::ios::sync_with_stdio(false);
    int t = 1;
    while(~scanf("%d", &n) && n )
    {
        for(int i=0;i<n;i++)
            scanf("%lf%lf%lf%lf", &Lx[i], &Ly[i], &Rx[i], &Ry[i]);
        printf("Test case #%d\n", t++);
        printf("Total explored area: %.2f\n", solve());
        puts("");
    }
    //system("pause");
}

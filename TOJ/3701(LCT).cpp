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
#define ALL(a) a.begin(), a.end()
using namespace std;

#define MaxN 30010
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

int n,A[MaxN]; //原树节点信息
struct Edge
{
    int u,v,w,next;
}edge[MaxM];
int cont, head[MaxM];
void add(int u, int v)
{
    edge[cont].u = u, edge[cont].v = v, edge[cont].next = head[u], head[u] = cont++;
}
int dep[MaxN], sz[MaxN], son[MaxN], fa[MaxN];
void DFS1(int u, int f, int d)    //求出重孩子
{
    dep[u] = d, fa[u] = f, sz[u] = 1;
    int mx = 0,loc=0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(v==f) continue;
        DFS1(v, u, d+1);
        if(sz[v]>mx)
        {
            mx = sz[v], loc = v;
        }
        sz[u] += sz[v];
    }
    son[u] = loc;
}
int dfn, tid[MaxN], top[MaxN];
void DFS2(int u, int rt)            //剖分
{
    tid[u] = ++dfn, top[u] = rt;
    if(tid[son[u]]==0) DFS2(son[u], rt);
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(tid[v]) continue;
        DFS2(v, v);
    }
}

struct Node
{
    int L,R,sum,mx;
    int mid(){return (L+R)/2;}
    Node (){}
    Node (int l, int r, int s, int mx):L(l),R(r),sum(s),mx(mx){}
}tr[MaxN<<2];

int val[MaxN];      //线段树信息
Node UP(Node rt, Node ls, Node rs)
{
    Node tmp = Node(ls.L, rs.R, ls.sum+rs.sum, max(ls.mx, rs.mx) );
    return tmp;
}
void build(int rt, int L, int R)
{
    tr[rt].L = L, tr[rt].R = R;
    if(L == R){
        tr[rt] = Node(L,R,val[L],val[R]);
        return;
    }
    build(rt<<1, L, tr[rt].mid());
    build(rt<<1|1, tr[rt].mid()+1, R);
    tr[rt] = UP(tr[rt], tr[rt<<1], tr[rt<<1|1]);
}
void update(int rt, int pos, int v)
{
    if( tr[rt].L == tr[rt].R && tr[rt].L == pos)
    {
        tr[rt].sum = tr[rt].mx = val[tr[rt].L] = v;
        return;
    }
    if( pos <= tr[rt].mid() ) update(rt<<1, pos, v);
    else update(rt<<1|1, pos, v);
    tr[rt] = UP(tr[rt], tr[rt<<1], tr[rt<<1|1]); 
}
Node query(int rt, int L, int R)
{
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
Node QQ(int u, int v)  //查询树上2个节点之间的信息
{
    Node ans = Node(0,0,0,-INF),tmp;
    while(top[u]!=top[v])
    {
        if( dep[top[u]] < dep[top[v]] ) swap(u,v);
        tmp = query(1,tid[top[u]], tid[u]);
        ans = UP(ans, ans, tmp);
        u = fa[top[u]];
    }
    if( tid[u] > tid[v] ) swap(u,v);
    tmp = query(1, tid[u], tid[v]);
    ans = UP(ans, ans, tmp);
    return ans;
}
void calulate()
{
    DFS1(1,-1,1); //标记信息
    dfn = 0;
    DFS2(1,1);   //剖分
    for(int i=1;i<=n;i++) val[tid[i]] = A[i];
    build(1,1,dfn); //建立线段树
}
void answer()
{
    int Q,a,b;
    scanf("%d", &Q);
    char str[10];
    while(Q--)
    {
        scanf("%s%d%d", &str, &a, &b);
        if(str[0] == 'Q')
        {
            if(str[1] == 'S') printf("%d\n", QQ(a,b).sum);
            else printf("%d\n", QQ(a,b).mx);
        }
        else update(1,tid[a],b);
    }
}
void solve()
{
    calulate();
    answer();
}
void init()
{
    cont = 0, MST(head,-1), CLR(tid);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &n))
    {
        init();
        int a,b;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d", &a, &b);
            add(a,b),add(b,a);
        }
        for(int i=1;i<=n;i++) scanf("%d", A+i);
        solve();
    }
    //system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
}

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

#define MaxN 1000010
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

int n,a[MaxN];
struct Node
{
    int L,R;
    int minV,maxV,minloc,maxloc;
    int mid(){return (L+R)/2;}
}node[MaxN*3];

void build(int root, int L, int R)
{
    node[root].L = L;
    node[root].R = R;
    node[root].minV = INF;
    node[root].maxV = -INF;
    if(L!=R)
    {
        build(2*root,L,(L+R)/2);
        build(2*root+1,(L+R)/2+1,R);
        if(node[root<<1].minV < node[root<<1|1].minV)
        {
            node[root].minV = node[root<<1].minV;
            node[root].minloc = node[root<<1].minloc;
        }
        else
        {
            node[root].minV = node[root<<1|1].minV;
            node[root].minloc = node[root<<1|1].minloc;
        }
        if(node[root<<1].maxV > node[root<<1|1].maxV)
        {
            node[root].maxV = node[root<<1].maxV;
            node[root].maxloc = node[root<<1].maxloc;
        }
        else
        {
            node[root].maxV = node[root<<1|1].maxV;
            node[root].maxloc = node[root<<1|1].maxloc;
        }
    }
    else
    {
        node[root].minV = node[root].maxV = a[node[root].L];
        node[root].minloc = node[root].maxloc = node[root].L;
    }
}
int minV,maxV,minL,maxL;
void query(int root, int s, int e) //查询区间[s,e]间最大值和最小值的差
{
    if(node[root].minV>=minV && node[root].maxV <= maxV) return;
    if(node[root].L==s && node[root].R == e) 
    {
        if(minV > node[root].minV)
        {
            minV = node[root].minV;
            minL = node[root].minloc; 
        }
        if(maxV < node[root].maxV)
        {
            maxV = node[root].maxV;
            maxL = node[root].maxloc; 
        }
        return;
    }
    if(e<=node[root].mid()) query(root*2,s,e);
    else if(s>node[root].mid()) query(root*2+1,s,e);
    else
    {
        query(root*2,s,node[root].mid());
        query(root*2+1,node[root].mid()+1,e);
    }
}
LL DFS(int l, int r)
{
    if(l>=r) return 0;
    int min_val, min_loc, max_val, max_loc;
    //debug(l) debug(r)
    minV = INF, maxV = 0;
    query(1,l,r);
    min_val = minV, min_loc = minL;
    max_val = maxV, max_loc = maxL;
    //debug(min_val) debug(min_loc)debug(max_val) debug(max_loc)
    int new_l = min(min_loc, max_loc), new_r = max(min_loc, max_loc);
    LL ans = (LL)abs(max_val-min_val)*(LL)(new_l-l+1)*(LL)(r-new_r+1);
    //debug(ans)debug(new_l) debug(new_r)
    ans+=DFS(l,new_r-1);
    ans+=DFS(new_l+1,r);
    ans-=DFS(new_l+1,new_r-1);
    return ans;
}

void solve()
{
    LL ans = DFS(1,n);
    printf("%lld\n", ans);
}


int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &n))
    {
        for(int i=1;i<=n;i++) 
        {
            scanf("%d", &a[i]);
        }
        build(1,1,n);
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

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
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}

int n,w,h;
struct Node
{
    int x,y,g;
    Node(int x=0, int y=0, int g=0):x(x),y(y),g(g){}
}node[MaxN],ans[MaxN];

vector<int> stat[MaxN<<1];
vector<int> xs,ys;

void solve()
{
    for(int i=0;i<=2E5;i++) stat[i].clear();
    for(int i=1;i<=n;i++) 
    {
        int tmp = node[i].x+node[i].y+1E5;
        stat[tmp].pb(i);
    }
    for(int s=0;s<=2E5;s++)
    {
        if(stat[s].size()==0) continue;
        xs.clear(),ys.clear();
        for(auto id : stat[s])
        {
            if(node[id].g==2) ys.pb(node[id].y);
            else xs.pb(node[id].x); 
        }

        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        sort(stat[s].begin(), stat[s].end(), [](int a, int b)
        {
            if( node[a].g != node[b].g) return (node[a].g==2);
            else return node[a].g==2? node[a].y>node[b].y : node[a].x<node[b].x;
        });
        for(int j=0;j<xs.size();j++)
        {
            ans[stat[s][j]] = Node(xs[j], h);
        }
        for(int j=0;j<ys.size();j++)
        {
            ans[stat[s][j+xs.size()]] = Node(w,ys[ys.size()-1-j]);
        }
    }
    for (int i = 1; i <= n; ++i) printf("%d %d\n", ans[i].x, ans[i].y);
}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d%d", &n, &w, &h))
    {
        int g,p,t;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d", &g, &p, &t);
            if(g==1) node[i] = Node(p,-t, g);
            else node[i] = Node(-t,p,g);
        }
        solve();
    }
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

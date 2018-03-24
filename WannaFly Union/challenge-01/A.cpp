/*************************************************************************
> File Name: test.cpp
> Author: Akira
> Mail: qaq.febr2.qaq@gmail.com
************************************************************************/
 
//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define pb emplace_back
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
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}
 
int n;
struct Edge{
    int v, next;
}edge[MaxM];
int cont, head[MaxN];
 
void add(int u, int v)
{
    edge[cont].v = v, edge[cont].next = head[u], head[u] = cont++;
}
LL odd[MaxN], even[MaxN], ans;
void DFS(int u, int pre)
{
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(v==pre) continue;
        DFS(v,u);
        LL O = even[v]+1, E = odd[v];
        ans += 1LL*odd[u]*O;
        ans += 1LL*even[u]*E;
        odd[u] += O;
        even[u] += E;
    }   
    ans += even[u];
}
void solve()
{
    ans = 0;
    DFS(1, 0);
    printf("%lld\n", ans);
}
void init(){
    cont = 0, MST(head, -1);CLR(odd),CLR(even);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &n))
    {
        init();
        int a, b;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d", &a, &b);
            add(a,b);add(b,a);
        }
        solve();
    }
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}
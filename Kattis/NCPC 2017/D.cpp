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

#define MaxN 1050005
#define MaxM MaxN*30
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}
int n,k;
char str[22];
typedef pair<int,int> pii;
struct cmp{
    bool operator()(pii a, pii b)
    {
        return a.first > b.first;
    }
};
struct Edge{
    int v,w,next;
}edge[MaxM];
int cont, head[MaxN];

inline void add(int u, int v){
    edge[cont].v = v, edge[cont].next = head[u], edge[cont].w = 1, head[u] = cont++;
}
int vis[MaxN], dis[MaxN];
vector<int> start,ans;
void Dijkstra()
{
    CLR(vis);
    for(int i=0;i<(1<<k);i++) dis[i] = INF;
    priority_queue<pii,vector<pii>,cmp> q;
    for(auto s : start)
    {
        dis[s] = 0;q.push(mp(0,s));
    }
    while(!q.empty())
    {
        pii tmp = q.top();
        q.pop();
        int w = tmp.first, u = tmp.second; 
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            if(dis[v] > w + edge[i].w)
            {
                dis[v] = w + edge[i].w;
                q.push(mp(dis[v],v));
            }
        }
    }
    int mx = 0,loc = 0;
    for(int i=0;i<(1<<k);i++){
        if(dis[i]>mx){
            mx = dis[i], loc = i;
        }
    }
    ans.clear();
    while(loc)
    {
        ans.pb(loc&1);
        loc>>=1;
    }
    for(int i=0;i+ans.size()<k;i++) printf("0");
    for(int i=ans.size()-1;i>=0;i--) printf("%d", ans[i]);
    puts("");
}

int inline cal(){
    int len = strlen(str),tmp = 0;
    for(int i=0;i<len;i++)
    {
        tmp = tmp*2+str[i]-'0';
    }
    return tmp;
}

void init()
{
    MST(head,-1);cont = 0;
    for(int i=0;i<(1<<k);i++)
    {
        for(int j=0;j<k;j++)
        {
            add( i, (i^(1<<j)) );
        }
    }
    start.clear();
    for(int i=1;i<=n;i++){
        scanf("%s",&str);
        start.pb(cal());
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &k))
    {
        init();
        Dijkstra();
    }
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

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

#define MaxN 600005
#define MaxM MaxN*5
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 998244353;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
inline int max2(int a, int b) {return ((a > b)? a : b);}
inline int min2(int a, int b) {return ((a < b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}
inline int min3(int a, int b, int c) {return min2(a, min2(b, c));}

int T,n;
struct Edge
{
    int u, v, next; LL w;
    Edge(){}
    Edge(int u, int v, LL w, int next):u(u),v(v),w(w),next(next){}
}edge[MaxM];
int cont, head[MaxN],du[MaxN];
void add(int u, int v, LL w)
{
    edge[cont] = Edge(u,v,w,head[u]); head[u]=cont++;
    edge[cont] = Edge(v,u,w,head[v]); head[v]=cont++;
    du[v]++;du[u]++;
}
bool vis[MaxN];
vector<LL> one,two;
void dfs(int u, int fa, int rt)
{
    vis[u] = true;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(v == fa) continue;
        if(v == rt)
        {
            if(u>n) one.push_back(edge[i].w);
            else two.push_back(edge[i].w);
            return ;
        }
        if(vis[v]) continue;
        if(u>n) one.push_back(edge[i].w);
        else two.push_back(edge[i].w);
        dfs(v,u,rt);
    }
}
LL cal(int u)
{
    one.clear(),two.clear();
    LL ans = 0;
    dfs(u,u,u);
    LL tmp = 1;
    for(int i=0;i<one.size();i++) tmp = (tmp*one[i])%mod;  
    ans += tmp;
    tmp = 1;
    for(int i=0;i<two.size();i++) tmp = (tmp*two[i])%mod;  
    ans += tmp;
    return ans;
}
void solve()
{
    memset(vis,0,(2*n+10)*sizeof(bool));
    LL ans = 1;
    queue<int> Q;;
    for(int u=1;u<=2*n;u++)  if(du[u]==1) Q.push(u);
    int u,v,cnt=0;
    while(!Q.empty())
    {
        u = Q.front();Q.pop();
        cnt++;
        for(int i=head[u];i!=-1;i=edge[i].next )
        {
            if(!vis[edge[i].v])
            {
                v = edge[i].v;
                ans = (ans * edge[i].w)%mod;
                break;
            }
        }
        vis[v] = vis[u] = true;
        for(int i=head[v];i!=-1;i=edge[i].next )
        {
            if(!vis[u = edge[i].v])
            {
                du[u]--;
                if(du[u]==1) Q.push(u);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            ans = (ans * cal(i))%mod;
        }
    }
    printf("%lld\n", ans%mod);
}
void init()
{
    cont = 0, memset(head,-1,(2*n+10)*sizeof(int)),memset(du,0,(2*n+10)*sizeof(int));
}
int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        init();
        int v1,v2;LL w1,w2;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%lld%d%lld", &v1, &w1, &v2, &w2);
            add(i,v1+n,w1), add(i,v2+n,w2);
        }
        solve();
    }
}

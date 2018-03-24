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

int n,m;
struct Edge
{
    int u,v,next;
}edge[MaxM];
int cont, head[MaxN],in[MaxN],ans[MaxN];
void solve()
{
    priority_queue<int> Q;
    for(int i=1;i<=n;i++) if(in[i]==0) Q.push(i);
    int cnt = n;
    while(!Q.empty())
    {
        int u = Q.top();
        ans[u] = cnt--;
        Q.pop();
        for(int i = head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            in[v]--;
            if(in[v]==0) Q.push(v);
        }
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d%c", ans[i], i==n?'\n':' ');
    }
}
void add(int u, int v)
{
    edge[cont].u = u, edge[cont].v = v, edge[cont].next = head[u], head[u] = cont++;
}
void init()
{
    cont = 0, MST(head,-1), CLR(in), CLR(ans);
}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &m))
    {
        init();
        int u,v;
        while(m--)
        {
            scanf("%d%d",&u,&v);
            add(v,u);
            in[u]++;
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

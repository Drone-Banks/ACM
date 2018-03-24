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

#define MaxN 10010
#define MaxM MaxN*20
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}

int n,m; 
struct Edge
{
    int u,v,next;
    Edge(){}
    Edge(int u, int v):u(u),v(v){}
}edge[MaxM];
int cont,head[MaxN];
void add(int u, int v)
{
    edge[cont].u = u, edge[cont].v = v, edge[cont].next = head[u], head[u] = cont++;
}

int dfn[MaxN],low[MaxN],index;
int ans1,ans2;
int cnt;
stack<Edge> st;
vector<int> bcc[MaxN];
int bccno[MaxN];
bool check[MaxN];
void Tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++index;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].v;
        if(v==fa) continue;
        if(!dfn[v])
        {
            st.push(Edge(u,v));
            Tarjan(v,u);
            if( low[v] < low[u]) low[u] = low[v];
            if(low[v] > dfn[u]) ++ans1;
            if(low[v] >= dfn[u])//如果这个点是割点，那么先前入栈的一些边是属于一个双连通分量的
            {
                
                Edge x;
                cnt++;
                for(;;)
                {
                    x = st.top();
                    st.pop();
                    if(bccno[x.u] != cnt)
                    {
                        bccno[x.u] = cnt;
                        bcc[cnt].push_back(x.u);
                    }
                    if(bccno[x.v] != cnt)
                    {
                        bccno[x.v] = cnt;
                        bcc[cnt].push_back(x.v);
                    }
                    if(x.u==u && x.v==v)
                        break;
                }
                int sum = 0;
                CLR(check);
                for(int i=0;i<bcc[cnt].size();i++) check[bcc[cnt][i]]=true;
                for(int i=0;i<bcc[cnt].size();i++)
                {
                    int node = bcc[cnt][i];
                    for(int j=head[node];j!=-1;j=edge[j].next)
                    {
                        int to = edge[j].v;
                        if(check[to]) sum++;
                    }
                }
                sum/=2;
                if(sum>bcc[cnt].size()) ans2+=sum;
            }
        }
        else if( dfn[v] < low[u] ) { st.push(Edge(u,v));low[u] = min(low[u],dfn[v]);}
    }
}
void solve()
{
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i]) Tarjan(i,i);
    }
    printf("%d %d\n", ans1, ans2);
}
void init()
{
    cont = 0;
    MST(head, -1);

    CLR(dfn);
    CLR(low);
    index = ans1 = ans2 = 0;

    cnt = 0;
    for(int i=0; i<=n; ++i)
    {
        bccno[i] = 0;
        bcc[i].clear();
    }  
}


int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &m) && (n+m))
    {
        init();
        while(m--)
        {
            int u,v;
            scanf("%d%d", &u, &v);
            add(u,v), add(v,u);
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

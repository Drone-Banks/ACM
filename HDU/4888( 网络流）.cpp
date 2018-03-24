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

#define MaxN 1000
#define MaxM 400000
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

int N, M, K, Row[MaxN], Col[MaxN];
const int NV = MaxN;
const int NE = MaxM;
 
struct ISAP {
    int n, size;
    int head[NV];
    int dis[NV], gap[NV], pre[NV], cur[NV];
    int maxflow;
 
    struct Edge {
        int v, w, next;
        Edge () {}
        Edge (int V, int NEXT, int W = 0) : v(V), next(NEXT), w(W) { }
    }E[NE];
 
    void init(int x) {
        n = x, size = 0;
        for (int i = 0; i <= n; i++) {
            head[i] = -1;
        }
    }
 
    inline void insert(int u, int v, int w = 0) {
        E[size] = Edge(v, head[u], w);
        head[u] = size++;
        E[size] = Edge(u, head[v], 0);
        head[v] = size++;
    }
 
    int MaxFlow(int src, int des) {
        maxflow = 0;
        gap[0] = n;
        for (int i = 0; i <= n; i++) {
            dis[i] = gap[i] = 0;
        }
        for (int i = 0; i <= n; i++) {
            cur[i] = head[i];
        }
        int u = pre[src] = src;
        int aug = -1;
        while (dis[src] < n) {//结束条件1
    loop: 
            for (int &i = cur[u]; i != -1; i = E[i].next) {
                int v = E[i].v;
                if (E[i].w && dis[u] == dis[v] + 1) {
                    aug = min(aug, E[i].w);
                    pre[v] = u;
                    u = v;
                    if (v == des) {//找到一条增广路，更新
                        maxflow += aug;
                        // //修改残余网络
                        for (u = pre[u]; v != src; v = u, u = pre[u]) {
                            E[cur[u]].w -= aug;//正向边
                            E[cur[u]^1].w += aug;//反向边
                        }
                        aug = INT_MAX;
                    }//if
                    goto loop;
                }//for
            }//for
            //寻找最小的距离标号，并修改当前点    为最小的标号+1
            int mdis = n;
            for (int i = head[u]; i != -1; i = E[i].next) {
                int v = E[i].v;
                if (E[i].w && mdis > dis[v]) {
                    cur[u] = i;
                    mdis = dis[v];
                }
            }//for
 
            //GAP 优化 断层则跳出 结束条件2
            if ((--gap[dis[u]]) == 0) {
                break;
            }
            gap[dis[u] = mdis + 1]++;//将拥有该标号的数量加1
            u = pre[u];//当前节点 迁移一个
        }//while
        return maxflow;
    }//ISAP
}G;
struct Edge
{
    int u, v, next;
}edge[MaxM];
int cont, head[MaxN];
void add(int u, int v)
{
    edge[cont].u = u, edge[cont].v = v, edge[cont].next = head[u], head[u] = cont++;
}
void init()
{
    cont = 0, MST(head, -1);
}
bool vis[MaxN];
bool dfs(int u,int fa)  
{  
    for(int i=G.head[u]; i!=-1; i=G.E[i].next)      
    {  
        if(i==(fa^1)) continue;  
        if(G.E[i].w)  
        {  
            if(vis[G.E[i].v]) return 1;  
            vis[G.E[i].v]=1;  
            if(dfs(edge[i].v,i)) return 1;  
            vis[G.E[i].v]=0;  
        }  
    }  
    return 0;  
}  
bool build()
{
    CLR(vis);
    for(int i=1;i<=N;i++)
    {
        if(dfs(i,-1)) return true;
    }
    return false;
}
vector<int> ans;
void solve()
{
    G.init(N+M+2);
    int S = 0, T = N+M+1, sum1 = 0, sum2 = 0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            G.insert(i,j+N,K);
        }
    }
    for(int i=1;i<=N;i++) G.insert(S, i, Row[i]), sum1 += Row[i];
    for(int j=1;j<=M;j++) G.insert(N+j, T, Col[j]), sum2 += Col[j];
    //debug(tmp) 
    if(sum2 != sum1) puts("Impossible");
    else 
    {
        int tmp = G.MaxFlow(S,T);
        if(tmp!=sum1) puts("Impossible");
        else if(build()) puts("Not Unique");
        else 
        {
            puts("Unique");
            for(int u=1;u<=N;u++)
            {
                bool flag = true;
                ans.clear();
                for(int i=G.head[u];i!=-1;i=G.E[i].next)
                {
                    int v = G.E[i].v;
                    if(v==0) continue;
                    int w = G.E[i].w;
                    ans.push_back(K-w);
                }
                for(int i=ans.size()-1;i>=0;i--)
                {
                    printf("%d%c", ans[i], i==0?'\n':' ');
                }
            }
        }
    } 
}
int main()
{
    while(~scanf("%d%d%d", &N, &M, &K))
    {
        for(int i=1;i<=N;i++) scanf("%d", Row+i);
        for(int i=1;i<=M;i++) scanf("%d", Col+i);
        solve();
    }
}

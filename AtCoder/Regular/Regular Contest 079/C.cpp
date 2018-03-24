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

#define MaxN 200005
#define MaxM MaxN*2
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
int N, M;
typedef pair<int,int> pii; 
struct Edge
{
    int u,v,w,next;
}edge[MaxM];
int cont;
int head[MaxN];
void add(int u, int v)
{
    edge[cont].u = u;
    edge[cont].v = v;
    edge[cont].w = 1;
    edge[cont].next = head[u];
    head[u] = cont++;
}
struct cmp
{                        //将优先队列改为小根堆
    bool operator()(pii a,pii b)
    {
        return a.first>b.first;
    }
};
int vis[MaxN];
int dis[MaxN];   //存储起点到每一个点的最短路

int Dijkstra(int s, int t)
{
    CLR(vis);
    for(int i=0;i<=N;i++) dis[i] = INF;
    dis[s] = 0;
    priority_queue<pii,vector<pii>,cmp> q;
    q.push(make_pair(0,s));
    while(!q.empty())
    {
        pii u = q.top();
        q.pop();
        if(vis[u.second]) continue;
        vis[u.second] = 1;
        for(int i=head[u.second];i!=-1;i=edge[i].next)
        {
            int to = edge[i].v;
            if(dis[to] > u.first + edge[i].w)
            {
                dis[to] = u.first + edge[i].w;
                q.push(make_pair(dis[to], to));
            }
        }
    }
    return dis[t];
}
void init()
{
    cont = 0;
    MST(head,-1);
}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &N, &M))
    {
        init();
        for(int i=0;i<M;i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            add(a,b);add(b,a);
        }
        int ans = Dijkstra(1,N);
        if(ans==2) puts("POSSIBLE");
        else puts("IMPOSSIBLE");
    }
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

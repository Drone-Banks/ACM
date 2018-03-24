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
#define ps push_back
using namespace std;

#define MaxN 200000
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

int n,k;
int P[110], C[110], L[110];
bool isPrime[MaxM];
int primes[MaxN],tot=0;
void prime()
{
    MST(isPrime, true);
    for(int i=2;i<=MaxN;i++)
    {
        if(isPrime[i]) primes[++tot] = i;
        for(int j=1;j<=tot;j++)
        {
            if(i*primes[j]>=MaxN) break;
            isPrime[i*primes[j]] = false;
            if(i%primes[j]==0) break;
        }
    }
}
struct Edge
{
    int u,v,w,next;
}edge[MaxM];
int cont, head[333];
void init()
{
    cont = 0,MST(head,-1);
}
void add(int u, int v, int w)
{
    edge[cont].u = u, edge[cont].v = v, edge[cont].w = w, edge[cont].next = head[u], head[u] = cont++;
}
int dis[MaxN];
int num[MaxN];
int cur[MaxN];
int pre[MaxN];

void BFS(int source,int sink)
{
    queue<int>q;
    CLR(num);
    MST(dis,-1);

    q.push(sink);
    dis[sink]=0;
    num[0]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            if(dis[v] == -1)
            {
                dis[v] = dis[u] + 1;
                num[dis[v]]++;
                q.push(v);
            }
        }
    }
}

int ISAP(int source,int sink,int n)      //从源点到汇点，n为总点数，返回最大流
{
    memcpy(cur,head,sizeof(cur));
    int flow=0, u = pre[source] = source;
    BFS( source,sink);
    while( dis[source] < n )
    {
        if(u == sink)
        {
            int df = INF, pos;
            for(int i =source;i != sink;i = edge[cur[i]].v)
            {
                if(df > edge[cur[i]].w)
                {
                    df = edge[cur[i]].w;
                    pos = i;
                }
            }
            for(int i = source;i != sink;i = edge[cur[i]].v)
            {
                edge[cur[i]].w -= df;
                edge[cur[i]^1].w += df;
            }
            flow += df;
            //cout << flow << endl;
            u = pos;
        }
        int st;
        for(st = cur[u];st != -1;st = edge[st].next)
        {
            if(dis[edge[st].v] + 1 == dis[u] && edge[st].w)
            {
                break;
            }
        }
        if(st != -1)
        {
            cur[u] = st;
            pre[edge[st].v] = u;
            u = edge[st].v;
        }
        else
        {
            if( (--num[dis[u]])==0 ) break;
            int mind = n;
            for(int id = head[u];id != -1;id = edge[id].next)
            {
                if(mind > dis[edge[id].v] && edge[id].w != 0)
                {
                    cur[u] = id;
                    mind = dis[edge[id].v];
                }
            }
            dis[u] = mind+1;
            num[dis[u]]++;
            if(u!=source)
            u = pre[u];
        }
    }
    return flow;
}
void solve()
{
    int l=1,r=n+1;
    while(l<=r)
    {
        int mid = (l+r)>>1;
        init();
        int S = 0, T = n+1;
        int sum = 0;
        int mx1 = 0,loc=-1;
        for(int i=1;i<=n;i++)
        {
            if(L[i]<=mid && C[i]==1 && P[i]>mx1) mx1 = P[i], loc = i; 
        }
        for(int i=1;i<=n;i++)
        {
            if(L[i]<=mid)
            {
                if(C[i]==1 && i!=loc) continue;
                sum += P[i];
                if(C[i]&1)
                {
                    add(S,i,P[i]);
                    add(i,S,0);
                    for(int j=1;j<=n;j++)
                    {
                        if(L[j]<=mid && (C[j]&1)==0 && isPrime[C[j]+C[i]]==true)
                        {
                            add(i,j,INF),add(j,i,0);
                        }
                    }
                }
                else add(i,T,P[i]),add(T,i,0);
            }
        }
        sum -= ISAP(S,T,n+2);
        if(sum>=k) r = mid-1;
        else l = mid+1;
    }
    printf("%d\n", l>n?-1:l);
}
int main()
{
    prime();
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &k))
    {
        for(int i=1;i<=n;i++) scanf("%d%d%d", P+i, C+i, L+i);
        solve();
    }
    //system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

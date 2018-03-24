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

#define MaxN 100001
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

int N;
struct Edge
{
    int u, v, w, next;
}edge[MaxM];
int cont, head[MaxN];
void add(int u, int v, int w)
{
    edge[cont].u = u, edge[cont].v = v, edge[cont].w = w, edge[cont].next = head[u], head[u] = cont++;
}
int DP[MaxN][4];
void DFS1(int u, int fa)
{
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(v==fa) continue;
        DFS1(v, u);
        int cnt = edge[i].w + DP[v][1];
        if( cnt > DP[u][1])
        {
            DP[u][0] = DP[u][1];
            DP[u][2] = DP[u][3];
            DP[u][1] = cnt;
            DP[u][3] = v;
        }
        else if( cnt == DP[u][1] || cnt > DP[u][0] )
        {
            DP[u][0] = cnt;
            DP[u][2] = v;
        }
    }
}
void DFS2(int u, int fa)
{
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if( v==fa ) continue;
        int w = edge[i].w;
        if( v == DP[u][3] )
        {
            if( DP[u][0] + w > DP[v][0] )
            {
                DP[v][0] = DP[u][0] + w;
                DP[v][2] = u;
                if( DP[v][0] > DP[v][1])
                {
                    swap(DP[v][0], DP[v][1]);
                    swap(DP[v][2], DP[v][3]);
                }
            }
        } 
        else
        {
            if( DP[u][1] + w > DP[v][0])
            {
                DP[v][0] = DP[u][1] + w;
                DP[v][2] = u;
                if( DP[v][0] > DP[v][1] )
                {
                    swap(DP[v][0], DP[v][1]);
                    swap(DP[v][2], DP[v][3]);
                }
            }
        }
        DFS2(v, u);
    }
}
void solve()
{
    CLR(DP);
    DFS1(1, 0);
    DFS2(1, 0);
    for(int i=1;i<=N;i++)
    {
        printf("%d\n", DP[i][1]);
    }

}
void init()
{
    cont = 0, MST(head, -1);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &N))
    {
        init();
        int v,w;
        for(int u=2;u<=N;u++)
        {
            scanf("%d%d", &v, &w);
            add(u,v,w), add(v,u,w);
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
}

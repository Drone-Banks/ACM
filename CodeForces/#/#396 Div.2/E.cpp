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
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}

int n,a[MaxN];
struct Edge
{
    int u,v,next;
}edge[MaxM];
int cont,head[MaxN];
void add(int u, int v)
{
    edge[cont].u = u, edge[cont].v = v, edge[cont].next = head[u], head[u] = cont++;
}

LL DP[MaxN][20][2],ans;
void DFS(int u, int pre)
{
    int pos = 0;
    LL val = a[u];
    for(int i = 0; i < 20; i++)
    if(val & (1 << i)) DP[u][i][1]++;
    else DP[u][i][0]++;   
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(v==pre) continue;
        DFS(v,u);
        for(int j=0;j<20;j++)
        {
            ans += (DP[u][j][1]*DP[v][j][0])*(1<<j);
            ans += (DP[u][j][0]*DP[v][j][1])*(1<<j);

            if( (val&(1<<j)) )
            {
                DP[u][j][1] += DP[v][j][0];
                DP[u][j][0] += DP[v][j][1];
            }
            else 
            {
                DP[u][j][0] += DP[v][j][0];
                DP[u][j][1] += DP[v][j][1];
            }
        }
    }
}

void init()
{
    cont = 0; MST(head,-1);CLR(DP);
}
int main()
{
    while(~scanf("%d", &n))
    {
        init();
        ans = 0;
        for(int i=1;i<=n;i++) scanf("%d", &a[i]), ans+=a[i];
        int u,v;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d", &u, &v);
            add(u,v);add(v,u);
        }
        DFS(1,1);
        out(ans); puts("");
    }
}

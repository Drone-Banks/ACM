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
inline int max2(int a, int b) {return ((a > b)? a : b);}
inline int min2(int a, int b) {return ((a < b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}
inline int min3(int a, int b, int c) {return min2(a, min2(b, c));}
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}

int n;
struct Edge
{
    int u,v,next;
}edge[MaxM];
int cont,head[MaxN],du[MaxN];
void add(int u, int v)
{
    edge[cont].u = u, edge[cont].v = v, edge[cont].next = head[u], head[u] = cont++;
}
int col[MaxN];
bool BFS(int x)
{
    col[x] = 1;
    queue<int> Q;
    Q.push(x);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            if(col[v] == col[u]) return false;
            else
            {
                if(col[v] == -1)
                {
                    col[v] = col[u]^1;
                    Q.push(v);
                }
            }
        }
    }
    return true;
}
bool judge()
{
    for(int i=1;i<=n;i++)
    {
        if(col[i]==-1 && !BFS(i))
            return false;
    }
    return true;
}
void init()
{
    cont = 0, MST(head,-1), CLR(du), MST(col,-1);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &n))
    {
        init();
        int u,v;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d", &u, &v);
            du[u]++, du[v]++;
            add(u,v);
            add(v,u);
        }
        judge();
        LL fuck = 0,ans = 0;
        for(int i=1;i<=n;i++) if(col[i]) fuck++;
        for(int i=1;i<=n;i++) if(!col[i]) ans+=fuck-du[i];
        printf("%lld\n", ans);
    }
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}
close
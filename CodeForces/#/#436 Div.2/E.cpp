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

int n;
struct Node
{
    int t,d,p,id;
}node[101];

int DP[101][2002];
bool choose[101][2002];

void out(int num, int tot, int id)
{
    if(num<0) printf("%d\n", id);
    else
    {
        if(!choose[num][tot]) out(num-1,tot,id);
        else
        {
            out(num-1, tot-node[num].t, id+1);
            printf("%d ", node[num].id);
        }
    }
}
void solve()
{
    sort(node+1,node+1+n,[](Node a, Node b){return a.d<b.d;});
    MST(DP,0x80);
    DP[0][0] = 0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=2000;j++)
        {
            DP[i][j] = DP[i-1][j];
            choose[i][j] = 0;
            if( j>=node[i].t && j<node[i].d)
                if( DP[i][j] < DP[i-1][j-node[i].t] + node[i].p)
                {
                    DP[i][j] = DP[i-1][j-node[i].t] + node[i].p;
                    choose[i][j] = 1;
                }
        }
    int ans = -1,tot = -1;
    for(int i=0;i<=2000;i++)
        if(DP[n][i] > ans) 
        {
            ans = DP[n][i];
            tot = i;
        }
    // for(int i=1;i<=2000;i++) ans = max(DP[i][n], ans);
    printf("%d\n", ans);
    out(n, tot ,0);
}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &n))
    {
        for(int i=1;i<=n;i++) scanf("%d%d%d", &node[i].t, &node[i].d, &node[i].p), node[i].id = i;
        solve();
    }
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

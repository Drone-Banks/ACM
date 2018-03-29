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
#define pb emplace_back
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

int N, M, K, A[105][105], dis[105][105];
bool leaf[105];
vector<int> Leaf;
int Fa[105];

void update(int son, int fa)
{
    // cout << son << " " << fa << endl;
    Fa[son] = fa;
    for(int i=1;i<=N;i++)
    {
        if(dis[son][i]>0){
            dis[fa][i] = dis[i][fa] = dis[son][i]-1;
        }
    }
    // for(int i=1;i<=N;i++)
    // for(int j=1;j<=N;j++)
    // printf("%d%c", dis[i][j], " \n"[j==N]);
}
void solve()
{
    for(int now=M;now>1;now--)
    {
        int uplen = A[now-1][0], nowlen = A[now][0];
        int i = 1, j = 1;
        while( i<=nowlen && j<=uplen)
        {
            int a = A[now][i], b = A[now-1][j];
            if(leaf[b]) {
                j++;
                continue;
            }
            update(a, b);
            while(++i<=nowlen && dis[a][A[now][i]] == 2) update(A[now][i], b);
            j++;
        }
    }
}

void init()
{
    Leaf.clear();
    CLR(leaf);
    CLR(Fa);
    CLR(dis);
}
int main()
{
    //std::ios::sync_with_stdio(false);1
    while(~scanf("%d%d%d",&N, &M, &K))
    {
        init();
        for(int i=1;i<=M;i++) scanf("%d", &A[i][0]);
        for(int i=1;i<=M;i++) {
            for(int j=1;j<=A[i][0];j++) {
                scanf("%d", &A[i][j]);
            }
        }
        int tmp;        
        for(int i=0;i<K;i++) {
            scanf("%d", &tmp);
            leaf[tmp] = true;
            Leaf.pb(tmp);
        }
        for(int i=0;i<K;i++)
        for(int j=0;j<K;j++)
        {
            scanf("%d", &tmp);
            dis[Leaf[i]][Leaf[j]] = tmp;
        }
        solve();
        for(int i=1;i<=N;i++)
        {
            printf("%d%c", Fa[i], " \n"[i==N]);
        }
    }
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

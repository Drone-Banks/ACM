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

int h,w,a[505][505],X,Y;
int dir[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
struct Node
{
    int x, y, low;
    Node(int x=0, int y=0, int low=0):x(x),y(y),low(low){}
    bool operator<(const Node &a ) const{
        return low>a.low;
    }
};
priority_queue<Node> Q;
int lost[505][505];
bool vis[505][505];
bool check(int x, int y)
{
    if( x>=1 && x<=h && y>=1 && y<=w && a[x][y]<0 && !vis[x][y]) return true;
    else return false;
}
void solve()
{
    while(!Q.empty()) Q.pop();
    Q.push(Node(X,Y,a[X][Y]));
    lost[X][Y] = -a[X][Y]; vis[X][Y] = true; 
    LL ans = -a[X][Y];
    while(!Q.empty())
    {
        Node tmp = Q.top();Q.pop();
        int x = tmp.x, y = tmp.y, low = tmp.low;
        for(int i=0;i<8;i++)
        {
            int xx = x + dir[i][0],
                yy = y + dir[i][1];
            if(check(xx, yy) )
            {
                int cost = -max(low, a[xx][yy]);
                if(cost<=lost[xx][yy]) continue;
                ans += cost-lost[xx][yy];
                lost[xx][yy] = cost;
                Q.push(Node(xx,yy,-cost));
                vis[xx][yy] = true;
            }
        }
    }
    printf("%lld\n", ans);
}
void init()
{
    CLR(lost);CLR(vis);
    for(int i=1;i<=h;i++)
    for(int j=1;j<=w;j++)
    {
        scanf("%d", &a[i][j]);
    }
    scanf("%d%d", &X, &Y);
}

int main()
{
    while(~scanf("%d%d", &h, &w))
    {
        init();
        solve();
    }
}
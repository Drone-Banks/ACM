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
using namespace std;

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
int n,m,k;
int MAP[666][666];
char str[666];
bool vis[666][666];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int num;
bool check(int x, int y)
{
    if(x<0||y<0||x>=n||y>=m||MAP[x][y]>=num) return false;
    else return true;
}

int BFS()
{
    CLR(vis);
    queue< pair< pair<int,int>, int> > Q;
    Q.push(make_pair(make_pair(0,0),0));
    vis[0][0] = 1;
    bool flag = false;
    int ans = -1;
    while(!Q.empty())
    {
        pair< pair<int,int>, int> tmp = Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            int x = tmp.first.first + dir[i][0];
            int y = tmp.first.second + dir[i][1];
            if(check(x,y)&&!vis[x][y])
            {
                if(x==n-1&&y==m-1)
                {
                    ans = tmp.second+1;
                    flag = true;
                    break;
                }
                vis[x][y] = 1;
                Q.push(make_pair(make_pair(x,y),tmp.second+1));
            }
        }
        if(flag) break;
    }
    return ans;
}

void solve()
{
    num = 1;
    int she = BFS();
    num = 2;
    int me = BFS();
    //cout << me << " " << she << endl;
    if(me == -1 || (she!=-1 && me>=she-5) ) puts("NO");
    else puts("YES");
}
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d%d%d", &n, &m, &k);
    for(int i=0;i<n;i++)
    {
        scanf("%s", str);
        for(int j=0;j<m;j++)
        {
            if(str[j]=='.') MAP[i][j] = 0;
            else MAP[i][j] = 2;
        }
    }
    int a,b;
    while(k--)
    {
        scanf("%d%d", &a, &b);MAP[a][b] = 1;
    }
    solve();
    system("pause");
}

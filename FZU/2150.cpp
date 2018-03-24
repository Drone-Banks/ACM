/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
#include <climits>
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

int T, n, m; 
char Map[12][12];
int vis[12][12];
struct Node
{
    int x, y, step;
    Node(){}
    Node(int x, int y, int step): x(x), y(y), step(step) {}
};
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
bool check(int x, int y)
{
    if(x<0 || y<0 || x==n || y==m || Map[x][y]=='.' || vis[x][y]) return false;
    else return true;
}
int BFS(Node n1, Node n2)
{
    int ans = 0;
    CLR(vis);
    vis[n1.x][n1.y] = 1;
    vis[n2.x][n2.y] = 1;
    queue<Node> Q;
    Q.push(n1);
    Q.push(n2);
    while(!Q.empty())
    {
        Node tmp = Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            int x = tmp.x + dir[i][0];
            int y = tmp.y + dir[i][1];
            if( check(x, y) ) 
            {
                vis[x][y] = 1;
                Q.push(Node(x,y,tmp.step+1));
                ans = max(ans, tmp.step+1);
            }
        }
    }
    bool flag = true;
    for(int i=0;i<n && flag;i++)
    {
        for(int j=0;j<m && flag;j++)
        {
            if(Map[i][j]=='#' && !vis[i][j]) flag = false;
        }
    }
    if(flag) return ans;
    else return INF;
}

int use[12][12];
void solve(int t)
{
    int ans = INF;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(Map[i][j]=='.') continue;
            Node n1 = Node(i, j, 0);
            for(int ii=0;ii<n;ii++)
            {
                for(int jj=0;jj<m;jj++)
                {
                    if(Map[ii][jj]=='.' ) continue;
                    Node n2 = Node(ii, jj, 0);
                    int tmp = BFS(n1, n2);
                    ans = min(ans, tmp);
                }
            }
        }
    }
    if(ans == INF) ans = -1;
    printf("Case %d: %d\n", t, ans);
}

int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d", &n, &m);
        for(int i=0;i<n;i++) scanf("%s", Map[i]);
        solve(t);
    }
    //system("pause");
}

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
template<typename T> T abs(T val){return val>0?val:-val;}

int w,h;

char Map[22][22];
bool vis[22][22];
struct Node{
    int x,y;
    Node(){}
    Node(int x, int y):x(x),y(y){}
}S;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool check(int x, int y)
{
    if( x<1 || x>w || y<1 || y>h || Map[y][x]=='#' || vis[y][x]) return false;
    else return true;
}
void solve()
{
    for(int i=1;i<=h;i++)
    for(int j=1;j<=w;j++)
    {
        if(Map[i][j]=='@')
        {
            S.x = j, S.y = i;
        }
    }
    CLR(vis);
    int ans = 0;
    queue<Node> Q;
    vis[S.y][S.x] = true;
    Q.push(S);
    while(!Q.empty())
    {
        Node tmp = Q.front();
        Q.pop();
        ans++;
        for(int i=0;i<4;i++)
        {
            int x = tmp.x+dir[i][0];
            int y = tmp.y+dir[i][1];
            if(check(x,y))
            {
                vis[y][x] = true;
                Q.push(Node(x,y));
            }
        }
    }
    printf("%d\n", ans);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(scanf("%d%d", &w, &h)&&(w+h))
    {
        for(int i=1;i<=h;i++) scanf("%s", Map[i]+1);
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

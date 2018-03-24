/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
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

#define MaxN 100000
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

template<typename _> inline void scan(_& t)
{
    int c;
    while((c = getchar()) < '0' || c > '9');
    t = c - '0';
    while((c = getchar()) >= '0' && c <= '9') t = t * 10 + c - '0';
}
template<typename _> inline void print(_ x)
{
    int len = 0, p[20];
    if(x < 0) putchar('-'), x = -x;
    while(x) p[++len] = x % 10, x /= 10;
    if(!len) p[++len] = 0;
    while(len) putchar(p[len--] + '0');
}

int T;
int N,M;
char Map[41][41];
int id[41][41];
int Num;
vector<int> V[1700];
set<int> S[1700];
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
bool check(int x, int y)
{
    if(x<0||x>=N||y<0||y>=M) return false;
    else return true;
}
void DFS(int x, int y)
{
    id[x][y] = Num;
    for(int i=0;i<4;i++)
    {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if(check(xx,yy))
        {
            if( Map[xx][yy] == Map[x][y] && id[xx][yy]==0)
            {  
                DFS(xx,yy);
            }
            else if( Map[xx][yy] != Map[x][y] && id[xx][yy]!=0)
            {
                int t = id[xx][yy];
                if (!S[Num].count(t))
                {
                    S[Num].insert(t);
                    V[t].push_back(Num);
                    V[Num].push_back(t);
                }
            }
        }
    }
}
int vis[1700];
int BFS(int s)
{
    CLR(vis);
    vis[s] = 1;
    queue<int> Q;
    queue<int> D;
    Q.push(s);
    D.push(0);
    int ans = 0;
    while(!Q.empty())
    {
        int tmp = Q.front();Q.pop();
        int d = D.front();D.pop();
        ans = MAX(ans, d);
        for(int i=0;i<V[tmp].size();i++)
        {
            int v = V[tmp][i];
            if(!vis[v])
            {
                vis[v] = 1;
                Q.push(v);
                D.push(d+1);
            }
        }
    }
    return ans;
}

void init()
{
    CLR(id);
    Num = 0;
}
int main()
{
    scanf("%d", &T);
    while(T--)
    {
        init();
        scanf("%d%d", &N, &M);
        for(int i=0;i<N;i++)
        {
            scanf("%s", Map[i]);
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(!id[i][j])
                {
                    id[i][j] = ++Num;
                    V[Num].clear();
                    S[Num].clear();
                    DFS(i,j);
                }
            }
        }
        int ans = INF;
        for(int i=1;i<=Num;i++)
        {
            int tmp = BFS(i);
            ans = MIN(ans, tmp);
        }
        printf("%d\n", ans);
    }
    //system("pause");
}
/*

1345
2 2
OX
OX
3 3
XOX
OXO
XOX

*/
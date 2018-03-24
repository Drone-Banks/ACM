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
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
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
int dir[8][2] = {{-1,-1}, {0,-1}, {1,-1}, {-1,0}, {1,0}, {-1,1}, {0,1}, {1,1}};
int n,m;
int Map[110][110];
int vis[110][110];
bool Invalid(int x, int y)
{   
    if( x<1 || x>n ) return true;
    if( y<1 || y>m ) return true;
    if( vis[x][y]>0) return true;
    return false;
}
int cnt;
void check(int i, int j)
{
    if(vis[i][j] == -1) vis[i][j] = ++cnt;

    for(int k=0;k<8;k++)
    {
        int x = i + dir[k][0];
        int y = j + dir[k][1];
        if( Invalid(x,y)) continue;
        if(Map[x][y] == 1)
        {
            vis[x][y] = vis[i][j];
            check(x,y);
            //cout << i <<"," <<j << ": " << x << "-" << y << endl;
        }
    }
}

void Find()
{
    cnt = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(Map[i][j] && vis[i][j]==-1 )
                check(i, j);
        }
    }
}

int main()
{
    while(~scanf("%d%d", &n, &m) && m)
    {
        MST(vis,-1);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char ch;
                cin >> ch;
                if(ch == '*') Map[i][j] = 0;
                else Map[i][j] = 1;
            }
        }

        Find();
        cout << cnt << endl;
    }
    //system("pause");
}
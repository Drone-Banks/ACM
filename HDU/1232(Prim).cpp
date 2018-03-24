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

#define MaxN 233
#define MaxM MaxN*10
#define INF 1000000000
#define bug cout<<88888888<<endl;

int N, M;
int Map[MaxN][MaxN];
int low[MaxN];
int vis[MaxN]; // 表示该点是否已经加入最小生成树中
int n;
  
int Prim() 
{
    n = N;      //n赋值为图中点数
    for (int i=1; i<=n; ++i) 
    {
        low[i] = Map[1][i];
    }
  
    int ans = 0;                              
    CLR(vis);
    vis[1] = 1;
  
    for (int i=2; i<=n; ++i) 
    { // 循环n-1次，找剩下的n-1个点。
        int k = -1, mindis = INF;
        for (int j=1; j<=n; ++j) 
        { // 循环找当前剩下的点中 距离最小生成树点集距离最短的点。
            if (!vis[j] && low[j] < mindis) 
            {
                mindis = low[j];
                k = j;
            }
        }
  
         if (k == -1) return -1;
         vis[k] = 1; // 加入最小生成树点集
         ans += mindis;
  
         for (int j=1; j<=n; ++j) 
         { 
            if (!vis[j] && low[j] > Map[k][j]) 
            { // 上面的if是错的。low数组存储的距离是当前点到生成树中所有点距离最小的的点。
                low[j] = Map[k][j]; // 因为这个点加入最小生成树集合中，可以和其中任意一个点连一条边。
            }
        }
    }
    return ans;
}

int main()
{
    while(cin >> N && N)
    {
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                Map[i][j] = INF;
        M = N*(N-1)/2;
        int a, b, c;
        for(int i=0;i<M;i++)
        {
            cin >> a >> b >> c; 
            Map[a][b] = Map[b][a] = c;
        }
        cout << Prim() << endl;
    }
    system("pause");
}
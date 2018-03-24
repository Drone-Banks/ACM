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

#define MaxN 303
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)


int N,M;
int dis[MaxN][MaxN];  //dis[i][j]存储i到j的最短路
int num[MaxN][MaxN];

void Floyd()
{
    int n = N;    //n赋值为图中的点数
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dis[i][j]>dis[i][k]+dis[k][j])
                {
                    dis[i][j]=dis[i][k]+dis[k][j];
                    num[i][j]=num[i][k]+num[k][j];
                }
                    
}

int main()
{
    scanf("%d%d", &N, &M);
    MST(num,1);
    int a,b;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d", &a, &b, &dis[a][b], &dis[b][a]);
        cin >> dis[a][b] >> dis[b][a];
    }
    Floyd();
    int ans = INF;
    for(int i=1;i<=N;i++)
    {
        cout << dis[i][i] << endl;
        if(dis[i][i]>0) ans = MIN(ans, num[i][i]);
    }
    cout << ans << endl;
    system("pause");
}
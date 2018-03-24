
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

#define MaxN 101
#define MaxM MaxN*10
#define INF 1000000000
#define bug cout<<88888888<<endl;

int N;
int n; //总点数
int dis[MaxN][MaxN];  //dis[i][j]存储i到j的最短路


void Floyd()
{
    n = N;    //n赋值为图中的点数
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dis[i][j]>dis[i][k]+dis[k][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
}

void init()
{
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            dis[i][j] = INF;
}

int main()
{
    while( cin>>N && N )
    {
        init();
        int num;
        int a,b;
        for(int i=1;i<=N;i++)
        {
            cin >> num;
            for(int j=0;j<num;j++)
            {
                cin >> a >> b;
                dis[i][a] = b;
            }
        }
        Floyd();
        int ans = INF;
        int flag = 0;
        for(int i=1;i<=N;i++)
        {
            int tmp = 0;
            for(int j=1;j<=N;j++)
            {
                if(i == j) continue;
                
                tmp = tmp > dis[i][j] ? tmp : dis[i][j];
            }
            if(ans > tmp)
            {
                flag = i;
                ans = tmp;
            }
            
        }
        cout <<flag << " "<< ans << endl;
    }
    system("pause");
}
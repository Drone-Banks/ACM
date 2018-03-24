/*************************************************************************
	> File Name: 1055.cpp
	> Author: Akira 
	> Mail: qaq.febr2.qaq@gmail.com 
	> Created Time: 2016年10月07日 星期五 14时21分56秒
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

#define MaxN 110
#define MaxM MaxN*2
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

int N, M;
int dp[MaxN][MaxN];

struct Edge
{
    int u,v;
    int next;
}edge[MaxM];
int head[MaxN];
int cont;

void init()
{
    CLR(dp);
    MST(head, -1);
    cont = 0;
}

void add(int u, int v)
{
    edge[cont].v = v;
    edge[cont].next = head[u];
    head[u] = cont++;
}

int dfs(int u, int m)
{
    int sons = 1;
    int num;

    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].v;
        num = dfs(v, m-1);
        for(int j=m;j>=1;j--)
        {
            for(int k=1; k<=num && k<j; k++)
            {
                dp[u][j] = MAX( dp[u][j], dp[v][k]+dp[u][j-k] );
            }
        }
        sons += num;
    }
    return sons;
}

int main()
{
    while(~scanf("%d%d", &N, &M))
    {
        init();
        for(int i=1;i<=N;i++)
        {
            scanf("%d", &dp[i][1]);
        }
        int a, b;
        for(int i=1;i<N;i++)
        {
            scanf("%d%d", &a, &b);
            add(a, b);
        }
        dfs(1, M);
        cout << dp[1][M] << endl;
    }
}

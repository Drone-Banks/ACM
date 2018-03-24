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
const LL INF = LL(1e18);
#define bug cout<<88888888<<endl;


int n,m,k; 
int tree[110];
LL ans;

LL cost[110][110];

LL DP[110][110][110]; //用第i种颜色涂第j颗树，beauty为k的花费




LL solve()
{
    ans = INF;
    if(tree[1]!=0)
    {
        DP[tree[1]][1][1] = 0;
    }
    else
    {
        for(int i=1;i<=m;i++)
        {
            DP[i][1][1] = cost[1][i];
        }
    }
    for(int i = 2; i <= n; i++)
	{
		for(int j = 1; j <= k; j++)
		{
			if(tree[i] == 0)
			{
				for(int a = 1; a <= m; a++)
				{
                    DP[a][i][j] = min(DP[a][i][j], DP[a][i-1][j] + cost[i][a]);
					for(int b = 1; b <= m; b++)
					{
						if(b != a) DP[a][i][j] = min(DP[a][i][j], DP[b][i-1][j-1] + cost[i][a]);
					}
				}
			}
			else
			{
				DP[tree[i]][i][j] = min(DP[tree[i]][i][j], DP[tree[i]][i-1][j]);
				for(int b = 1; b <= m; b++)
				{
					if(b != tree[i]) DP[tree[i]][i][j] = min(DP[tree[i]][i][j], DP[b][i-1][j-1]);
				}
			}
		}
	}
    for(int i = 1; i <= m; i++)
	{
		ans = min(ans, DP[i][n][k]);
	}
    if(ans >= INF) return -1;
    else return ans;
}

int main()
{
    while( ~scanf("%d%d%d", &n, &m, &k))
    {
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
                for(int l=0;l<=k;l++)
                    DP[i][j][l] = INF;

        for(int i=1;i<=n;i++)
            scanf("%d", &tree[i]);

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%lld", &cost[i][j]);
            }
        }

        cout << solve() << endl;
    }

    //system("pause");
}
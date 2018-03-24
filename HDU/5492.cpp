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

#define MaxN 35
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
int T;
int N,M;
int Map[MaxN][MaxN];
int DP[MaxN][MaxN][1800];
int solve()
{
    MST(DP,INF);
    DP[1][1][Map[1][1]]=Sqr(Map[1][1]);
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(i+1<=N)
            {
                for(int k=0;k<=59*30;k++)
                    if(DP[i][j][k]!=INF)
                        DP[i+1][j][k+Map[i+1][j]]=min(DP[i+1][j][k+Map[i+1][j]], DP[i][j][k]+Map[i+1][j]*Map[i+1][j]);
            }
            if(j+1<=M)
            {
                for(int k=0;k<=59*30;k++)
                    if(DP[i][j][k]!=INF)
                        DP[i][j+1][k+Map[i][j+1]]=min(DP[i][j+1][k+Map[i][j+1]], DP[i][j][k]+Map[i][j+1]*Map[i][j+1]);
            }
        }
    }
    int ans = INF;
    for(int k=0;k<=59*30;k++)
    {
        if(DP[N][M][k]!=INF) ans = min(ans,(N+M-1)*DP[N][M][k]-Sqr(k));
    }
    return ans;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d", &N, &M);
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                scanf("%d", &Map[i][j]);
            }
        }
        printf("Case #%d: %d\n",t,solve());
    }
    //system("pause");
}

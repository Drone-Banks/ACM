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

#define MaxN 105
#define MaxM MaxN*10
#define INF 0x3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
int BigBang = 1000000;
int N,M,T,S,E;
int cost[MaxN],value[MaxN];
int MAP[MaxN][MaxN];
struct Scen 
{
	int id;
}ss[MaxN];
void Floyd()
{
    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                MAP[i][j] = min(MAP[i][j], MAP[i][k]+MAP[k][j]);
}
int DP[MaxN][3*MaxN];
int Begin;
int End;
int len;
void solve(int t)
{	
	//debug(MAP[S][E]);
	MST(DP,-1);
	DP[Begin][0] = 0;
	for(int i=0;i<len;i++)
	{
		int u = ss[i].id;
		for(int j=0;j<=T;j++)
		{
			if(DP[u][j]!=-1)
			{
				for(int k=i+1;k<len;k++)
				{
					int v = ss[k].id;
					int c = cost[v]+MAP[u][v];
					if(value[v]>value[u] && j+c<=T)
					{
						DP[v][j+c] = max(DP[v][j+c], DP[u][j]+value[v]);
					}
				}
			}
		}
	}
	int ans = BigBang;
	for(int j=0;j<=T;j++) ans = max(ans, DP[End][j]); 
	ans -= BigBang;
	printf("Case #%d:\n%d\n", t, ans);
}
int main()
{
    //std::ios::sync_with_stdio(false);
	int W;
	scanf("%d", &W);
	for(int t=1;t<=W;t++)
	{
		MST(MAP,INF);
		scanf("%d%d%d%d%d", &N, &M, &T, &S, &E);
		len = 0;
		Begin = N+1, End = N;
		cost[Begin] = cost[End] = 0, value[Begin] = -1, value[End] = BigBang;
		ss[len++].id = Begin,ss[len++].id = End;
		for(int i=0;i<N;i++) scanf("%d", &cost[i]);
		for(int i=0;i<N;i++) 
		{
			scanf("%d", &value[i]);
			ss[len++].id = i;
		}
		
		sort(ss,ss+len,[](Scen a, Scen b){return value[a.id]<value[b.id];});
		int u,v,L;
		while(M--)
		{
			scanf("%d%d%d", &u, &v, &L);
			MAP[u][v] = MAP[v][u] = min(L, MAP[u][v]);
		}
		Floyd();
		for(int i=0;i<N;i++)
		{
			MAP[Begin][i] = MAP[S][i];
			MAP[i][End] = MAP[i][E];
		}
		MAP[Begin][End] = MAP[S][E];
		MAP[Begin][S] = MAP[E][End] = 0;
		solve(t);
	}
    //system("pause");
}

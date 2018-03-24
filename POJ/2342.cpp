#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

#define N 6666
int dp[N][2], val[N], visit[N];
int fa[N];
struct node
{
	int v;
	int next;
}People[N<<1];

int e, head[N];
void init ()
{
	memset  (head, -1, sizeof (head));
	e = 1;
}
void ADD (int u, int v)
{
	People[e].v = v;
	People[e].next = head[u];
	head[u] = e ++;
}
int DFS (int u)
{
	visit[u] = 1;
	dp[u][0] = 0;
	dp[u][1] = val[u];
	for (int i = head[u]; i != -1; i = People[i].next)
	{
		int v = People[i].v;
		DFS(v);
		dp[u][0] += max(dp[v][0],  dp[v][1]);
		dp[u][1] += dp[v][0];
	}
	return max(dp[u][0], dp[u][1]);
}

int main()
{
	int n, v, u;
	while (scanf ("%d", &n) != EOF)
	{
		init();
		for (int i = 1; i <= n; ++i)
		{
			fa[i] = 0;
			visit[i] = 0;
			scanf ("%d", &val[i]);
		}
		while (scanf ("%d%d", &v, &u) && v + u != 0)
		{
			ADD (u, v);
			fa[v]++;
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			if(!fa[i])
				ans += DFS(i);
		}
		//for(int i=0;i<=e;i++)
		//	cout << i << ":" << head[i] << "---" <<People[head[i]].next<< endl;
		printf("%d\n", ans);
	}
	return 0;
}
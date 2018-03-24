/*************************************************************************
> File Name: test.cpp
> Author: Akira
> Mail: qaq.febr2.qaq@gmail.com
************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<vector>
#include<cstring>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 100010
#define MaxM MaxN*20
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9 + 7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x;
int N, M;
struct Edge
{
	int u, v, next;
}edge[MaxM];
int cont;
int head[MaxN];
int vis[MaxN];
int col[MaxN];
void add(int u, int v)
{
	edge[cont].u = u;
	edge[cont].v = v;
	edge[cont].next = head[u];
	head[u] = cont++;
}
void Add(int u, int v) { add(u, v); add(v, u); }
void init()
{
	cont = 0;
	MST(head, -1);
	CLR(vis);
}
int main()
{
	//std::ios::sync_with_stdio(false);
	while (~scanf("%d%d", &N, &M))
	{
		init();
		while (M--)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			Add(u, v);
		}
		LL I = 0, Q = 0, P = 0;
		for (int i = 1; i<=N; i++)
		{
			if(!vis[i]) 
			{
				bool flag = true;
				queue<int> q;
				vector<int> V;
				q.push(i);
				V.push_back(i);
				vis[i] = 1;
				col[i] = 0;
				while(!q.empty())
				{
					int u = q.front();
					q.pop();
					for(int j=head[u];j!=-1;j=edge[j].next)
					{
						int v = edge[j].v;
						if(!vis[v])
						{
							vis[v] = 1;
							q.push(v);
							V.push_back(v);
							col[v] = col[u] + 1;
						}
						else
						{
							if( (col[v]-col[u])%2 == 0) flag = false;
						}
					}
				}				

				if (V.size() == 1) I++;
				else
				{
					if (flag) Q++;
					else P++;
				}
			}
		}
		//cout << I << " " << Q << " " << P << endl;
		LL ans = 2*I*N - I*I + P*P + 2 * P*Q + 2*Q*Q;
		printf("%lld\n", ans);
	}
	//system("pause");
}

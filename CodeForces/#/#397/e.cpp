#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct node {
	node *next;
	int where;
} a[1000001], *first[200001];
int n, l, f[1000001], dist[1000001], c[1000001], fa[1000001], g[1000001], T[1000001];
vector<int> shy[1000001];
map<int, int> C;

inline void makelist(int x, int y) {
	a[++l].where = y;
	a[l].next = first[x];
	first[x] = &a[l];
}

int calc(int now) {
	for (; now && now & 1; now = (now + 1) / 2);
	return now;
}

int main() {
	//freopen("e.in", "r", stdin);
	//freopen("e.out", "w", stdout);
	scanf("%d", &n);
	memset(first, 0, sizeof(first));
	l = 0;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		makelist(x, y);
		makelist(y, x);
	}
	memset(dist, 0, sizeof(dist));
	c[1] = 1; dist[1] = 1;
	for (int k = 1, l = 1; l <= k; l++)
	{
		int m = c[l];
		for (node *x = first[m]; x; x = x->next)
			if (!dist[x->where])
				dist[x->where] = dist[m] + 1,
				c[++k] = x->where;
	}
	for (int i = n; i; --i)
	{
		int m = c[i], cnt = 0;
		shy[m].clear();
		bool ok = true;
		for (node *x = first[m]; x; x = x->next)
			if (dist[x->where] == dist[m] + 1)
				if (f[x->where] != -1)
					shy[m].push_back(f[x->where] + 1); 
				else
				{
					ok = false;
					shy[m].push_back(-1);
				}
		if (ok == false)
			f[m] = -1;
		else
		if (shy[m].empty())
			f[m] = 1;
		else
		{
			sort(shy[m].begin(), shy[m].end());
			if (shy[m][0] == shy[m][shy[m].size() - 1])
				f[m] = shy[m][0];
			else
				f[m] = -1;
		}
		/*printf("%d %d\n", m, f[m]);
		for (int i = 0; i < shy[m].size(); i++)
			printf("%d ", shy[m][i]);
		printf("\n");*/
	}
	memset(g, 0, sizeof(g));
	int ans = 1 << 30;
	for (int j = 1; j <= n; j++)
	{
		int m = c[j];
		sort(shy[m].begin(), shy[m].end());
		/*printf("%d\n", m);
		for (int i = 0; i < shy[m].size(); i++)
			printf("%d ", shy[m][i]);
		printf("\n");*/
		int cnt = 0;
		for (int i = 0; i < shy[m].size(); ++i)
			if (!i || shy[m][i] != shy[m][i - 1])
				++cnt;
		if (shy[m][0] != -1) 
			if (cnt == 1)
			{
				ans = min(ans, calc(shy[m][0]));
			}
			else
				if (cnt == 2)
					ans = min(ans, calc(shy[m][0] + shy[m][shy[m].size() - 1] - 1));
		C.clear();
		for (int i = 0; i < shy[m].size(); i++)
			C[shy[m][i]]++;
			
		for (node *x = first[m]; x; x = x->next)
			if (dist[x->where] == dist[m] + 1)
			{
				//printf("! %d %d\n", x->where, f[x->where]);
				if (f[x->where] == -1)
				{
					if (!(--C[f[x->where]]))
						C.erase(f[x->where]); 
				}
				else
				if (!(--C[f[x->where] + 1]))
					C.erase(f[x->where] + 1); 
				if (C.empty())
					shy[x->where].push_back(2);
				else
					if (C.size() == 1 && C.begin()->first != -1)
						shy[x->where].push_back(C.begin()->first + 1);
				else
					shy[x->where].push_back(-1);
				if (f[x->where] == -1)
				{
					++C[f[x->where]];
				}
				else
					++C[f[x->where] + 1];
			}
	}
	if (ans == 1 << 30)
		printf("-1\n");
	else
		printf("%d\n", ans - 1);
}


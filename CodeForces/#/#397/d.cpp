#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n, a[100001], g[100001], h[100001], m;
set<int> events[100001];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		events[i].clear();
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]),
		events[a[i]].insert(i);
	m = 0;
	bool ok = true;
	for (int i = 1; i <= n; ++i)
		if (!events[i].empty())
			if (events[i].find(i) == events[i].end())
			{
				ok = false;
				break;
			}
	if (!ok)
	{
		printf("-1\n");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		if (!events[i].empty())
		{
			h[++m] = i;
			for (set<int>::iterator itr = events[i].begin(); itr != events[i].end(); ++itr)
				g[*itr] = m;
		}
	printf("%d\n", m);
	for (int i = 1; i <= n; i++)
		printf("%d ", g[i]);
	printf("\n");
	for (int i = 1; i <= m; i++)
		printf("%d ", h[i]);
	printf("\n");
}


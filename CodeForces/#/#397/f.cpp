#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

struct node {
	int pos, value;
	bool operator < (const node &A) const {
		return value > A.value;
	}
} c[100001];

int n, m, a[100001], ans[300001], v[100001], f[400001], V[400001];
vector<int> Q[100001];
vector<int> P[100001];

inline void update(int i, int value) {
	for (; i <= n; i += i & (-i))
		f[i] = min(f[i], value);
}

int calc(int i) {
	int ans = 1 << 30;
	for (; i; i -= i & (-i))
		ans = min(ans, f[i]);
	return ans;
}

int findmax(int k, int Left, int Right, int s, int t) {
	if (s > t)
		return -1;
	if (Left == s && Right == t)
		return V[k];
	int i = (Left + Right) >> 1;
	if (t <= i)
		return findmax(k + k, Left, i, s, t);
	else
	if (s > i)
		return findmax(k + k + 1, i + 1, Right, s, t);
	else
		return max(findmax(k + k, Left, i, s, i), findmax(k + k + 1, i + 1, Right, i + 1, t));
}

inline void insert(int k, int Left, int Right, int x, int y) {
	V[k] = max(V[k], y);
	if (Left == Right) return;
	int i = (Left + Right) >> 1;
	if (x <= i)
		insert(k + k, Left, i, x, y);
	else
		insert(k + k + 1, i + 1, Right, x, y);
}

int findpos(int value) {
	int l = 0, r = n, m = (l + r) >> 1;
	for (; l + 1 < r; m = (l + r) >> 1)
		if (c[m].value <= value)
			r = m;
		else
			l = m;
	return r;
}

inline void work() {
	for (int i = 1; i <= n; i++)
		v[c[i].pos] = i;
	//for (int i = 1; i <= n; i++) 
	//	printf("%d\n", v[i]);
	memset(V, 255, sizeof(V));
	memset(f, 127, sizeof(f));
	for (int i = 1; i <= n; i++)
	{
		//printf("%d\n", i);
		int r = 1;
		for (; r < v[i]; )
		{
			//printf("r %d %d %d\n", r, v[i] - 1, c[r].value);
			int pos = findmax(1, 1, n, r, v[i] - 1);
			if (pos < 0)
				break;
			update(n - pos + 1, a[pos] - a[i]);
			//printf("I %d %d\n", pos, a[pos] - a[i]);
			if (a[pos] == a[i])
				break;
			r = findpos((a[i] + a[pos]) / 2);
			//printf("e %d %d\n", (a[i] + a[pos]) / 2, r);
		}
		insert(1, 1, n, v[i], i);
		for (int j = 0; j < Q[i].size(); j++)
			ans[P[i][j]] = min(ans[P[i][j]], calc(n - Q[i][j] + 1));
	}
}
 
int main() {
	//freopen("f.in", "r", stdin);
	//freopen("f.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), Q[i].clear(), P[i].clear(), 
		c[i].value = a[i], c[i].pos = i;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		Q[y].push_back(x);
		P[y].push_back(i);
	}
	memset(ans, 127, sizeof(ans));
	sort(c + 1, c + n + 1);
	work();
	for (int i = 1, j = n; i <= j; i++, j--)
	{
		swap(c[i].pos, c[j].pos);
		swap(c[i].value, c[j].value);
	}
	for (int i = 1; i <= n; i++)
		c[i].value = 1000000000 - c[i].value, a[i] = 1000000000 - a[i];
	work();
	for (int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
}


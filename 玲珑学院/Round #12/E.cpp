#include <cstdio>
#include <vector>
#include <algorithm>
std::vector < int > E[100001], col[100001];
std::vector < std::pair < int, int > > inc[100002], dec[100002];
int N, q[100001], left[100001], right[100001], size[100001], BeiZeng[17][100001], *fa = BeiZeng[0], LOG; // left : DFN; right maximum DFN in its subtree
std::vector < int >::iterator ue[100001];
void DFS()
{
	int D = 1, TIME = 1;
	q[1] = 1;
	ue[1] = E[1].begin();
	left[1] = right[1] = 1;
	while (D)
	{
		if (ue[D] != E[q[D]].end() && *ue[D] == fa[q[D]])
			ue[D]++;
		if (ue[D] != E[q[D]].end())
		{
			int To = *ue[D]++;
			fa[To] = q[D];
			left[To] = right[To] = ++TIME;
			q[++D] = To;
			ue[D] = E[To].begin();
		}
		else
		{
			if (D > 1)
				right[q[D - 1]] = right[q[D]];
			D--;
		}
	}
	for (int i = 1; i <= N; i++)
		size[i] = right[i] - left[i] + 1;
	while (2 << LOG < N)
		LOG++;
	for (int i = 1; i <= LOG; i++)
		for (int j = 1; j <= N; j++)
			BeiZeng[i][j] = BeiZeng[i - 1][BeiZeng[i - 1][j]];
}
int lowest(int u, int v)
{
	for (int i = LOG; ~i; i--)
		if (BeiZeng[i][u] && size[BeiZeng[i][u]] < size[v])
			u = BeiZeng[i][u];
	return u;
}
inline void bar(int u, int d, int l, int r)
{
	inc[u].push_back(std::make_pair(l, r));
	if (d < N)
		dec[d + 1].push_back(std::make_pair(l, r));
}
void conflict(int u, int v)
{
	if (size[u] < size[v])
		std::swap(u, v);
	if (left[u] <= left[v] && right[v] <= right[u]) // u is v's ancestor
	{
		int lw = lowest(v, u);
		if (left[lw] > 1)
		{
			bar(left[v], right[v], 1, left[lw] - 1);
			bar(1, left[lw] - 1, left[v], right[v]);
		}
		if (right[lw] < N)
		{
			bar(left[v], right[v], right[lw] + 1, N);
			bar(right[lw] + 1, N, left[v], right[v]);
		}
	}
	else
	{
		bar(left[u], right[u], left[v], right[v]);
		bar(left[v], right[v], left[u], right[u]);
	}
}
int MIN[262145], TAG[262145], NUM[262145]; // NUM[] : the number of elements which reach MIN[]
void INC(int p, int l, int r, int L, int R, int w)
{
	if (L <= l && r <= R)
	{
		MIN[p] += w;
		TAG[p] += w;
		return;
	}
	if (TAG[p])
	{
		MIN[p + p] += TAG[p];
		MIN[p + p + 1] += TAG[p];
		TAG[p + p] += TAG[p];
		TAG[p + p + 1] += TAG[p];
		TAG[p] = 0;
	}
	int m = (l + r) >> 1;
	if (L <= m)
		INC(p + p, l, m, L, R, w);
	if (R > m)
		INC(p + p + 1, m + 1, r, L, R, w);
	MIN[p] = std::min(MIN[p + p], MIN[p + p + 1]);
	NUM[p] = (MIN[p + p] == MIN[p] ? NUM[p + p] : 0) + (MIN[p + p + 1] == MIN[p] ? NUM[p + p + 1] : 0);
}
inline int ZERONUM()
{
	return MIN[1] == 0 ? NUM[1] : 0;
}
long long ANS;
void Treeinit(int p = 1, int l = 1, int r = N)
{
	NUM[p] = r - l + 1;
	if (l < r)
	{
		int m = (l + r) >> 1;
		Treeinit(p + p, l, m);
		Treeinit(p + p + 1, m + 1, r);
	}
}
int main()
{
	scanf("%d", &N);
	for (int i = 1, u, v; i < N; i++)
	{
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	for (int i = 1, c; i <= N; i++)
	{
		scanf("%d", &c);
		col[c].push_back(i);
	}
	DFS();
	for (int i = 1; i <= N; i++)
		for (std::vector < int >::iterator x = col[i].begin(); x != col[i].end(); x++)
			for (std::vector < int >::iterator y = x + 1; y != col[i].end(); y++)
				conflict(*x, *y);
	Treeinit();
	for (int i = 1; i <= N; i++)
	{
		for (std::vector < std::pair < int, int > >::iterator j = inc[i].begin(); j != inc[i].end(); j++)
			INC(1, 1, N, j -> first, j -> second, 1);
		for (std::vector < std::pair < int, int > >::iterator j = dec[i].begin(); j != dec[i].end(); j++)
			INC(1, 1, N, j -> first, j -> second, -1);
		ANS += ZERONUM();
	}
	printf("%lld\n", (ANS - N) >> 1);
	return 0;
}

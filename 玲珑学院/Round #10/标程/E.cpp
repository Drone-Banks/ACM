#include <stdio.h>
#include <cassert>
#include <algorithm>
typedef long long LL;
const int maxn = (int)1e5 + 1, maxd = 10;
const LL maxv = (LL)1e10 + 1;
int t, cnt, tot;
LL L, R, seq[maxn], res[maxn];
void pfs(int dep, LL val)
{
	if(val > 1)
		seq[cnt++] = val;
	if(dep == maxd)
		return;
	pfs(dep + 1, val * 10 + 1);
	pfs(dep + 1, val * 10 + 6);
}
void dfs(int dep, LL val)
{
	res[tot++] = val;
	LL lim = (maxv - 1) / val;
	for(int i = dep; i < cnt && seq[i] <= lim; ++i)
		dfs(i, val * seq[i]);
}
int main()
{
	pfs(0, 0);
	std::sort(seq, seq + cnt);
	dfs(0, 1);
	std::sort(res, res + tot);
	tot = std::unique(res, res + tot) - res;
	assert(scanf("%d", &t) == 1
	&& 1 <= t && t < maxn);
	while(t--)
	{
		assert(scanf("%lld%lld", &L, &R) == 2
		&& 1 <= L && L <= R && R < maxv);
		printf("%d\n", std::lower_bound(res, res + tot, R + 1) - std::lower_bound(res, res + tot, L));
	}
	return 0;
}

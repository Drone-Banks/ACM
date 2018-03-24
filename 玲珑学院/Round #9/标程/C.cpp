#include <stdio.h>
#include <cassert>
#include <algorithm>
const int maxt = 51, maxn = 100001, maxk = (int)1e9 + 1, maxv = (int)1e4 + 1;
int t, n, m, lim, a[maxn], b[maxn];
int tot, que[maxn], mx, cnt[maxn], sum[maxn];
void bit_add(int x)
{
	for(int i = x; i > 0; i -= i & -i)
	{
		++cnt[i];
		sum[i] += que[x];
	}
}
void bit_sub(int x)
{
	for(int i = x; i > 0; i -= i & -i)
	{
		--cnt[i];
		sum[i] -= que[x];
	}
}
int bit_que(int k) // at most k elements
{
	int ret = 0, msk = 0;
	for(int x = mx, y; x; x >>= 1)
		if((y = msk | x) <= tot && k < cnt[y])
			msk = y;
		else if(y <= tot)
		{
			k -= cnt[y];
			ret += sum[y];
		}
	ret += que[msk] * std::min(cnt[msk], k);
	return ret;
}
int main()
{
	assert(scanf("%d", &t) == 1
	&& 1 <= t && t < maxt);
	while(t--)
	{
		assert(scanf("%d%d%d", &n, &m, &lim) == 3
		&& 1 <= m && m <= n && n < maxn
		&& 1 <= lim && lim < maxk);
		tot = 0;
		for(int i = 1; i <= n; ++i)
		{
			assert(scanf("%d", a + i) == 1
			&& 1 <= a[i] && a[i] < maxv);
			que[++tot] = a[i];
		}
		std::sort(que + 1, que + tot + 1);
		tot = std::unique(que + 1, que + tot + 1) - que - 1;
		for(mx = 1; (mx << 1) <= tot; mx <<= 1);
		for(int i = 1; i <= n; ++i)
		{
			assert(scanf("%d", b + i) == 1
			&& 1 <= b[i] && b[i] < maxv);
			a[i] = std::lower_bound(que + 1, que + tot + 1, a[i]) - que;
		}
		int ans = 0;
		for(int i = 1, j = i, ctr = 0, val = 0; i <= n; ++i)
		{
			for( ; j <= n; ++j) // [i, j) -> [i, j]
			{
				ctr += que[a[j]];
				val += b[j];
				bit_add(a[j]);
				if(ctr - bit_que(m) > lim)
				{
					ctr -= que[a[j]];
					val -= b[j];
					bit_sub(a[j]);
					break;
				}
				if(ans < val)
					ans = val;
			}
			ctr -= que[a[i]];
			val -= b[i];
			bit_sub(a[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}

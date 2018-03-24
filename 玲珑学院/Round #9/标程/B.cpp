#include <stdio.h>
#include <cassert>
const int maxt = 21, maxk = 21, maxv = 1000000001;
const int maxn = 1 << 20 | 1;
int Log[maxn], t, n, a[maxn], sg, ans;
int main()
{
	for(int i = 2; i < maxn; ++i)
		Log[i] = Log[i >> 1] + 1;
	assert(scanf("%d", &t) == 1
	&& 1 <= t && t < maxt);
	while(t--)
	{
		assert(scanf("%d", &n) == 1
		&& 1 <= n && n < maxk);
		sg = 0;
		for(int i = 1; i < 1 << n; ++i)
		{
			assert(scanf("%d", a + i) == 1
			&& 0 <= a[i] && a[i] < maxv);
			if((n - Log[i]) & 1)
				sg ^= a[i];
		}
		ans = 0;
		for(int i = 1; i < 1 << n; ++i)
		{
			if(!((n - Log[i]) & 1))
				continue;
			int tmp = sg ^ a[i];
			if(0 <= tmp && tmp < a[i])
				ans += 1 + (n - Log[i] > 1);
			else if(a[i] < tmp && tmp <= a[i] + a[i >> 1]) // a[0] = 0
				++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}

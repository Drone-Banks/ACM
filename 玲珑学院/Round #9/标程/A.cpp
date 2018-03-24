#include <cmath>
#include <stdio.h>
#include <cassert>
#include <algorithm>
typedef long long LL;
const int maxn = 31623, maxm = 17, maxp = 61, maxt = 100001, maxv2 = (int)1e9;
const LL maxv = (LL)1e18;
int tot, pr[maxn], d[maxn], sz[maxm];
LL pp[maxm][maxn];
bool isprime(int x)
{
	if(x < 2)
		return 0;
	if(x < maxn)
		return d[x] == x;
	for(int i = 0; i < tot && pr[i] * pr[i] <= x; ++i)
		if(x % pr[i] == 0)
			return 0;
	return 1;
}
int main()
{
	for(int i = 2; i < maxn; ++i)
	{
		if(!d[i])
			pr[tot++] = d[i] = i;
		for(int j = 0, k; (k = i * pr[j]) < maxn; ++j)
		{
			d[k] = pr[j];
			if(d[i] == pr[j])
				break;
		}
	}
	for(int i = 2; i < maxm; ++i)
		for(int j = 0; j < tot; ++j)
		{
			int rem = pr[i] - 1;
			LL val = 1, lim = maxv / pr[j];
			for( ; rem && val <= lim; --rem, val *= pr[j]);
			if(rem)
				break;
			pp[i][sz[i]++] = val;
		}
	int t;
	LL n, p;
	assert(scanf("%d", &t) == 1
	&& 1 <= t && t < maxt);
	while(t--)
	{
		assert(scanf("%lld%lld", &n, &p) == 2
		&& 1 <= n && n <= maxv
		&& (p & 1) && p <= maxv2 && isprime(p));
		if(p >= maxp || d[p] != p)
		{
			puts("NO");
			continue;
		}
		if(p == 3)
		{
			LL val = (LL)sqrt(n);
			for( ; val * val > n; --val);
			for( ; (val + 1) * (val + 1) <= n; ++val);
			puts(val * val == n && isprime(val) ? "YES" : "NO");
			continue;
		}
		for(int i = 2; i < maxm; ++i)
			if(pr[i] == p)
			{
				puts(*std::lower_bound(pp[i], pp[i] + sz[i], n) == n ? "YES" : "NO");
				break;
			}
	}
	return 0;
}

#include <stdio.h>
#include <cassert>
const int maxt = 1001, maxn = 1000001, mod = 1000000007;
int t, n, a, b, f[maxn][3];
inline void mod_add(int &x, int y)
{
	if((x += y) >= mod)
		x -= mod;
}
inline void mod_sub(int &x, int y)
{
	if((x -= y) < 0)
		x += mod;
}
int main()
{
	f[0][0] = 1;
	assert(scanf("%d", &t) == 1
	&& 1 <= t && t < maxt);
	while(t--)
	{
		static int sum_n = 0;
		assert(scanf("%d%d%d", &a, &b, &n) == 3
		&& 1 <= a && a < maxn
		&& 1 <= b && b < maxn
		&& 1 <= n && n < maxn
		&& (sum_n += n >= 10000) <= 50);
		for(int i = 1; i <= n; ++i)
		{
			f[i][1] = f[i - 1][0];
			if(i >= a)
			{
				mod_sub(f[i][1], f[i - a][0]);
				mod_add(f[i][1], f[i - a][1]);
			}
			f[i][2] = f[i - 1][0];
			if(i >= b)
			{
				mod_sub(f[i][2], f[i - b][0]);
				mod_add(f[i][2], f[i - b][2]);
			}
			f[i][0] = f[i][1];
			mod_add(f[i][0], f[i][2]);
		}
		printf("%d\n", f[n][0]);
	}
	return 0;
}

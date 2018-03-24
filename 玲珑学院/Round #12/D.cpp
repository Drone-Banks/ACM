#include <cstdio>
const long long MOD = 1234321237;
long long POWER(long long a, long long b)
{
	long long r = 1;
	for (; b; b >>= 1)
	{
		if (b & 1)
			r = r * a % MOD;
		a = a * a % MOD;
	}
	return r;
}
long long N;
int T;
int main()
{
	for (scanf("%d", &T); T--; )
	{
		scanf("%lld", &N);
		long long F = POWER(4, N - 1) * 3 - POWER(3, N - 1) * 2;
		long long G = POWER(4, N - 1) * (((N % MOD * 9) - 69) % MOD) + POWER(3, N - 1) * (((N % MOD * 8) + 52) % MOD);
		G %= MOD;
		F %= MOD;
		G %= MOD;
		F += MOD;
		G += MOD;
		F %= MOD;
		G %= MOD;
		if (G & 1)
			G += MOD;
		G >>= 1;
		printf("%lld %lld\n", F, G);
	}
	return 0;
}

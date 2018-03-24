#include <bits/stdc++.h>
const int MOD = 1234321237;
int F[100001], N, G, a[1000], w[1000];
int gcd(int x, int y)
{
	int r;
	while (y)
	{
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}
void DP(int x, int y)
{
	std::vector < int > Div;
	for (int i = 1; i * i <= x; i++)
		if (x % i == 0)
		{
			Div.push_back(i);
			if (i * i < x)
				Div.push_back(x / i);
		}
	std::sort(Div.begin(), Div.end());
	int L = Div.size();
	std::vector < int > Use(L, 0);
	for (int i = L - 1; ~i; i--)
	{
		Use[i] = y / Div[i];
		for (int j = i + 1; j < L; j++)
			if (Div[j] % Div[i] == 0)
				Use[i] -= Use[j];
	}
	for (int i = G; ~i; i--)
	{
		F[i] = 0;
		for (int j = 0; j < L && Div[j] <= i; j++)
			F[i] = (F[i] + (long long)F[i - Div[j]] * Use[j]) % MOD;
		std::cout << i << " " << F[i] << std::endl; 
	}
}
int main()
{
	scanf("%d%d", &N, &G);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	for (int i = 0; i < N; i++)
		scanf("%d", w + i);
	F[0] = 1;
	for (int i = 0; i < N; i++)
		DP(a[i], w[i]);
	printf("%d\n", F[G]);
	system("pause");
	return 0;
}

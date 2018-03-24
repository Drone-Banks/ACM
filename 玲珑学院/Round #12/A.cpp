#include <cstdio>
#include <algorithm>
int T, N, R, X;
int main()
{
	for (scanf("%d", &T); T--; )
	{
		scanf("%d%d%d", &N, &R, &X);
		printf("%d\n", std::min(N, X + R) - std::max(1, X - R) + 1);
	}
	return 0;
}

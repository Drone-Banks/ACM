#include <stdio.h>
#include <cassert>
#include <cstring>
const int maxt = 31, maxn = 101, maxm = 11, maxs = 59049, INF = 0x3f3f3f3f;
int t, n, m, pw[maxm], f[2][maxs], cur, pre = 1;
char str[maxn][maxm];
inline void upd(int &x, int y)
{
	if(x > y)
		x = y;
}
inline int test(int mask, int pos)
{
	return mask / pw[pos] % 3;
}
inline int trans(int mask, int pos, int val)
{
	int cur = test(mask, pos);
	for( ; cur < val; ++cur, mask += pw[pos]);
	for( ; cur > val; --cur, mask -= pw[pos]);
	return mask;
}
int main()
{
	pw[0] = 1;
	for(int i = 1; i < maxm; ++i)
		pw[i] = (pw[i - 1] << 1) + pw[i - 1];
	assert(scanf("%d", &t) == 1
	&& 1 <= t && t < maxt);
	while(t--)
	{
		assert(scanf("%d%d", &n, &m) == 2
		&& 1 <= n && n < maxn
		&& 1 <= m && m < maxm);
		for(int i = 0; i < n; ++i)
		{
			assert(scanf("%s", str[i]) == 1
			&& strlen(str[i]) == m);
		    for(int j = 0; j < m; ++j)
		        assert(str[i][j] == '.' || str[i][j] == '*');
		}
		int fir = 0, las = 0;
		for(int i = 0; i < m; ++i)
		{
			if(str[0][i] == '*')
				fir += pw[i];
			str[n][i] = '*';
			las += pw[i];
		}
		memset(f[cur], 0x3f, pw[m] * sizeof(int));
		f[cur][fir] = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 0; j < m; ++j)
			{
				cur ^= 1;
				pre ^= 1;
				memset(f[cur], 0x3f, pw[m] * sizeof(int));
				for(int s = 0; s < pw[m]; ++s)
				{
					if(f[pre][s] == INF)
						continue;
					int sp = test(s, j);
					if(sp == 1) // skip
						upd(f[cur][trans(s, j, str[i][j] == '*')], f[pre][s]);
					else
					{
						if(sp == 0) // delay
						{
							int ss = trans(s, j, 1 + (str[i][j] != '*'));
							if(j + 1 < m && test(s, j + 1) != 1)
								ss = trans(ss, j + 1, 2);
							upd(f[cur][ss], f[pre][s]);
						}
						if(j + 1 < m && test(s, j + 1) != 1) // right
							upd(f[cur][trans(trans(s, j, str[i][j] == '*'), j + 1, 1)], f[pre][s] + 1);
						if(str[i][j] != '*') // down
							upd(f[cur][trans(s, j, 1)], f[pre][s] + 1);
					}
				}
			}
		printf("%d\n", f[cur][las]);
	}
	return 0;
}

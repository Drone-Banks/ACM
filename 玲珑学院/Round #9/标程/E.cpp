#include <cstdio>
#include <cstring>
#include <cassert>
typedef long long LL;
const int maxt = 1001, maxn = 101, maxm = 10001, maxv = (int)1e9 + 1, maxd = 31;
int t, n, m, q, mod, Max;
struct Matrix {
	int r, c, num[maxn][maxn];
	Matrix operator + (const Matrix &x) const {
		Matrix ret = *this;
		for(int i = 0; i < r; ++i)
			for(int j = 0; j < c; ++j)
				if((ret.num[i][j] += x.num[i][j]) >= mod)
					ret.num[i][j] -= mod;
		return ret;
	}
	Matrix operator * (const Matrix &x) const {
		Matrix ret = {r, x.c};
		for(int i = 0; i < r; ++i)
			for(int j = 0; j < c; ++j) if(num[i][j])
				for(int k = 0; k < x.c; ++k) if(x.num[j][k])
					ret.num[i][k] = (ret.num[i][k] + (LL)num[i][j] * x.num[j][k]) % mod;
		return ret;
	}
} Sum[maxd], Mat[maxd], Ans, Tmp;
int main()
{
	assert(scanf("%d", &t) == 1
	&& 1 <= t && t < maxt);
	while(t--)
	{
		static int sum_big = 0;
		assert(scanf("%d%d%d%d", &n, &m, &q, &mod) == 4
		&& 1 <= n && n < maxn
		&& 1 <= m && m < maxm
		&& 1 <= q && q < maxn
		&& 1 <= mod && mod < maxv
		&& (sum_big += !(n <= 10 && m <= 500 && q <= 10)) <= 5);
		Max = 0;
		Sum[0].r = Sum[0].c = Mat[0].r = Mat[0].c = n;
		for(int i = 0; i < n; ++i)
		{
			memset(Sum[0].num[i], 0, n * sizeof(int));
			Sum[0].num[i][i] = 1;
			memset(Mat[0].num[i], 0, n * sizeof(int));
		}
		while(m--)
		{
			int u, v;
			assert(scanf("%d%d", &u, &v) == 2
			&& 1 <= u && u <= n
			&& 1 <= v && v <= n);
			--u, --v;
			++Mat[0].num[u][v];
			if(u != v)
				++Mat[0].num[v][u];
		}
		for(int i = 0; i < q; ++i)
		{
			int u, v, d;
			assert(scanf("%d%d%d", &u, &v, &d) == 3
			&& 1 <= u && u <= n
			&& 1 <= v && v <= n
			&& 1 <= d && d < maxv);
			--u, --v;
			Ans.r = Tmp.r = 1;
			Ans.c = Tmp.c = n;
			memset(Ans.num[0], 0, n * sizeof(int));
			memcpy(Tmp.num[0], Mat[0].num[u], n * sizeof(int));
			for(int j = 0; d > 0; ++j, d >>= 1)
			{
				if(~d & 1)
					continue;
				for( ; Max < j; ++Max)
				{
					Sum[Max + 1] = Sum[Max] + Mat[Max] * Sum[Max];
					Mat[Max + 1] = Mat[Max] * Mat[Max];
				}
				Ans = Ans + Tmp * Sum[j];
				Tmp = Tmp * Mat[j];
			}
			printf("%d\n", Ans.num[0][v]);
		}
	}
	return 0;
}

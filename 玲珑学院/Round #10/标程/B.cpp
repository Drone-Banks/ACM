#include <cmath>
#include <stdio.h>
#include <cstring>
#include <cassert>
#include <algorithm>
typedef long long LL;
typedef long double DB;
const int maxt = 101, maxn = 100001, maxh = 300001, maxv = 100001, maxp = 101;
const int maxLen = 18, maxm = 1 << maxLen | 1;
const DB pi = acos((DB)-1);
struct complex
{
	long double r, i;
	complex() {}
	complex(long double x, long double y) : r(x), i(y) {}
	friend complex operator + (const complex &a, const complex &b) { return complex(a.r + b.r, a.i + b.i); }
	friend complex operator - (const complex &a, const complex &b) { return complex(a.r - b.r, a.i - b.i); }
	friend complex operator * (const complex &a, const complex &b) { return complex(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r); }
	complex conj() { return complex(r, -i); }
} X[maxm], Y[maxm];
void FFT(complex a[], int n, int flag)
{
	for(int i = 1, j = n >> 1, k; i < n - 1; ++i)
	{
		if(i < j)
			std::swap(a[i], a[j]);
		for(k = n >> 1; j >= k; k >>= 1)
			j -= k;
		if(j < k)
			j += k;
	}
	for(int i = 1; i < n; i <<= 1)
	{
		complex wn(cos(pi / i), flag * sin(pi / i));
		for(int j = 0; j < n; j += i << 1)
		{
			complex w(1, 0);
			for(int k = 0; k < i; ++k, w = w * wn)
			{
				complex t = w * a[j + k + i];
				a[j + k + i] = a[j + k] - t;
				a[j + k] = a[j + k] + t;
			}
		}
	}
	if(flag == -1)
		for(int i = 0; i < n; ++i)
			a[i].r /= n;
}
int t, n, m, a[maxn], b[maxn], c[maxn], p[maxn], mxB, mxC;
int len, bs[maxn], cs[maxn];
LL f[(maxn - 1) << 1 | 1];
int main()
{
	assert(scanf("%d", &t) == 1
	&& 1 <= t && t < maxt);
	while(t--)
	{
		static int sum_n = 0;
		assert(scanf("%d%d", &n, &m) == 2
		&& 1 <= n && n < maxn
		&& 1 <= m && m < maxh
		&& (sum_n += !(n <= 1000 && m <= 1000)) <= 10);
		mxB = mxC = 0;
		for(int i = 0; i < n; ++i)
		{
			assert(scanf("%d%d%d%d", a + i, b + i, c + i, p + i) == 4
			&& 0 <= a[i] && a[i] < maxv
			&& 0 <= b[i] && b[i] < maxv
			&& 0 <= c[i] && c[i] < maxv
			&& 0 <= p[i] && p[i] < maxp);
			if(mxB < b[i])
				mxB = b[i];
			if(mxC < c[i])
				mxC = c[i];
		}
		if(mxB > m)
			mxB = m;
		if(mxC > m)
			mxC = m;
		for(len = 1; len <= mxB + mxC; len <<= 1);
		memset(bs, 0, (mxB + 1) * sizeof(int));
		memset(cs, 0, (mxC + 1) * sizeof(int));
		for(int i = 0; i < len; ++i)
			X[i] = complex(0, 0);
		for(int i = 0; i < n; ++i)
		{
			if(b[i] > mxB)
				b[i] = mxB;
			if(c[i] > mxC)
				c[i] = mxC;
			++bs[b[i]];
			++cs[c[i]];
			++X[b[i]].r;
			++X[c[i]].i;
		}
		FFT(X, len, 1);
		for(int i = 0; i < len; ++i)
		{
			int j = (len - i) & (len - 1);
			Y[i] = (X[i] * X[i] - (X[j] * X[j]).conj()) * complex(0, -0.25);
		}
		FFT(Y, len, -1);
		for(int i = 0; i <= mxB + mxC; ++i)
			f[i] = (LL)(Y[i].r + 0.5);
		for(int i = 0; i < n; ++i)
			--f[b[i] + c[i]];
		for(int i = mxB - 1; i >= 0; --i)
			bs[i] += bs[i + 1];
		for(int i = mxC - 1; i >= 0; --i)
			cs[i] += cs[i + 1];
		for(int i = mxB + mxC - 1; i >= 0; --i)
			f[i] += f[i + 1];
		LL ans = 0;
		for(int i = 0; i < n; ++i)
		{
			int dt = (100 * m - 1) / (100 + p[i]) + 1 - a[i];
			if(mxB + mxC < dt)
				continue;
			ans += f[std::max(dt, 0)];
			if(dt <= mxB + c[i])
				ans -= bs[std::max(dt - c[i], 0)];
			if(dt <= b[i] + mxC)
				ans -= cs[std::max(dt - b[i], 0)];
			if(dt <= b[i] + c[i])
				ans += 2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

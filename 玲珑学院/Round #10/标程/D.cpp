#include <cmath>
#include <stdio.h>
#include <cassert>
#include <algorithm>
typedef long double DB;
typedef long long LL;
const int maxt = 10001, maxr = 1000001, maxang = 360;
const DB pi = acos((DB)-1), eps = 1e-10;
int t, r, h, ang1, ang2, h1, h2, ang;
inline int sgn(DB x)
{
	assert(!std::isnan(x));
	return (x > eps) - (x < -eps);
}
inline LL sqr(int x)
{
	return (LL)x * x;
}
inline DB sqr(DB x)
{
	return x * x;
}
inline DB rad(int x)
{
	return pi * x / (maxang >> 1);
}
inline DB calc(int H, int R, DB alpha)
{
	DB pL = 0, pR = alpha, H2divR2 = (DB)sqr(H) / sqr(R);
	if(sgn(sin((alpha - pL) / 2) - sqrt((DB)H / (R << 1))) > 0) // do not pass the minmum limit (from f'')
		pR -= 2 * asin(sqrt((DB)H / (R << 1)));
	for(int i = 0; i < 100; ++i)
	{
		DB pM = pL + (pR - pL) / 2;
		DB val = pM / sqrt(sqr(pM) + H2divR2) - cos((alpha - pM) / 2); // f'(pL) <= 0, f'(pR) > 0, f' is mono
		if(sgn(val) > 0)
			pR = pM;
		else
			pL = pM;
	}
	return (sqrt(sqr(pL) + H2divR2) + 2 * sin((alpha - pL) / 2)) * R;
}
int main()
{
	assert(scanf("%d", &t) == 1
	&& 1 <= t && t < maxt);
	while(t--)
	{
		assert(scanf("%d%d%d%d%d%d", &r, &h, &ang1, &h1, &ang2, &h2) == 6
		&& 1 <= r && r < maxr
		&& 1 <= h && h < maxr
		&& 0 <= ang1 && ang1 < maxang
		&& 0 <= ang2 && ang2 < maxang
		&& 0 < h1 && h1 < h
		&& 0 < h2 && h2 < h);
		ang = ang1 - ang2;
		if(ang < 0)
			ang = -ang;
		if(ang > maxang - ang)
			ang = maxang - ang;
		h2 = (h << 1) - h2;
		printf("%.6f\n", (double)std::min((DB)sqrt(sqr(r * rad(ang)) + sqr(h2 - h1)), calc(h1 + h2, r, rad(ang))));
	}
	return 0;
}

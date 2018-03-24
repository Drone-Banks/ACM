#define OPENSTACK
#include <stdio.h>
#include <cstring>
#include <cassert>
#include <cstdlib>
typedef long long LL;
const int maxt = 51, maxn = 100001, maxm = 400001;
const LL maxv = ~0ULL >> 1;
struct Edge {
	int nxt, v;
} e[maxm];
int t, n, m, lnk[maxn], tot, pre[maxn], *bcc = pre, deg[maxn], bcnt[maxn];
bool used[maxm];
int tarjan(int u, int Fa)
{
	int lowu = pre[u] = tot++;
	for(int it = lnk[u]; it != -1; it = e[it].nxt)
	{
		if(Fa == (it ^ 1))
			continue;
		int v = e[it].v;
		if(pre[v] == -1)
		{
			int lowv = tarjan(v, it);
			if(lowu > lowv)
				lowu = lowv;
			if(pre[u] < lowv)
				used[it] = used[it ^ 1] = 1;
		}
		else if(lowu > pre[v])
			lowu = pre[v];
	}
	return lowu;
}
void dfs(int u)
{
	++bcnt[tot];
	bcc[u] = tot;
	for(int it = lnk[u]; it != -1; it = e[it].nxt)
		if(used[it])
			++deg[tot];
		else if(bcc[e[it].v] == -1)
				dfs(e[it].v);
}
int main()
{
	#ifdef OPENSTACK
		int size = 64 << 20; // 64MB
		char *p = (char*)malloc(size) + size;
		#if (defined _WIN64) or (defined __unix)
			__asm__("movq %0, %%rsp\n" :: "r"(p));
		#else
			__asm__("movl %0, %%esp\n" :: "r"(p));
		#endif
	#endif
	assert(scanf("%d", &t) == 1
	&& 1 <= t && t < maxt);
	while(t--)
	{
		assert(scanf("%d%d", &n, &m) == 2
		&& 1 <= n && n < maxn
		&& 1 <= m && m < maxm);
		memset(lnk + 1, -1, n * sizeof(int));
		memset(used, 0, (m << 1) * sizeof(bool));
		for(int i = 0; i < m; ++i)
		{
			int u, v;
			assert(scanf("%d%d", &u, &v) == 2
			&& 1 <= u && u <= n
			&& 1 <= v && v <= n
			&& u != v);
			e[i << 1] = (Edge){lnk[u], v};
			lnk[u] = i << 1;
			e[i << 1 | 1] = (Edge){lnk[v], u};
			lnk[v] = i << 1 | 1;
		}
		{ // assert multi-edge
			static int tim[maxn];
			memset(tim + 1, -1, n * sizeof(int));
			for(int i = 1; i <= n; ++i)
				for(int it = lnk[i]; it != -1; it = e[it].nxt)
				{
					assert(tim[e[it].v] != i);
					tim[e[it].v] = i;
				}
		}
		tot = 0;
		memset(pre + 1, -1, n * sizeof(int));
		for(int i = 1; i <= n; ++i)
			if(pre[i] == -1)
			{
				assert(i == 1);
				tarjan(i, -1);
			}
		tot = 0;
		memset(bcc + 1, -1, n * sizeof(int));
		int ans1 = 0;
		LL ans2 = 1;
		bool invalid = 0;
		for(int i = 1; i <= n; ++i)
			if(bcc[i] == -1)
			{
				deg[tot] = bcnt[tot] = 0;
				dfs(i);
				if(deg[tot] == 1)
				{
					if(bcnt[tot] == 1)
					{
						ans1 = -1;
						break;
					}
					if(ans2 && bcnt[tot] - 1 > maxv / ans2)
						invalid = 1;
					++ans1;
					ans2 *= bcnt[tot] - 1;
				}
				++tot;
			}
		if(ans1 == -1)
		{
			printf("%d\n", ans1);
			continue;
		}
		if(tot == 1)
		{
			ans1 = 2;
			ans2 = ((n * (n - 1LL)) >> 1) - m;
			if(!ans2)
			{
				++ans1;
				ans2 = n * (n - 1LL) * (n - 2LL) / 6;
			}
		}
		assert(!invalid);
		printf("%d %lld\n", ans1, ans2);
	}
	#ifdef OPENSTACK
		exit(0);
	#else
		return 0;
	#endif
}

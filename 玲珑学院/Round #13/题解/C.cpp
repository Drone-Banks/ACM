#include <bits/stdc++.h>

#define MOD 1000000007

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std ;

int n, K ; 

typedef long long LL ; 

int qpow(int a, int b) { 
		int ret = 1 ;
		for (; b; b >>= 1, a = 1LL * a * a % MOD) if (b & 1) ret = 1LL * ret * a % MOD ; 
		return ret ;
}

const int MAXN = 500010 ; 

int siz[MAXN], fa[MAXN];  

vector<int> g[MAXN]; 
				
int main() { 
		scanf("%d%d", &n, &K) ; 
		for (int i = 2; i <= n; i ++) scanf("%d", &fa[i]) ; 
		for (int i = n; i; i --) {
				 siz[i] ++ ; 
				 siz[fa[i]] += siz[i] ; 
				 g[fa[i]].push_back(i) ; 
		}
		int ans = 0 ; 
		for (int i = 2; i <= n; i ++) { 
				int t = 1LL * siz[i] * (n - siz[i]) % MOD ; 
				ans = (ans - qpow(t, K) + MOD) % MOD ; 
		}
		for (int i = 1; i <= n; i ++) { 
				int t = 0 ;
				for (int j = 0; j < g[i].size(); j ++) { 
						t += 1LL * siz[g[i][j]] * (n - siz[g[i][j]] - 1) % MOD ; 
						t %= MOD ; 
				}
				t += 1LL * (siz[i] - 1) * (n - siz[i]) % MOD ; 
				t %= MOD; 
				t = 1LL * t * ((MOD + 1) / 2) % MOD ; 
				t += n ; 
				t %= MOD ; 
				ans += qpow(t, K) ;
				ans %= MOD ; 
		}
		printf("%d\n", ans) ; 
}

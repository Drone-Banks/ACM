#include <bits/stdc++.h>

#define MOD 998244353

using namespace std ;

int n, k; 

int qpow(int a, int b) { 
		int ret = 1; 
		for (; b; b >>= 1, a = 1LL * a * a % MOD) if (b & 1) ret = 1LL * ret * a % MOD ; 
		return ret ;
}

int C(int n, int m) { 
		int ans = 1 ; 
		for (int i = 1; i <= m; i ++) { 
				ans = 1LL * ans * (n - i + 1) % MOD * qpow(i, MOD - 2) % MOD ; 
		}
		return ans ;
}
						
int main() { 

		scanf("%d%d", &n, &k) ; 
		n -= k ; 
		int ans = 1LL * qpow(n, k - 1) * qpow(k, n - 1) % MOD ;
		ans = 1LL * ans * C(n + k - 1, k - 1) % MOD ; 
		printf("%d\n", ans) ; 
}

#include <bits/stdc++.h>

using namespace std ;

typedef long long LL ;

const int MAXN = 500010 ;

int n ; 

int a[MAXN], b[MAXN] ; 

int main() { 
		scanf("%d", &n) ;
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]) ; 
		for (int i = 1; i <= n; i ++) scanf("%d", &b[i]) ;
		sort(a + 1, a + n + 1) ;
		sort(b + 1, b + n + 1) ; 
		LL ans = 0 ; 
		for (int i = 1; i <= n; i ++) ans += 1LL * a[i] * b[i] ; 
		cout << ans << endl ; 
}

#include <bits/stdc++.h>

using namespace std ;

int n ;

typedef long long LL ; 

LL M ; 

const int MAXN = 300010 ;

int a[MAXN] ; 

int ps[MAXN], p[MAXN], cnt[MAXN], v[MAXN]; 
bool vis[MAXN] ; 


bool check(int l, int r) { 
		for (int i = l; i <= r; i ++) p[i] = a[i] ;  
		sort(p + l, p + r + 1) ; 
		LL ans = 0 ; 
		for (int i = l; i <= r; i ++) { 
				ans += 1LL * p[i] * v[i - l + 1] ; 
		}
		return ans <= M ; 
}

int main() { 
		cin >> n >> M ; 
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]) ;
	    for (int i = 1; i <= n; i ++) scanf("%d", &v[i]) ; 	
		int l = 1, r = 1 ; 
		for (; l <= n;) { 
				 int last = 1, lastp = r - 1 ;  
				 for (; check(l, r) && lastp < r; lastp = r , r = min(n, r + last), last <<= 1) ; 
				 if (lastp == r) break ; 
				 int lp = lastp + 1, rp = r ; 
				 while (lp < rp) { 
						 int mid = ((lp + rp) >> 1) ; 
						 if (!check(l, mid)) rp = mid ;
						 else lp = mid + 1;  
				 }
				 cnt[lp] ++ ; 
				 l = lp + 1, r = l  ; 
		}
		for (int i = 1; i <= n; i ++) {
				cnt[i] += cnt[i - 1] ; 
				printf("%d", cnt[i]) ; 
				if (i < n) putchar(' ') ; 
		}
		putchar(10) ; 
}

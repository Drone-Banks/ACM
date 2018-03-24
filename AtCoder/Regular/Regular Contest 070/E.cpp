
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--) 
#define Rep(i,a) for(int i = 0; i < a; i++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ab(x) ((x) < 0 ? -(x) : (x))
using namespace std;
typedef long long LL;
typedef map<int, int>::iterator mit;
typedef set<LL>::iterator sit;
const int N = 1e5 + 10;
const LL inf = 1e13;
int l[N], r[N];
multiset<LL> s0, s1; LL d0, d1;
int main() {
	int n; scanf("%d",&n);
	int l1 = 0;
	rep(i,1,n) {
		scanf("%d%d",&l[i],&r[i]);
		int l2 = r[i] - l[i]; 
		if (i > 1) d0 -= l2, d1 += l1;
		l1 = l2;
		LL L, R;
		if (i > 1) {
			sit it = s0.end(); it--;
			L = *it + d0;
			it = s1.begin();
			R = *it + d1;
		} else L = 0, R = 0;
		if (L <= l[i] && l[i] <= R) {
			s0.insert(l[i] - d0), s1.insert(l[i] - d1);
		} else if (l[i] < L) {
			s0.insert(l[i] - d0), s0.insert(l[i] - d0);
			sit it = s0.end(); it--;
			s1.insert(*it + d0 - d1); s0.erase(it);
		} else if (l[i] > R) {
			s1.insert(l[i] - d1), s1.insert(l[i] - d1);
			sit it = s1.begin(); 
			s0.insert(*it + d1 - d0); s1.erase(it);
		}
	}
	LL cur = 0, t = -inf;
	dep(i,n,1) cur += l[i] - t, t += r[i] - l[i];
	int d = -n; LL tmp = -inf;
	for(sit it = s0.begin(); it != s0.end(); it++)
		cur += 1LL * d * (*it + d0 - tmp), tmp = *it + d0, d++;
	cout <<cur<<endl;
	return 0;
}

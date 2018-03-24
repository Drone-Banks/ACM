#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int k, a, b;

int main() {
	//freopen("c.in", "r", stdin);
	//freopen("c.out", "w", stdout);
	scanf("%d%d%d", &k, &a, &b);
	if (a > b)
		swap(a, b);
	if (a < k)
		if (!(b % k))
			printf("%d\n", b / k);
		else
			printf("-1\n");
	else
		printf("%d\n", a / k + b / k); 
}


/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
int n, m, x[MaxN], y[MaxN];

int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++) scanf("%d", x+i);
    for(int i=1;i<=m;i++) scanf("%d", y+i);
    LL sx = 0;
    LL sy = 0;
	for(int i = 1; i <= n; i++) {
		sx = (sx+(LL)x[i]*(i-1)%mod)%mod;
		sx = (sx-(LL)x[i]*(n-i)%mod+mod)%mod;
	}
    for(int i = 1; i <= m; i++) {
		sy = (sy+(LL)y[i]*(i-1)%mod)%mod;
		sy = (sy-(LL)y[i]*(m-i)%mod+mod)%mod;
	}
	printf("%lld\n", sx*sy%mod);
    //system("pause");
}

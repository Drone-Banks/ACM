/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
#include <climits>
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

int T;
int n;
int A[MaxN], B[MaxN], C[MaxN];
int gcd(int a, int b)
{
    return b==0?a:gcd(b,a%b);
}

void solve()
{
    int ans = 0;
    for(int i=1;i<=n-2;i++)
    {
        ans = max(ans, gcd(B[i], C[n-i-1]));
    }
    ans = max(ans, B[n-1]);
    ans = max(ans, C[n-1]);
    printf("%d\n", ans);
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i=1;i<=n;i++) scanf("%d", &A[i]);

        B[1] = A[1];
        for(int i=2;i<=n;i++)
        {
            B[i] = gcd(B[i-1],A[i]);
        }

        C[1] = A[n];
        for(int i=2;i<=n;i++)
        {
            C[i] = gcd(C[i-1], A[n-i+1]);
        }

        solve();
    }
}
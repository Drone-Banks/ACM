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

LL gcd(LL a, LL b)
{
    return b==0?a:gcd(b, a%b);
}
int n;
LL A[MaxN];

void solve()
{
    int ans = 0;
    int GCD = A[1];
    for(int i=2;i<=n;i++)
    {
        GCD = gcd(GCD, A[i]);
    }
    if(GCD>1) 
    {
        cout << "YES\n" << 0 << endl;
        return;
    }
    for(int i=2;i<=n;i++)
    {
        if(A[i]%2 && A[i-1]%2)
        {
            LL tmp = A[i-1];
            A[i-1] = abs(A[i-1] - A[i]);
            A[i] = abs(tmp + A[i]);
            ans++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        //cout << i << " " << A[i] << endl;
        if(A[i]%2)
        {
            A[i] = abs(2*A[i]);
            A[i+1] = abs(2*A[i+1]);
            ans+=2;
        }
    }
    
    cout << "YES\n" << ans << endl;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%lld", &A[i]);
    solve();
    system("pause");
}

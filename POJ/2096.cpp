/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <iomanip>
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
#define ALL(a) a.begin(), a.end()
using namespace std;

#define MaxN 1010
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
inline int max2(int a, int b) {return ((a > b)? a : b);}
inline int min2(int a, int b) {return ((a < b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}
inline int min3(int a, int b, int c) {return min2(a, min2(b, c));}

int n,s;
double DP[MaxN][MaxN];

void solve()
{
    CLR(DP);
    DP[n][s] = 0;
    for(int i=n;i>=0;i--)
    {
        for(int j=s;j>=0;j--)
        {
            if(i==n && s==j) continue;
            DP[i][j] = n*s;
            DP[i][j] += (double) (n-i)*1.0*  j    * DP[i+1][j] + 
                        (double)    i *1.0* (s-j) * DP[i][j+1] + 
                        (double) (n-i)*1.0* (s-j) * DP[i+1][j+1];

            DP[i][j] /= (1.0*n*s-1.0*i*j);
        }
    }
    printf("%.4f\n", DP[0][0]);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &s))
    {
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x+mod)%mod );
}

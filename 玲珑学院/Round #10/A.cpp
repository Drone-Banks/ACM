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

#define MaxN 1000001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
const int mod = 1E9+7;
template <class T>
inline void scan_d(T &ret) {
	char c; ret=0;
	while((c=getchar())<'0'||c>'9');
	while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
}
inline void out(int x) {
   if(x>9) out(x/10);
   putchar(x%10+'0');
}
int DP[MaxN][3];
int T,a,b,n;
int sum;

inline void mod_add(int &x, int y)
{
	if((x += y) >= mod)
		x -= mod;
}
inline void mod_sub(int &x, int y)
{
	if((x -= y) < 0)
		x += mod;
}
void solve()
{
    for(int i=1;i<=n;i++)
    {
        DP[i][1] = DP[i-1][0];
        if(i>=a)
        {
            mod_sub(DP[i][1], DP[i-a][0]);
            mod_add(DP[i][1], DP[i-a][1]);
        }
        DP[i][2] = DP[i-1][0];
        if(i>=b)
        {
            mod_sub(DP[i][2], DP[i-b][0]);
            mod_add(DP[i][2], DP[i-b][2]);
        }
        DP[i][0] = DP[i][1];
        mod_add(DP[i][0],DP[i][2]);
    }
    out(DP[n][0]);
    printf("\n");
}
int main()
{
    DP[0][0] = 1;
    //std::ios::sync_with_stdio(false);
    scan_d(T);
    while(T--)
    {
        scan_d(a);
        scan_d(b);
        scan_d(n);
        sum = 0;
        solve();
    }
    //system("pause");
}

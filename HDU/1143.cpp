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
using namespace std;

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}

int DP[33][3],n;
void init()
{
    DP[0][2] = DP[0][0] = DP[1][1] = 1;
    for(int i=2;i<=30;i++)
    {
        DP[i][0] = DP[i-1][1] + DP[i-2][2] + DP[i-2][0];
        DP[i][1] = DP[i-1][2];
        DP[i][2] = DP[i][0] + DP[i-1][1];
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    init();
    while(cin>>n && n!=-1)
    {
        cout << DP[n][0] << endl;
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

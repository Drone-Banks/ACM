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

int N,M;
int cal(int m, int n)
{
    if(m==0) return 1;
    if(n==0) return 0;
    if(m<n) return cal(m,m);
    else
    {
        return cal(m,n-1)+cal(m-n,n);
    }
}

void solve()
{
    cout << cal(M,N) << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> M >> N;
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

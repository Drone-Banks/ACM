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
#define INF 1E9
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
int N,M; 

int main()
{
    //std::ios::sync_with_stdio(false);
    LL l1 = 0,r1 = INF, l2=0, r2=INF,a,b;
    scanf("%d", &N);
    while(N--)
    {
        scanf("%lld%lld", &a, &b);
        l1 = max(l1, a);
        r1 = min(r1,b);
    }
    scanf("%d", &M);
    while(M--)
    {
        scanf("%lld%lld", &a, &b);
        l2 = max(l2,a);
        r2 = min(r2,b);  
    }
    LL ans = 0;
    
    ans = max(l2-r1, max( ans, l1-r2));
    printf("%lld\n", ans);
    //system("pause");
}
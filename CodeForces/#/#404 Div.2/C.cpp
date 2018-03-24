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
LL n,m;
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%lld%lld", &n, &m);
    LL ans = n+m;
    if(n<=m) ans = n; 
    else
    {
        LL l = 0, r = n;
        while(l<=r)
        {
            LL mid = (l+r)/2;
            LD cnt = 0.5*Sqr((LD)mid)+1.5*(LD)mid-(LD)(n-m-1); 
            //debug(cnt);
            if(cnt>=0) 
            {
                ans = min(ans,mid+m+1);
                r = mid-1;
            }
            else l = mid+1;
        }
    }
    cout << ans<< endl;
   // system("pause");
}
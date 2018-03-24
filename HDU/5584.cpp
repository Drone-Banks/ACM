/*************************************************************************
	> File Name: L.cpp
	> Author: Akira
	> Mail: qaq.febr2.qaq@gmail.com
	> Created Time: 2017年05月06日 星期六 14时00分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<cmath>
#include<vector>
#include<set>
#include<list>
#include<ctime>
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
const int mod = 1e9+7;
const int eps = 1e-8;
#define bug cout << 88888888 << endl;

int T;

LL ex, ey;

int ans;
//前面小，后面大
//
LL gcd(LL a, LL b)
{
    return b==0?a:gcd(b,a%b);
}

void find(LL x, LL y)
{
    if(!x||!y) return;
    if(x==y) return;

    LL Gcd = gcd(x,y);
    
    LL z = x*y/(x+Gcd);
    
    if( x*(y-z)/gcd(x,y-z) != z ) return;
    else 
    {
        ans++;
        LL newx = min(x, y-z);
        LL newy = max(x, y-z);
        find(newx, newy);
    }
}

int main()
{
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
    {
        ans = 1;
        scanf("%lld%lld", &ex, &ey);


        if(ex>ey) swap(ex, ey);
        find(ex, ey);
        
        
        printf("Case #%d: %d\n",  t , ans);
    }
}

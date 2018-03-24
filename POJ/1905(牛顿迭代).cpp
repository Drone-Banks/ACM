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

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-12;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
inline int max2(int a, int b) {return ((a > b)? a : b);}
inline int min2(int a, int b) {return ((a < b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}
inline int min3(int a, int b, int c) {return min2(a, min2(b, c));}

double lp,n,c,l,rp,r;
double Newton()
{
    lp = (1 + n * c) * l;
    r = lp * lp * 0.25 / sqrt(lp * lp - l * l);
    do
    {
        double temp = lp / (2 * r);
        rp = r;
        r += r * (l - 2 * r * sin(temp)) / (l - lp * cos(temp));
    }
    while(fabs(r - rp) > r * eps);
    printf("%.3f\n", r - sqrt(r * r - l * l * 0.25));
}
int main()
{
    while(~scanf("%lf%lf%lf",&l,&n,&c)&& (l!=-1))
    {
        Newton();  
    }    
    return 0;
} 
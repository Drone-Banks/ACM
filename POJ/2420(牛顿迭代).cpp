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
const double eps = 1e-2;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
inline int max2(int a, int b) {return ((a > b)? a : b);}
inline int min2(int a, int b) {return ((a < b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}
inline int min3(int a, int b, int c) {return min2(a, min2(b, c));}

int N;
struct Point
{
    double x,y;
    Point(){}
    Point(int x,int y):x(x),y(y){}
}p[110];
int dir[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
double getdis(Point a, Point b)
{
    return sqrt(Sqr(a.x-b.x)+Sqr(a.y-b.y));
}
double alldis(Point a)
{
    double tmp = 0;
    for(int i=1;i<=N;i++) tmp += getdis(a, p[i]);
    return tmp;
}
void solve()
{
    Point c = p[0];
    //c.x = 0.0, c.y = 0.0;
    //for(int i=1;i<=N;i++) c.x+=p[i].x, c.y+=p[i].y; c.x/=N, c.y/=N;
    double pre,step = 100;
    pre = alldis(c);
    while(step>eps)
    {
        bool flag = true;
        for(int i=0;i<8;i++)
        {
            double x = c.x+step*dir[i][0];
            double y = c.y+step*dir[i][1];
            double cnt = alldis(Point(x,y));
            if(cnt<pre)
            {
                pre = cnt;
                c = Point(x,y);
                flag = false;
            }
        }
        if(flag) step/=2;
    }
    printf("%.0f\n",pre);
}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &N))
    {
        for(int i=1;i<=N;i++) scanf("%lf%lf", &p[i].x, &p[i].y);
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}
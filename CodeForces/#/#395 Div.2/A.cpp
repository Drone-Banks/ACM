/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 100000
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

int n,m,z;

int gcd(int a, int b)
{
    return b==0?a:gcd(b, a%b);
}
int lcm(int a, int b)
{
    return a/gcd(a,b)*b;
}

int main()
{
    while(~scanf("%d%d%d", &n,&m,&z))
    {
        int cnt = lcm(n,m);
        int ans = z/cnt;
        printf("%d\n", ans);
    }
    //system("pause");
}
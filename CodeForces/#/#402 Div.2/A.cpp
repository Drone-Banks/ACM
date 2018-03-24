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
int n;
int a[6];
int b[6];
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &n))
    {
        CLR(a);CLR(b);
        int x;
        for(int i=0;i<n;i++)
        {
            scanf("%d", &x);
            a[x]++;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d", &x);
            b[x]++;
        }
        int sum = 0;
        int ans = 0;
        for(int i=1;i<=5;i++)
        {
            if(abs(a[i]-b[i])&1)
            {
                sum = -1;
                break;
            }
            sum += ( (a[i]-b[i])/2 );
            ans += abs( (a[i]-b[i])/2 );
        }
        if(sum==0) printf("%d\n", ans/2);
        else puts("-1");
    }
    //system("pause");
}

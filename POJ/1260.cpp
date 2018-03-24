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
LL T;
LL c;
LL A[MaxN];
LL P[MaxN];
LL sum[MaxN];
LL DP[MaxN];

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &c);
        for(int i=1;i<=c;i++) 
        {
            scanf("%lld%lld", &A[i], &P[i]);
            sum[i] =  A[i] + sum[i-1];
        }

        for(int i=1;i<=c;i++)
        {
            DP[i] = (sum[i]+10)*P[i];
            for(int j=1;j<i;j++)
            {
                DP[i] = MIN(DP[i], (sum[i]-sum[j]+10)*P[i] + DP[j]);
            }
        }
        printf("%lld\n", DP[c]);

    }
    system("pause");
}
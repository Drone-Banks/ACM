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

#define MaxN 21
#define MaxM 15001
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

template<typename _> inline void scan(_& t)
{
    int c;
    while((c = getchar()) < '0' || c > '9');
    t = c - '0';
    while((c = getchar()) >= '0' && c <= '9') t = t * 10 + c - '0';
}
template<typename _> inline void print(_ x)
{
    int len = 0, p[20];
    if(x < 0) putchar('-'), x = -x;
    while(x) p[++len] = x % 10, x /= 10;
    if(!len) p[++len] = 0;
    while(len) putchar(p[len--] + '0');
}

int C,G;
int X[MaxN];
int W[MaxN];
int DP[2][MaxM];
void solve()
{
    DP[0][7500] = 1;
    int flag = 0;
    for(int i=1;i<=G;i++)
    {
        CLR(DP[flag^1]);
        for(int j=0;j<=15000;j++)
        {
            if(DP[flag][j])
            {
                for(int k=1;k<=C;k++)
                {
                    DP[flag^1][j+W[i]*X[k]] += DP[flag][j];
                }
            }
        }
        flag^=1;
    }
    print(DP[flag][7500]);
    cout << endl;
}

int main()
{
    scanf("%d%d", &C, &G);
    for(int i=1;i<=C;i++) scanf("%d", &X[i]);
    for(int i=1;i<=G;i++) scanf("%d", &W[i]);
    solve();
    system("pause");
}

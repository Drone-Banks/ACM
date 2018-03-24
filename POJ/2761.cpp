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

#define MaxN 100000
#define MaxM MaxN*10
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
int n,m;
int sorted[MaxN];
int tree[17][MaxN];
int toleft[17][MaxN];
void Build(int l, int r,int deep)
{
    if(l==r) return;
    int mid = (l+r)>>1;
    int same = mid-l+1;
}
int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &sorted[i]);
            tree[0][i] = sorted[i];
        }
        sort(sorted+1, sorted+1+n);
        Build(1,n,0);
    }
    //system("pause");
}

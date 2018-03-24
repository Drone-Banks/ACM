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

#define MaxN 13
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
int loc[1<<13];
int edge[MaxN];
int ans = 0;
void dfs(int u, int stat)
{
    if( !stat ) ans += (edge[u]&1);
    else
    {
        int rest = stat & edge[u];
        while(rest)
        {
            int v = rest&(-rest);
            dfs(loc[v], stat-v);
            rest -= v;
        }
    }
}
void solve()
{
    dfs(1, (1<<n)-2);
    print(ans);
    cout << endl;
}

int main()
{
    scan(n);scan(m);
    for(int i=0;i<n;i++) loc[1<<i] = i+1;
    while(m--)
    {
        int a,b;
        scan(a);scan(b);
        edge[a] |= 1 << (b-1);
    }
    solve();
    system("pause");
}
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
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 14
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
int nums[1<<MaxN];
int edge[MaxN];
int DP[MaxN][(1<<MaxN)];
void init()
{
    for(int i=0;i<(1<<n);i++)
    {
        int tmp = 0;
        int x = i;
        while(x)
        {
            tmp ++;
            x&=(x-1);
        }
        nums[i] = tmp;
    }
}

void solve()
{
    init();
    DP[1][(1<<n)-2] = 1;
    for(int t=n-1;t>=0;t--)
    {
        for(int stat=0;stat<(1<<n);stat++)
        {
            if(nums[stat] == t)
            {
                //cout << bitset<8>(stat) << endl;
                for(int j=1;j<=n;j++)
                {
                    for(int i=1;i<=n;i++)
                    {
                        if( j!=i && (edge[j]&(1<<(i-1))) &&  (stat&(1<<(i-1)))==0 ) 
                            DP[i][stat] += DP[j][stat+(1<<(i-1))];
                    }
                } 
            }  
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        if(edge[i]&1)ans += DP[i][0];
    }
    print(ans);
    cout << endl;
}

int main()
{
    scan(n);scan(m);
    while(m--)
    {
        int a,b;
        scan(a);scan(b);
        edge[a] |= 1 << (b-1);
    }
    solve();
    system("pause");
}
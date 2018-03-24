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

int N,M;
int Map[101];
char str[10];
int cnt;
int way[66];
int num[66];
int Legal[101][66];
int DP[2][66][66];
int Count(int x)
{
    int tmp = 0;
    while(x)
    {
        tmp++;
        x &= (x-1);
    }
    return tmp;
}
bool check(int a, int x)
{
    if( (Map[a]&x) != x || (x&(x<<1)) != 0 || (x&(x<<2)) !=0 ) return 0;
    else return 1;
}
void init()
{
    cnt = 0;
    for(int i=0; i< (1<<M); i++)
    {
        if( (i&(i<<1)) != 0 || (i&(i<<2)) !=0 ) continue;
        way[cnt] = i;
        num[cnt++] = Count(i);
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<cnt;j++)
        {
            if(check(i,way[j])) Legal[i][j] = num[j];
        }
    }
}

void solve()
{
    init();
    int flag = 0;
    for(int i=1;i<=N;i++)
    {
        //CLR(DP[flag^1]);
        for(int j=0;j<cnt;j++)
        {
            int tmp = Legal[i][j];
            for(int k=0;k<cnt;k++)
            {
                for(int l=0;l<cnt;l++)
                {
                    if( (way[j]&way[k]) == 0 && (way[j]&way[l]) == 0 ) DP[flag][j][k] = MAX(DP[flag][j][k], DP[flag^1][k][l]+tmp);
                }
            }
        }
        flag^=1;
    }
    int ans = 0;
    for(int j=0;j<cnt;j++)
    {
        for(int k=0;k<cnt;k++)
        {
            ans = MAX(ans, DP[flag^1][j][k]);
        }
    }
    cout << ans <<endl;
}

int main()
{
    scan(N);scan(M);
    for(int i=1;i<=N;i++) 
    {
        scanf("%s", str);
        for(int j=0;j<M;j++)
        {
            int x;
            if(str[j] == 'P') x = 1;
            else x = 0;
            Map[i] = (Map[i]<<1) + x;
        }
    }
    solve();
    system("pause");
}

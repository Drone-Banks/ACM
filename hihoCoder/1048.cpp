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
const int MOD = 1000000007;
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

int N, M;
int DP[2][(1<<10)+1];

void solve()
{
    int l = (1<<M)-1;
    int len =  1 << (2*M);
    DP[0][0] = 1;
    int flag = 0;
    for(int i=0;i<N;i++)
    {
        CLR(DP[flag^1]);
        for(int j=0;j<M;j++)
        {
            for(int s=0;s<len;s++)
            {
                if( ((1<<j)&s)==0 ) 
                {
                    if( j!=M-1 && ((1<<(j+1))&s)==0  )
                        DP[flag][s|(1<<j)|(1<<(j+1))] = (DP[flag][s|(1<<j)|(1<<(j+1))] + DP[flag][s])%MOD;
                    DP[flag][s|(1<<(j+M))|(1<<j)] = (DP[flag][s|(1<<(j+M))|(1<<j)] + DP[flag][s])%MOD;
                }
            }
        }
        for(int s=0;s<len;s++) 
                if( (s&l) == l ) 
                    DP[flag^1][s>>M]=DP[flag][s];
        flag^=1;  
    }
    print(DP[flag^1][l]);
    cout << endl;
}
int main()
{
    scan(N);scan(M);
    solve();
    system("pause");
}

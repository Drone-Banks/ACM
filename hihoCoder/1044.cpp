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
// 快速读入输出
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


int N,M,Q;
int A[MaxN];
int DP[2][1<<10];
int num[1<<10];

int get(int pos, int flag)
{
    int v = pos>>1;
    if(num[v]<Q)
        return MAX(DP[flag][v+(1<<(M-1))], DP[flag][v]);
    if(num[v]==Q)
        return DP[flag][v];
}
int cal(int x)
{
    int ans = 0;
    while(x)
    {
        if(x&1) ans+=1;
        x>>=1;
    }
    return ans;
}
void solve()
{
    int len = 1<<M;
    for(int i=0;i<len;i++) num[i] = cal(i);

    int flag = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<len;j+=2)
        {
            if(num[j]>Q) 
            {
                DP[flag][j] = DP[flag][j+1] = 0;
                continue;
            }
            else if(num[j] == Q)
            {
                DP[flag][j] = get(j, flag^1);
                DP[flag][j+1] = 0;
                continue;
            }
            else
            {
                DP[flag][j] = DP[flag][j+1] = get(j, flag^1);
                DP[flag][j+1] += A[i];
            }
        }
        flag^=1;
    }
    int ans = 0;
    for(int i=0;i<len;i++) ans = MAX(ans, DP[flag^1][i]);
    print(ans);
    cout << endl;
}

int main()
{
    scan(N);
    scan(M);
    scan(Q);
    for(int i=0;i<N;i++) scan(A[i]);
    solve();
    system("pause");
}

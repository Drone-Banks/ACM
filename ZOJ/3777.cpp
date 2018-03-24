/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include<bits/stdc++.h>
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
int T;
int N, M;
int val[13][13];
int fac[13];
int p[1<<13];
void init()  
{  
    fac[0] = 1;  
    for(int i = 1; i <= 12; i++)  fac[i] = fac[i-1] * i; 
    for(int i=0;i<(1<<N);i++) 
    {
        int tmp = 0;
        int x = i;
        while(x)
        {
            tmp++;
            x &= (x-1);
        }
        p[i] = tmp;
    }
}
int gcd(int a, int b) {return b == 0 ? a : gcd(b, a%b);  }
int DP[(1<<13)-1][600];

void solve()
{
    init();
    int flag = 0;
    CLR(DP);
    DP[0][0] = 1;
    for(int s=0;s<(1<<N);s++)
    {
        for(int j=0;j<N;j++)
        {
            if( (s & (1<<j))==0)
            {
                for(int k = 0; k <= M; ++k) 
                {
                    if(DP[s][k]) 
                    {
                        int tmp = MIN(k + val[p[s]][j], M);
                        DP[s|(1<<j)][tmp] += DP[s][k];
                    }
                }
            }
        }
    }
    int ans = DP[(1<<N)-1][M];
    if(ans == 0) puts("No solution");
    else 
    {
        int tmp = fac[N];
        int g = gcd(ans, tmp);
        printf("%d/%d\n", tmp/g, ans/g);
    }
}
int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &N, &M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                scanf("%d", &val[i][j]);
            }
        }
        solve();
    }
    system("pause");
}

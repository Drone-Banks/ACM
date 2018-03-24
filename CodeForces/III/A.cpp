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
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define pb push_back
using namespace std;

#define MaxN 2501
#define MaxM 5005
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
inline int max2(int a, int b) {return ((a > b)? a : b);}
inline int min2(int a, int b) {return ((a < b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}
inline int min3(int a, int b, int c) {return min2(a, min2(b, c));}
const int NICO = 2500 + 10;
int prime[NICO+1];

void getPrim()
{
    CLR(prime);
    for(int i=2;i<NICO;i++)
    {
        if(!prime[i])
        {
           prime[++prime[0]] = i;
        }
        for(int j=1;(j<=prime[0])&&(prime[j]<=(NICO/i));j++)
        {
            prime[prime[j]*i] = 1;
            if(i%prime[j]==0) break;
        }
    }
}
int n,m;
char str[MaxN];
int MAXX,dp[MaxN][MaxN];
int check(int k)
{
    int i=k,j=k;
    int ans = 0, area = k*k;
    for(i=k;i<=n;i+=k)
    {
        for(j=k;j<=m;j+=k)
        {
            int tot = dp[i][j] - dp[i-k][j] - dp[i][j-k] + dp[i-k][j-k];
            int tmp = min(tot, area-tot);
            ans += tmp;
        }
    }
    i-=k;j-=k;
    if(i<n || j<m)
    {
        int jj = m/k*k;
        for(int x=k;x<=jj;x+=k)
        {
            int tot = dp[n][x] - dp[n][x-k] - dp[i][x] + dp[i][x-k];
            int tmp = min(tot, area-tot);
            ans += tmp;
        }
        int ii = n/k*k;
        for(int y=k;y<=ii;y+=k)
        {
            int tot = dp[y][m] - dp[y][jj] - dp[y-k][m] + dp[y-k][jj];
            int tmp = min(tot, area-tot);
            ans += tmp;
        }
        int tot = dp[n][m] - dp[n][jj] - dp[ii][m] + dp[ii][jj];
        int tmp = min(tot, area-tot);
        ans += tmp;
    }
    return ans;
}
 
void solve()
{
    int ans = INF;
    // for(int k=2;k<=MAXX;k++)
    for(int k=1;k<=prime[0] && prime[k]<=MAXX;k++)
    {
        // int tmp = check(k);
        int tmp = check(prime[k]);
        ans = min2(ans, tmp);
    }
    printf("%d\n", ans);
}

int main()
{
    getPrim();
    while(~scanf("%d%d",&n, &m))
    { 
        MAXX = max(n,m);
        for(int i=1;i<=n;i++) 
        {
            scanf("%s", &str);
            for(int j=1;j<=m;j++)
            {
                dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + (int)(str[j-1]-'0');
            }
        }
        solve();
    }
}

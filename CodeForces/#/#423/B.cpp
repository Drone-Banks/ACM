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
using namespace std;

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
int n,m;
char str[110][110];
void solve()
{
    int up,down,left,right;
    up = left = 110, down = right = 0;
    int cnt = 0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        if(str[i][j]=='B')
        {
            //debug(cnt);
            cnt++;
            up = min(i,up);
            left = min(j,left);
            down = max(i,down);
            right = max(j,right);
        }
    }
    if(cnt==0) puts("1");
    else
    {
        int side = max( (down-up), (right-left) )+1, ans;
        if( side > n || side > m) ans = -1;
        else  ans = Sqr(side) - cnt;
        printf("%d\n", ans);
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &m))
    {
        for(int i=1;i<=n;i++) scanf("%s", str[i]+1);
        solve();
    }

    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

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

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
LL N;
void solve()
{
    int len = INF;
    for(LL i=1;i*i<=N;i++)
    {
        if( N%i == 0)
        {
            LL cnt = N/i;
            int tmp = 0;
            while(cnt)
            {
                cnt/=10;
                tmp++;
            }
            len = min(len,tmp);
        }
    }
    printf("%d\n", len);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%lld",&N);
    solve();
    //system("pause");
}

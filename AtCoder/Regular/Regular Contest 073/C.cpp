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

#define MaxN 200001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
int N;
LL T;
LL t[MaxN];
void solve()
{
    LL ans = 0;
    LL s = 0, e = 0;
    for(int i=1;i<=N;i++)
    {
        if(t[i]>e) 
        {
            ans += (e-s);
            s = t[i]; 
            e = t[i]+T;
        }
        else e = t[i]+T;
    }
    ans += e-s;
    printf("%lld\n", ans);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d%lld",&N, &T);
    for(int i=1;i<=N;i++) scanf("%lld", &t[i]);
    solve();
    system("pause");
}

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
template<typename T> T abs(T val){return val>0?val:-val;}
int N,P,A[55];
int odd,even;
LL F[55];
void solve()
{
    if(P)
    {
        if(odd==0) cout << 0 << endl;
        else 
        {
            LL ans = F[max(0,odd-1)]*F[even];
            cout << ans << endl;
        }
    }
    else
    {
        if(even==0 && odd == 1) cout << 0 << endl;
        else
        {
            LL ans = F[max(0,odd-1)]*F[even];
            cout << ans << endl;
        }
           
    }
}
void init()
{
    F[0] = 1;
    for(int i=1;i<=50;i++) F[i] = F[i-1]*2;
}
int main()
{
    std::ios::sync_with_stdio(false);
    init();
    while(cin >> N >> P)
    {
        odd = even = 0;
        for(int i=1;i<=N;i++)
        {
            int x;
            cin >> x;
            if(x&1) odd++;
            else even++;
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

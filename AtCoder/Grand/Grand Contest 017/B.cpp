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
int N;
LL A,B,C,D;
void solve()
{
    LL AB = abs(A-B);
    LL d = N-1;
    LL MIN = d*C, MAX = d*D;
    if( MIN <= AB && MAX >= AB ) puts("YES");
    else if( MAX < AB) puts("NO");
    else
    {
        bool flag = false;
        for(int i=1;i<d;i++)
        {
            LL tmp = 1LL*i*C + AB;
            MAX = (d-i)*D;
            MIN = (d-i)*C;
            if(tmp>MAX) break;
            else if(tmp>=MIN)
            {
                flag = true;
                break;
            }
        }
        for(int i=1;i<d;i++)
        {
            LL tmp = 1LL*i*D + AB;
            MAX = (d-i)*D;
            MIN = (d-i)*C;
            if(tmp>MAX) break;
            else if(tmp>=MIN)
            {
                flag = true;
                break;
            }
        }
        if(flag) puts("YES");
        else puts("NO");
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%lld%lld%lld%lld", &N, &A, &B, &C, &D))
    {
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

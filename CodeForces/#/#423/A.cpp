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

#define MaxN 200001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}

int n,a,b,t[MaxN];

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d%d", &n, &a, &b))
    {
        int one_0 = a, two_0 = b, two_1 = 0,ans = 0;
        for(int i=1;i<=n;i++) scanf("%d", t+i);
        for(int i=1;i<=n;i++)
        {
            if(t[i]==1)
            {
                if(one_0) one_0--;
                else if(two_0) two_0--, two_1++;
                else if(two_1) two_1--;
                else ans++;
            }
            else
            {
                if(two_0) two_0--;
                else ans+=2;
            }
        }
        printf("%d\n", ans);
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

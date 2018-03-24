/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
#include <climits>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))

using namespace std;

#define MaxN 1000001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}

int n,m;
LL fac[MaxN];
void init()
{
    fac[0] = fac[1] = 1;
    for(int i=2;i<=1000000;i++) fac[i] = (fac[i-1]*i)%mod;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    init();
    while(~scanf("%d%d", &n, &m))
    {
        vector<int> a[m];
        for(int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d", &x);
            while(x--)
            {
                scanf("%d", &y);
                a[y-1].push_back(i);
            }
        }
        for(int i=0;i<m;i++) sort(a[i].begin(), a[i].end());
        sort(a,a+m);
        LL ans = 1,num = 1;
        for(int i=1;i<m;i++)
        {   
            if(a[i]==a[i-1]) num++;
            else ans = ans*fac[num]%mod, num = 1;
        }
        ans = ans*fac[num]%mod;
        printf("%lld\n", ans);
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}
    
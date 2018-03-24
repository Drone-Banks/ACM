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

#define MaxN 1005
#define MaxM MaxN*MaxN
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

int n,k,x;
vector<int> V;
int DP[MaxM];
void solve()
{
    sort(V.begin(), V.end());
    int mn = V[0];
    for(int i=0;i<V.size();i++) V[i] -= mn;
    V.erase(unique(V.begin(),V.end()),V.end()); 
    int mx = k*V.back();
    fill_n(DP,mx+10,k+1);
    DP[0] = 0;
    for(int i=0;i<V.size();i++)
    {
        int x = V[i];
        if(x==0) continue;
        for(int j=0;j<=mx-x;j++)
        {
            DP[j+x] = min(DP[j+x], DP[j]+1);
        }
    }
    bool flag = true;
    for(int i=0;i<=mx;i++)
    {
        if(DP[i]<=k)
        {
            if(flag) flag = false;
            else printf(" ");
            printf("%d", i+mn*k);
        }
    }
    puts("");
}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &k))
    {
        V.clear();
        for(int i=0;i<n;i++) 
        {
            scanf("%d", &x);
            V.push_back(x);
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

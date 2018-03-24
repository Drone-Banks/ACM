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
inline int max2(int a, int b) {return ((a > b)? a : b);}
inline int min2(int a, int b) {return ((a < b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}
inline int min3(int a, int b, int c) {return min2(a, min2(b, c));}
LL n,S;
int digits[20];
LL Pow[20];
LL DP[20][22][200];

LL dfs(int pos, int dif, int sum, LL tar, bool limit)
{
    if(pos==0)
    {
        if (sum+S==tar && (dif-10)>=0) return 1;
        else return 0;
    }
    if(!limit && DP[pos][dif][sum]!=-1) return DP[pos][dif][sum];
    int Max = limit ? digits[pos] : 9;
    LL ans = 0;
    for(int i=0;i<=Max;i++)
    {
        int x = (dif-10)*10+i - tar/Pow[pos-1]%10;
        if(x>10) x = 10;
        if(x<-10) x = -10;
        ans += dfs(pos-1, x+10, sum+i, tar, limit&&(i==digits[pos]) );
    }
    if(!limit) DP[pos][dif][sum] = ans;
    return ans;
}

LL find(LL x)
{
    int pos = 0;
    while(x)
    {
        digits[++pos] = x%10;
        x/=10;
    }
    LL ans = 0;
    for(int i=0;i<=162;i++)
    {
        MST(DP,-1);
        LL tar = i+S;
       // debug(tar) debug(n)
        if(tar>n) break;
        ans += dfs(pos, 10, 0, tar, true);
    }
    return ans;
}
void solve()
{
    printf("%lld\n", find(n));
}
int main()
{
    
    Pow[0] = 1;
    for(int i=1;i<=20;i++) Pow[i] = Pow[i-1]*10;
    //std::ios::sync_with_stdio(false);
    scanf("%lld%lld", &n, &S);
    solve();
    system("pause");
}

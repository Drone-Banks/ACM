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

#define MaxN 5005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
int n;
char str[MaxN];
short dp[MaxN][MaxN];
void solve()    
{
    CLR(dp);
    for(int len=1;len<n;len++)
    {
        for(int i=1;i<=n-len;i++)
        {
            int j = i+len;  
            //debug(str[i])debug(str[j])
            if(str[i] == str[j])
            {
                dp[i][j] = dp[i+1][j-1];
            }
            else
            {
                dp[i][j] = min(dp[i][j-1], dp[i+1][j])+1;
            }   
            //cout << j << "-"<<i<<" : " << dp[j][i] << endl;
        }
    }
    printf("%d\n", dp[1][n]);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(scanf("%d",&n)!=EOF)
    {

        scanf("%s",str+1);
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

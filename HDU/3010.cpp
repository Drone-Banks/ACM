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

#define MaxN 1002
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
const int P = 20090818;
int N,M;

int DP[MaxN];
int C[MaxN][MaxN];
void init()
{
    for(int i=0;i<=1000;i++) C[i][0]=C[i][i] = 1;
    DP[0] = 1, DP[1] = 0, DP[2] = 1;
    for (int i = 2; i <= 1000; i++) //1e6以内的组合数
    {
        for(int j=1;j<i;j++)
        {
            C[i][j] = (C[i-1][j]+C[i-1][j-1])%P;
        }
        if(i>2) DP[i] = (LL)(i-1)*((DP[i-1]+DP[i-2])%P)%P;
    }  
}

int main()
{
    //std::ios::sync_with_stdio(false);
    init();
    while(~scanf("%d%d",&N,&M))
    {
        int ans = 0;
        for(int i=0;i<=M;i++)
        {
            ans += ( C[N][i]*(LL)DP[N-i] )%P;
            if(ans>P) ans%=P;
        }
        printf("%d\n",ans);
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

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

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3fffffff
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}

int dp[110][110],choose[110][110];
char str[110];
int len;
void init()
{
    len = strlen(str);
    for(int i=0;i<len;i++) dp[i][i] = 1,dp[i+1][i] = 0;
}
void printstr(int l,int r)
{
    if(l>r) return;
    if(l==r)
    {
        if(str[l]=='(' || str[l]==')') printf("()");
        else printf("[]");
    }
    else
    {
        if(choose[l][r]==-1)
        {
            printf("%c",str[l]);
            printstr(l+1,r-1);
            printf("%c",str[r]);
        }
        else
        {
            printstr(l,choose[l][r]);
            printstr(choose[l][r]+1,r);
        }
    }
}
void solve()
{
    init();
    for(int p=1;p<len;p++)
    {
        for(int i=0,j=i+p;j<len;i++,j++)
        {
            dp[i][j] = INF,choose[i][j]=-1;
            if ((str[i] == '(' && str[j] == ')') ||
                    (str[i] == '[' && str[j] == ']')) 
            {
                dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
            }
            for(int k=i;k<j;k++)
            {
                if(dp[i][j] > dp[i][k]+dp[k+1][j])
                {
                    dp[i][j] = dp[i][k]+dp[k+1][j];
                    choose[i][j] = k;
                }
            }
        }
    }
    //printf("%d\n",dp[0][len-1]);
    printstr(0,len-1);
    printf("\n");
}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(gets(str)) solve();
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

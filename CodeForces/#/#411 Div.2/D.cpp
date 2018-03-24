/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
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

#define MaxN 1000000+10
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;

char str[MaxN];

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%s", str))
    {
        int len = strlen(str);
        int zenfu = 0;
        int ans = 0;
        for(int i=len-1;i>=0;i--)
        {
            if(str[i] == 'b') zenfu++;
            else 
            {
                ans+=zenfu;
                if(ans>mod) ans%=mod;
                zenfu*=2;
                if(zenfu>mod) zenfu%=mod;
            }
        }
        printf("%d\n", ans%mod);
    }
    //system("pause");
}

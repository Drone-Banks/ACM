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

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;;

int T;
int n,k;

int F[10010][6];

int main()
{
    scanf("%d", &T);
    for(int i=1;i<=10000;i++)
    {
        for(int j=0;j<=5;j++)
        {
            LL cnt = 1;
            for(int l=1;l<=j;l++)
            {
                cnt*=i;
                if(cnt>mod) cnt%=mod;
            }
            F[i][j] = cnt;
        }
    }

    while(T--)
    {
        scanf("%d%d", &n, &k);
        int sum = 0;
        for(int i=1;i<=n;i++)
        {
            sum += F[i][k];
            if(sum>mod) sum%=mod;
        }
        printf("%d\n", sum);
    }

}
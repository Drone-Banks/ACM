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

#define MaxN 500
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
int n,t[MaxN][MaxN]; //原矩阵
int a[MaxN][MaxN]; //以i,j结束的矩阵的最大字矩阵和
void MaxMatrixSum()
{
    CLR(a);
    int mx=0;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
            a[i][j]+=t[i][j]+a[i-1][j]; 
        for (int j=1; j<=i; j++)
        {
            int sum=0;
            for (int k=1; k<=n; k++)
            {
                if (sum<0)
                    sum=a[i][k]-a[j-1][k];
                else
                    sum+=a[i][k]-a[j-1][k];
                mx=max(mx,sum);
            }
        }
    }
    printf("%d\n",mx);
}
int main()
{
    while(~scanf("%d",&n))
    {
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                scanf("%d",&t[i][j]);
        MaxMatrixSum();
    }
    return 0;
}
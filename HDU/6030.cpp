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
#define debug(x) cout << #x" = " << x << endl;
const int MatLen = 3;

int T;
LL n;

struct Mat
{
    LL mat[MatLen][MatLen];
    Mat()
    {
        CLR(mat);
    }
    void init(LL v)
    {
        for(int i=0;i<=MatLen;++i)
            mat[i][i] = v;
    }
};

Mat operator * (Mat a, Mat b)
{
    Mat c;
    for(int k=0;k<MatLen;k++)
    {
        for(int i=0;i<MatLen;i++)
        {
            for(int j=0;j<MatLen;j++)
            {
                c.mat[i][j] += a.mat[i][k]%mod * b.mat[k][j]%mod;
            }
        }
    }
    return c;
}

Mat operator^(Mat a, LL k)
{
    Mat c;
    for(int i=0;i<MatLen;i++)
    {
        for(int j=0;j<MatLen;j++)
        {
            c.mat[i][j] = (i==j);
        }
    }
    for(;k;k>>=1)
    {
        if(k&1)
            c = c*a;
        a = a*a;
    }
    return c;
}
int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld", &n);
        if(n==2) puts("3");
        else if (n==3) puts("4");
        else if(n==4) puts("6");
        else
        {
            Mat num;
            num.mat[0][0] = 1;
            num.mat[0][1] = 0;
            num.mat[0][2] = 1;

            num.mat[1][0] = 1;
            num.mat[1][1] = 0;
            num.mat[1][2] = 0;

            num.mat[2][0] = 0;
            num.mat[2][1] = 1;
            num.mat[2][2] = 0;

            Mat ans = num^(n-4);
            LL ANS = (ans.mat[0][0]*6 + ans.mat[0][1]*4 + ans.mat[0][2]*3) % mod;
            printf("%lld\n", ANS);
        }
    }
}
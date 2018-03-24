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

#define MaxN 1E18
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1234321237;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x;

//矩阵
const int MatLen = 4;//赋值
struct Mat
{
    LL mat[MatLen][MatLen];
    Mat()  
    {  
        CLR(mat);
    } 
    void init(LL v)  
    {  
        for(int i=0; i<=MatLen; ++i)  
            mat[i][i]=v;  
    } 
};

//矩阵乘法
Mat operator * (Mat a, Mat b)
{
    Mat c;
    for(int k=0;k<MatLen;k++)
    {
        for(int i=0;i<MatLen;i++)
        {
            for(int j=0;j<MatLen;j++)
            {
                c.mat[i][j] += a.mat[i][k]%mod * b.mat[k][j]%mod ;
            }
        }
    }

    return c;
}
Mat MM[100];
LL index[100];
void init()
{
    Mat num;
    num.mat[0][0] = 6, num.mat[0][1] = 1, num.mat[0][2] = 0, num.mat[0][3] = 0;
    num.mat[1][0] = -6,num.mat[1][1] = 1, num.mat[1][2] = 6, num.mat[1][3] = 0;
    num.mat[2][0] = 0, num.mat[2][1] = 0, num.mat[2][2] = 6, num.mat[2][3] = 1;
    num.mat[3][0] = 0, num.mat[3][1] = 0, num.mat[3][2] = -6,num.mat[3][3] = 1;
    index[0] = 0;
    index[++index[0]] = 1;
    MM[1] = num;
    LL i = 2;
    while(i<=MaxN)
    {
        index[++index[0]] = i;
        MM[index[0]] = MM[index[0]-1]*MM[index[0]-1];
        i*=2;
    }
}

int main()
{
    int T;
    LL n;
    scanf("%d", &T);
    init();
    while(T--)
    {
        scanf("%lld", &n);
        if(n==1) {puts("1 0");continue;}
        else n-=1;
        LL loc = index[0];
        Mat ans;
        for(int i=0;i<MatLen;i++)
        {
            for(int j=0;j<MatLen;j++)
            {
                ans.mat[i][j] = (LL)(i==j);
            }
        }
        while(n&&loc>0)
        {
            while(n>=index[loc])
            {
                ans = ans*MM[loc];
                n-=index[loc];
            }
            loc--;
        }
        LL f = ans.mat[0][0]%mod;
        if(f<0) f+=mod; 
        LL g = ans.mat[0][2]%mod;
        if(g<0) g+=mod;
        printf("%lld %lld\n",f ,g);
    }
    //system("pause");
}

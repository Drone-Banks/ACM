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

#define bug cout<<88888888<<endl;
int k,mod;
struct Mat
{
    LL mat[4][4];
    Mat()
    {
        CLR(mat);
    }
    void init(int v)  
    {  
        for(int i=0; i<=4; ++i)  
            mat[i][i]=v;  
    }  
};

//矩阵乘法
Mat operator * (Mat a, Mat b)
{
    Mat c;
    for(int k=0;k<4;k++)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                c.mat[i][j] += a.mat[i][k] %mod* b.mat[k][j] %mod;
            }
        }
    }
    return c;
}

//矩阵快速幂
Mat operator^(Mat a, long long int k)
{
    Mat c;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            c.mat[i][j] = (i==j);
        }
    }
    for(; k; k>>=1)
    {
        if(k&1)
            c = c*a;
        a = a*a;
    }
    return c;
}

int main()
{
    Mat a,b,c;  
    a.mat[0][0]=9;  
    a.mat[1][0]=6;  
    a.mat[2][0]=4;  
    a.mat[3][0]=2;    
    b.mat[0][0]=b.mat[0][2]=b.mat[0][3]=b.mat[1][0]=b.mat[2][1]=b.mat[3][2]=1;  
    while(~scanf("%d%d",&k,&mod))  
    {  
        if(k==0){  
            puts("0");  
        }  
        else if(k<=4){  
            printf("%d\n",a.mat[4-k][0]%mod);  
        }  
        else{  
            c=b^(k-4);  
            c=c*a;  
            printf("%d\n",c.mat[0][0]%mod);  
        }  
    }  
    return 0;  
}
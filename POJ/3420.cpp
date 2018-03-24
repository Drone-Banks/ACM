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
typedef long long ll;
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
template<typename T> T abs(T val){return val>0?val:-val;}

  
typedef vector<ll> vec;  
typedef vector<vec> mat;  
ll MOD;
  
mat mul(mat &A,mat &B)  
{  
    mat C(A.size(),vec(B[0].size()));  
    for(int i=0;i<A.size();i++)  
        for(int k=0;k<B.size();k++)  
            for(int j=0;j<B[0].size();j++)  
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;  
    return C;  
}  
  
mat pow(mat A, ll n)  
{  
    mat B(A.size(),vec(A.size()));  
    for(int i=0;i<A.size();i++) B[i][i]=1;  
    while(n>0)  
    {  
        if(n&1) B=mul(B,A);  
        A=mul(A,A);  
        n>>=1;  
    }  
    return B;  
}  
int k;  
ll d[22][22];  
void dfs(int x,int y,int col)  
{  
    if(col==k)  
    {  
        d[y][x]=1;  
        return;  
    }  
    dfs(x<<1,(y<<1)+1,col+1);  
    dfs((x<<1)+1,y<<1,col+1);  
    if(col+2<=k)    dfs((x<<2)+3,(y<<2)+3,col+2);  
}  
  
  
  
int main()  
{  
    ll n;  
    while(~scanf("%lld%lld",&n,&MOD) && (n+MOD))  
    {  
        k = 4;
        dfs(0,0,0);  
        ll t=1<<k;  
        mat A(t,vec(t));  
        for(int i=0;i<t;i++)  
            for(int j=0;j<t;j++)  
                A[i][j]=d[i][j];  
        A=pow(A,n); 
        printf("%lld\n",A[t-1][t-1]%MOD);  
    }  
}  
#include <iostream>  
#include<bits/stdc++.h>  
#define ll long long  
  
using namespace std;  
  
typedef vector<ll> vec;  
typedef vector<vec> mat;  
const ll MOD=12357;  
  
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
ll d[220][220];  
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
    while(~scanf("%d%lld",&k,&n))  
    {  
        dfs(0,0,0);  
        ll t=1<<k;  
        mat A(t,vec(t));  
        for(int i=0;i<t;i++)  
            for(int j=0;j<t;j++)  
                A[i][j]=d[i][j];  
        A=pow(A,n);
        printf("%lld\n",A[t-1][t-1]);  
    }  
}  
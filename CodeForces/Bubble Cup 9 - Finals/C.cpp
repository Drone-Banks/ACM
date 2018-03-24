/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 100005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
const int mod = 10007;
int n;
LL A[MaxN],B[MaxN];
int main()
{
    while(~scanf("%d", &n))
    {
        CLR(A);
        CLR(B);
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &A[i]);
        }
        sort(A+1, A+n+1);
        for(int i=1;i<=n;i++)
        {
            B[n-i+1] = A[i];
        }
        LL ans = 0;
        for(int i=1;i<=n;i++)
        {
            //cout << A[i] << "*"<< B[i]<<endl;
            ans += A[i]*B[i];
            ans%=mod;
        }
        cout << ans%mod<< endl;
    }

    //system("pause");
}
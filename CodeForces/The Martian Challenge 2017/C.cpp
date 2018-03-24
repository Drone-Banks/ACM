/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include<bits/stdc++.h>
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
int n,a,b;
int T[30];
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &n);
    int MAX = 0;
    while(n--)
    {
        scanf("%d%d", &a, &b);
        for(int i=a+1;i<=b;i++) 
        {
            T[i]++;
            MAX = max(MAX, T[i]);
        }
    }
    cout << MAX << endl;
    system("pause");
}

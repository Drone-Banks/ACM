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
char a[66],b[66];
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%s", a), scanf("%s", b);
    int la = strlen(a), lb = strlen(b);
    int len = max(la, lb);
    for(int i=0;i<len;i++)
    {
        if(i<la) putchar(a[i]);
        if(i<lb) putchar(b[i]);
    }
    puts("");
    //system("pause");
}

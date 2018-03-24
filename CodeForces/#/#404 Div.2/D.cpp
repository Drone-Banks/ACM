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
const int SIZE = 400001;
const int P = mod;
LL f[SIZE], v[SIZE];
LL rev[SIZE];
LL rp(LL now, int k) 
{
    LL will = 1;
    for (; k; k >>= 1, now *= now, now %= P) 
    {
        if (k & 1) will *= now, will %= P;
    }
    return will;
}
LL C(int n, int m) 
{
    if(n < m) return 0;
    return f[n]*rev[m]%P*rev[n-m]%P;
}
void init()
{
    f[0] = 1; v[0] = 1;
    rev[0] = 1;
    for (int i = 1; i <= SIZE; i++) //1e6以内的组合数
    {
        f[i] = f[i - 1] * i % P;
        rev[i] = rp(f[i], P-2);
    }
}
char str[200005];
int main() 
{
    init();
    scanf("%s", str);
    int Left = 0, Right = 0;
    int len = strlen(str); 
    for(int i=0;i<len;i++) if(str[i]=='(')Left++; else Right++;
    LL L=0,R=Right,ans = 0;
    for(int i=0;i<len;i++)
    {
        if(!Right) break;
        if(str[i]=='(')  L++,ans+=C(L-1+R,R-1);
        else R--;
        if(ans>mod) ans%=mod;
    }
    printf("%lld\n",ans);
    //system("pause");
}
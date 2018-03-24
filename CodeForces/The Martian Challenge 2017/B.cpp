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
int k,n,m;
int a,b;
string str;
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> k >> n >> m;
    a = 0,b = 0;
    for(int i=0;i<k;i++) 
    {
        cin >> str;
        if( str == "Mars") b++;
        else a++;
    }
    int ans = max(m-a,0); 
    int res = b + max(a - m,0); 
    ans += max( (n-res), 0);
    cout << ans << endl;
    system("pause");
}

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

#define MaxN 100000
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

LL T;
LL a,b;
LL Pow(LL x, LL a)
{
    LL ans =1;
    while(a--)
    {
        ans*=x;
    }
    return ans;
}

LL change(LL x)
{
    LL ans = 0;
    LL w = 0;
    while(x)
    {
        ans += x%10*Pow(8,w);
        w++;
        x/=10;
    }
    //cout << ans << endl;
    return ans;
}
LL back(LL x)
{
    LL ans = 0;
    LL w = 0;
    //cout << x << endl;
    while(x)
    {
        //cout << "x: " << x << endl;
        ans += x%8*Pow(10,w);
        w++;
        x/=8;
        //cout << ans << endl;
    }
    //cout << ans << endl;
    return ans;
}

void solve(LL x, LL y)
{
    int flag = 0;
    if(x<y) {swap(x,y);flag=1;}

    if(x==y) cout << 0 << endl;
    else
    {
        LL ans = back(change(x) - change(y));
        if(flag) cout << "-";
        cout << ans << endl;
    }
}


int main()
{
    scanf("%lld", &T);
    while(T--)
    {
        scanf("%lld%lld",&a,&b);
        solve(a,b);
    }
    system("pause");
}
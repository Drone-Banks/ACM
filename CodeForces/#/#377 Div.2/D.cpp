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

#define MaxN 100005
#define MaxM MaxN
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
int n,m;
int d[MaxN],a[MaxM];
int flag[MaxM];
int ans;
bool check(int loc)
{
    int num = m;
    int cost = 0;
    CLR(flag);
    for(int i=loc;i>=1;i--)
    {
        if(d[i]!=0 && flag[d[i]]==0)
        {
            cost += a[d[i]];
            flag[d[i]] = 1;
            num--;
        }
        else
        {
            if(cost) cost--;
        }
    }
    if(cost||num) return false;
    else 
    {
        ans = min(ans, loc);
        return true;
    }
}
void BinSearch(int l, int r)
{
    //cout << l << " " << r << endl;
    if(l<=r)
    {
        int mid = ((l+r)>>1);
        if(check(mid)) 
        {
            BinSearch(l, mid-1);
        }
        else BinSearch(mid+1,r);
    }
}
void solve()
{
    ans = n;
    if(check(n))
    {
        BinSearch(1,n);
        printf("%d\n",ans);
    }
    else puts("-1");
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &m))
    {
        for(int i=1;i<=n;i++) scanf("%d", &d[i]);
        for(int i=1;i<=m;i++) scanf("%d", &a[i]);
        solve();
    }
    //system("pause");
}

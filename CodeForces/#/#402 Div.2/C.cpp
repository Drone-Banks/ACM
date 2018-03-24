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

#define MaxN 200005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
int n, k;
struct Item_qaq
{
    LL a,b;
    LL d;
    bool operator < (const Item_qaq &A) const
    {
        return A.d > d;
    }
}item_qaq[MaxN];
LL ans;
void solve()
{
    sort(item_qaq, item_qaq+n);
    ans = 0;
    for(int i=0;i<n;i++)
    {
        if(item_qaq[i].d<0)
        {
            k--;
            ans+=item_qaq[i].a;
        }
        else
        {
            if(k>0)
            {
                ans+=item_qaq[i].a;
                k--;
            }
            else
            {
                ans+=item_qaq[i].b;
            }
        }
    }
    printf("%lld\n", ans);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &k))
    {
        for(int i=0;i<n;i++) scanf("%lld", &item_qaq[i].a);
        for(int i=0;i<n;i++) scanf("%lld", &item_qaq[i].b);
        for(int i=0;i<n;i++) item_qaq[i].d = item_qaq[i].a-item_qaq[i].b;
        solve();
    }
    //system("pause");
}

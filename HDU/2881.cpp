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
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 10010
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
int n,m;
struct Node
{
    int t,x,y;
}node[MaxN];
int DP[MaxN];
void LIS()
{
    int ans = -1;
    for(int i=1;i<=m;i++)
    {
        DP[i] = 1;
        for(int j=1;j<i;j++)
        {
            if(node[i].t-node[j].t >= abs(node[i].x-node[j].x)+abs(node[i].y-node[j].y))
            {
                DP[i] = max(DP[i], DP[j]+1);
            }
        }
        if(DP[i]>ans) ans = DP[i];
    }
    printf("%d\n", ans);
}
void solve()
{
    sort(node+1,node+1+m,[](Node a, Node b){return a.t<b.t;});
    LIS();
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &m) && (n+m))
    {
        int t,x,y;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d", &node[i].t, &node[i].x,&node[i].y);
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

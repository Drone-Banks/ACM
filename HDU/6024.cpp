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

int n;

struct Node
{
    LL d, c;
    bool operator<(Node &a) const
    {
        return d<a.d;
    }
}node[MaxN];

LL DP[MaxN][2];

void solve()
{

    DP[1][1] = node[1].c;
    DP[1][0] =  2*INF;
    for(int i=2;i<=n;i++)
    {
        LL all=node[i].d-node[i-1].d;
   //     cout<<all<<endl;
        DP[i][1] = min(DP[i-1][1], DP[i-1][0])+node[i].c;
        DP[i][0] = DP[i-1][1] + node[i].d - node[i-1].d;
        for(int j=i-1;j>1;j--)
        {
            all+=(node[j].d-node[j-1].d)*(i-j+1);
            //cout<< all << " " << DP[j][1] << endl;
            DP[i][0] = min(DP[i][0], DP[j-1][1]+all);
        }
    }
    //for(int i=1;i<=n;i++) cout << DP[i][1] << ' ' << DP[i][0] << endl;
    LL ans = min(DP[n][0], DP[n][1]);
    printf("%lld\n", ans);
}

int main()
{
    node[0].d = -2*INF;
    while(~scanf("%d", &n))
    {
        for(int i=1;i<=n;i++) scanf("%lld%lld", &node[i].d, &node[i].c);
        sort(node+1, node+1+n);
        solve();
    }

}
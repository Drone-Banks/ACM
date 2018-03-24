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

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}

int n, V, K;
int DP[12][10010];
struct Node
{
    int cost, weight;
    Node() {}
    Node(int a, int b):cost(a),weight(b){}
}node[MaxN];
vector<Node> B[MaxN];
void GroupPack()
{
    DP[0][0] = 0;
    for(int k=1;k<=K;k++)
    for(int i=0;i<B[k].size();i++)
    for(int v=V;v>=B[k][i].cost;v--)
    {
        if(DP[k][v-B[k][i].cost]!=-1)
            DP[k][v]=max(DP[k][v], DP[k][v-B[k][i].cost]+B[k][i].weight);
        if(DP[k-1][v-B[k][i].cost]!=-1)
            DP[k][v]=max(DP[k][v], DP[k-1][v-B[k][i].cost]+B[k][i].weight);
    }
}

void solve()
{
    MST(DP,-1);
    GroupPack();
    int ans = -1;
    for(int i=0;i<=V;i++)
    {
        if(DP[K][i]!=-1) ans = max(ans, DP[K][i]);
    }
    if(ans==-1) puts("Impossible");
    else printf("%d\n", ans);
}

int main()
{
    //freopen("input.in", "r", stdin);
    while(~scanf("%d%d%d", &n, &V, &K))
    {
        for(int i=1;i<=K;i++) B[i].clear();
        for(int i=0; i<n; i++)
        {
            int k,c,w;
            scanf("%d%d%d", &k, &c, &w);
            B[k].push_back(Node(c,w));
        }
        solve();
    }
    return 0;
}
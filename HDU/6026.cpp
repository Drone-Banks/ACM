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
char str[55][55];
int MAP[55][55];


int value[55];
int dis[55];
int vis[55];
typedef pair<int,int> pii;
struct cmp
{
    bool operator()(pii a, pii b)
    {
        return a.first>b.first;
    }
};
void Dijkstra()
{
    CLR(value);
    CLR(vis);
    for(int i=0;i<n;i++) dis[i] = INF;
    dis[0] = 0;
    priority_queue<pii, vector<pii>, cmp> Q;
    Q.push(make_pair(0,0));
    while(!Q.empty())
    {
        pii tmp = Q.top();
        Q.pop();
        
        int u = tmp.second;
        if(vis[u]) continue;
        vis[u] = 1;
        for(int v=1;v<n;v++)
        {
            if(MAP[u][v]==0 || v==u) continue;

            if( dis[v] > tmp.first + MAP[u][v])
            {
                dis[v] = tmp.first + MAP[u][v];
                Q.push(make_pair(dis[v], v));
                value[v] = 1;
            }
            else if(dis[v] == tmp.first + MAP[u][v])
            {
                value[v] ++;
            }
        }
    }
}
void solve()
{
    Dijkstra();
    LL ans = 1;
    if( dis[n-1] == INF ) ans = 0;
    else
    {
        for(int i=1;i<n;i++)
        {
            ans*=value[i];
            if(ans>mod) ans%=mod;
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s", &str[i]);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                MAP[i][j] = str[i][j] - '0';
                //cout << i  << "-" << j <<":" << MAP[i][j] <<endl;
            }
        }

        solve();
    }
}

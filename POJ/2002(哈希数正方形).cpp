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

#define MaxN 1007
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
int n;
struct Node
{
    int x,y;
    bool operator < (const Node &a) const
    {
        if(x == a.x) return y<a.y;
        else return x<a.x;
    }
}node[MaxN+5];
vector<Node> Hash[MaxN+5];

bool check(Node a)
{
    int sum = abs(a.x+a.y)%MaxN;
    if(Hash[sum].size()==0) return false;
    else
    {
        for(int i=0;i<Hash[sum].size();i++)
        {
            if(a.x == Hash[sum][i].x && a.y == Hash[sum][i].y) return true;
        }
        return false;
    }
}
void insert(Node one)
{
    int sum = abs(one.x + one.y)%MaxN;
    //debug(sum);
    Hash[sum].push_back(one);
}
void solve()
{
    sort(node,node+n);
    for(int i=0;i<n;i++) insert(node[i]);
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        { 
            Node tmp;
            tmp.x = node[i].x+node[i].y-node[j].y;
            tmp.y = node[i].y+node[j].x-node[i].x;
            if(!check(tmp)) continue;
            //debug(tmp.x) debug(tmp.y)
            tmp.x = node[j].x+node[i].y-node[j].y;
            tmp.y = node[j].y+node[j].x-node[i].x;
            if(!check(tmp)) continue;
            //debug(tmp.x) debug(tmp.y)
            ans++;
            //debug(ans)
        }
    }
    printf("%d\n", ans/2);
}
void init()
{
    for(int i=0;i<MaxN;i++) Hash[i].clear();
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &n) && n)
    {
        init();
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&node[i].x, &node[i].y);
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

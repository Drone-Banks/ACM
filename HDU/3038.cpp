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

#define MaxN 200001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T dis){return dis>0?dis:-dis;}

int N,M;

int fa[MaxN],dis[MaxN];

int find(int x)
{
    if(x == fa[x]) return x;
    else
    {
        int f = fa[x];
        fa[x] = find(fa[x]);
        dis[x] += dis[f];
        return fa[x];
    }
}

bool Union(int x, int y, int sum)
{
    int fx = find(x), fy = find(y);
    if(fx == fy)
    {
        return abs(dis[x]-dis[y])==sum;
    }
    else
    {
        fa[fx] = fy;
        dis[fx] = dis[y]+sum-dis[x];
        return true;
    }
}

void init()
{
    for(int i=0;i<=N;i++) fa[i] = i, dis[i] = 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    while(cin >> N >> M)
    {
        init();
        int a,b,sum;
        int ans = 0;
        for(int i=1;i<=M;i++)
        {
            cin >> a >> b >> sum;
            a--;
            if(!Union(a,b,sum)) ans++;
        }
        cout << ans << endl;
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

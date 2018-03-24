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
int N,m;
struct Node
{
    LL x, y, d;
}node[MaxN];

struct Yaxes
{
    LL y;
    int id;
    Yaxes(){}
    Yaxes(LL y, int id):y(y),id(id){}
    bool operator<(const Yaxes &a) const
    {
        return y<a.y;
    }
};

int vis[MaxN];
vector<LL> DSZ_x;
multiset<Yaxes> S[MaxN];
multiset<Yaxes>::iterator it,L,R;

void init()
{
    DSZ_x.clear();
    for(int i=0;i<=N;i++) S[i].clear();
    CLR(vis);
}
int ans;
void solve()
{
    int num;
    while(m--) 
    {
        ans = 0;
        scanf("%d", &num);
        num--;
        queue<int> Q;
        if(vis[num]) 
        {
            puts("0");
            continue;
        }
        while(!Q.empty()) Q.pop();
        Q.push(num);
        vis[num] = 1;
        while(!Q.empty())
        {
            ans++;
            int tmp = Q.front();
            Q.pop();
            int sx = lower_bound(DSZ_x.begin(), DSZ_x.end(), node[tmp].x-node[tmp].d)-DSZ_x.begin();
            int sy = upper_bound(DSZ_x.begin(), DSZ_x.end(), node[tmp].x+node[tmp].d)-DSZ_x.begin();
            for(int i=sx;i<sy; i++)
            {
                int rem = node[tmp].d - abs(DSZ_x[i]-node[tmp].x);
                L = S[i].lower_bound(Yaxes(node[tmp].y-rem, 0));
                R = S[i].upper_bound(Yaxes(node[tmp].y+rem, 0));
                for(it=L; it!=R; it++)
                {
                    if(vis[it->id]) continue;
                    Q.push(it->id);
                    vis[it->id] = 1;
                }
                S[i].erase(L,R);
            }
        }
        printf("%d\n", ans);
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    int t = 1;
    while(~scanf("%d", &N) && N)
    {
        init();
        for(int i=0;i<N;i++)
        {
            scanf("%d%d%d", &node[i].x, &node[i].y, &node[i].d);
            DSZ_x.push_back(node[i].x);  
        }
        sort(DSZ_x.begin(), DSZ_x.end());
        DSZ_x.erase(unique(DSZ_x.begin(), DSZ_x.end()), DSZ_x.end());
        for(int i=0;i<N;i++)
        {
            int loc = lower_bound(DSZ_x.begin(), DSZ_x.end(), node[i].x)-DSZ_x.begin();
            S[loc].insert( Yaxes(node[i].y, i));
        }
        scanf("%d", &m);
        printf("Case #%d:\n", t++);
        solve();
    }
    //system("pause");
}

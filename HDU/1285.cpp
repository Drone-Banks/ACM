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

int N,M;
bool Map[505][505];
int in[505];

void topo()
{
    priority_queue<int, vector<int>, greater<int> > Q;
    for(int i=1;i<=N;i++)
    {
        if(!in[i]) Q.push(i);
    }
    bool flag = false;
    while(!Q.empty())
    {
        int u = Q.top();
        Q.pop();
        if(flag) cout << " ";
        else flag = true;
        cout << u ;
        for(int v=1;v<=N;v++)
        {
            if(Map[u][v])
            {
                Map[u][v] = 0;
                in[v]--;
                if(!in[v])
                {
                    Q.push(v);
                }
            }
        }
    }
    cout << endl;
}
void solve()
{
    topo();
}
void init()
{
    CLR(Map);
    CLR(in);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(cin >> N >> M)
    {
        init();
        while(M--)
        {
            int u,v;
            cin >> u >> v;
            if(!Map[u][v])
            {
                Map[u][v] = true;
                in[v]++;
            }
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

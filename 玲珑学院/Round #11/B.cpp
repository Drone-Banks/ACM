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
int n;
vector<int> V[MaxN];
pair<int,int> DP[MaxN][13];
void solve()
{
    CLR(DP);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<V[i].size();j++)
        {
            for(int k=0;k<13;k++)
            {
                if(DP[i-1][k].first < V[i][j] && DP[i][j+1].second<DP[i-1][k].second+1)
                {
                    DP[i][j+1].second = DP[i-1][k].second+1;
                    DP[i][j+1].first = V[i][j];
                }
            }
        }
        for(int k=0;k<13;k++)
        {
            if(DP[i][0].second<DP[i-1][k].second)
            {
                DP[i][0].second = DP[i-1][k].second;
                DP[i][0].first = DP[i-1][k].first;
            }
            else if(DP[i][0].second==DP[i-1][k].second && DP[i][0].first > DP[i-1][k].first)
            {
                DP[i][0].first = DP[i-1][k].first;
            }
        }
        for(int j=0;j<V[i].size();j++)
        {
            DP[i][7+j].first = V[i][j];
            DP[i][7+j].second = 1;
        }
    }
    int ans = 0;
    for(int i=0;i<13;i++)
    {
        ans = max(ans, DP[n][i].second);
    }
    printf("%d\n", ans);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &n))
    {
        for(int i=1;i<=n;i++)
        {
            V[i].clear();
            int choice = 6;
            while(choice--)
            {
                int x;
                scanf("%d", &x);
                V[i].push_back(x);
            }
        }
        solve();
    }
    //system("pause");
}

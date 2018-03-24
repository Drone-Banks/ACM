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

#define MaxN 505
#define MaxM 5005
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
#define bug cout<<88888888<<endl;

int N, M;
struct Node
{
    int P,Q,V;
    bool operator <(const Node &a) const
    {
        return a.Q-a.P>Q-P;
    }
}node[MaxN];
int DP[2][MaxM];
void solve()
{
    CLR(DP);
    sort(node,node+N);
    int flag = 0;
    for(int i=0;i<N;i++)
    {
        CLR(DP[flag^1]);
        for(int j=0;j<=M;j++)
        {
            if (j >= node[i].Q)
                DP[flag^1][j] = max(DP[flag][j], DP[flag][j-node[i].P]+node[i].V);
            else
                DP[flag^1][j] = DP[flag][j];
        }
        flag^=1;
    }
    int ans = 0;
    //for(int i=0;i<=M;i++) ans = max(ans, DP[flag][i]);
    printf( "%d\n", DP[flag][M] );
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &N, &M))
    {
        for(int i=0;i<N;i++)
        {
            scanf("%d%d%d", &node[i].P, &node[i].Q, &node[i].V);
        }
        solve();
    }
    //system("pause");
}

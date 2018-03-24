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
LL val[14];
LL dp[1<<13][14][14],ways[1<<13][14][14];
bool Map[14][14];
void solve()
{
    for(int stat = 0;stat<(1<<N);stat++)
    {
        for(int i=0;i<N;i++)
        {
            if( !(stat & (1<<i)) ) continue; // i is not in the stat
            for(int j=0;j<N;j++)
            {
                if(i==j || !(stat & (1<<j)) || dp[stat][i][j]<0 ) continue;
                for(int k=0;k<N;k++)
                {
                    if( (stat & (1<<k)) || !Map[j][k] ) continue;

                    LL tmp = dp[stat][i][j] + val[k] + val[j]*val[k];
                    if(Map[i][k]) 
                        tmp += val[i]*val[j]*val[k];

                    int news = stat | (1<<k);
                    if(tmp == dp[news][j][k]) 
                        ways[news][j][k] += ways[stat][i][j];
                    else if( tmp > dp[news][j][k]) 
                        dp[news][j][k] = tmp, ways[news][j][k] = ways[stat][i][j];
                }
            }
        }
    }
    LL ans = -1, way = 0;
    int finals = (1<<N)-1;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(!Map[i][j]) continue;
            if( ans < dp[finals][i][j]) 
            {
                ans = dp[finals][i][j];
                way = ways[finals][i][j];
            }
            else if( ans == dp[finals][i][j]) 
            {
                way += ways[finals][i][j];
            }
        }
    }
    printf("%lld %lld\n", ans==-1?0:ans, way/2);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        CLR(Map);MST(dp,-1);CLR(ways);
        scanf("%d%d", &N, &M);
        for(int i=0;i<N;i++) scanf("%lld",val+i);
        int a,b;
        while(M--)
        {
            scanf("%d%d", &a, &b);
            a--;b--;
            Map[a][b] =  Map[b][a] = true;
            dp[(1<<a)|(1<<b)][a][b] = dp[(1<<b)|(1<<a)][b][a] = val[a] + val[b] + val[a]*val[b];
            ways[(1<<a)|(1<<b)][a][b] = ways[(1<<b)|(1<<a)][b][a] = 1;
        }
        if(N==1)
        {
            printf("%d 1\n",val[0]);      
        }
        else solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

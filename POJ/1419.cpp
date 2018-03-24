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

#define MaxN 110
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}

int n,m;
bool flag[MaxN], a[MaxN][MaxN];
int ans, cnt[MaxN], group[MaxN],vis[MaxN];
bool dfs( int u, int pos ){
    int i, j;
    for( i = u+1; i <= n; i++){
        if( cnt[i]+pos <= ans ) return 0;
        if( a[u][i] ){
             // 与目前团中元素比较，取 Non-N(i) 
            for( j = 0; j < pos; j++ ) if( !a[i][ vis[j] ] ) break; 
            if( j == pos ){     // 若为空，则皆与 i 相邻，则此时将i加入到 最大团中 
                vis[pos] = i;
                if( dfs( i, pos+1 ) ) return 1;    
            }    
        }
    }    
    if( pos > ans ){
            for( i = 0; i < pos; i++ )
                group[i] = vis[i]; // 最大团 元素 
            ans = pos;
            return 1;    
    }    
    return 0;
} 
void maxclique()
{
    ans=-1;
    for(int i=n;i>0;i--)
    {
        vis[0]=i;
        dfs(i,1);
        cnt[i]=ans;
    }
}
int main(){
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        int x, y;
        CLR(a);
        for (int i = 0; i < m; i++){
            scanf("%d%d", &x, &y);
            a[x][y] = a[y][x] = 1;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i == j) a[i][j] = 0;
                else    a[i][j] ^= 1;
        maxclique();
        if (ans < 0) ans = 0;
        printf("%d\n", ans);
        for (int i = 0; i < ans; i++)
            printf(i ==0?"%d" : " %d", group[i]);
        if (ans > 0) puts("");
    }
    return 0;
}
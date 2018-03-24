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

#define MaxN (1<<10)+5
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
int m,n,k;
bool tu[50][50];
bool btu[MaxN][MaxN];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int Dir[4];
bool Check(int i,int j)
{
    if( i<1 || i>m || j<1 || j>n || tu[i][j]) return false;
    else return true;
}
int matching[MaxN];
bool check[MaxN];
bool DFS(int u)
{
    for(int i=0;i<4;i++)
    {
        int v = u+Dir[i];
        if(0<v && v<=n*m && btu[u][v] && !check[v])
        {
            check[v] = true;
            if(matching[v]==-1||DFS(matching[v]))
            {
                matching[v] = u;
                matching[u] = v;
                return true;
            }
        }
        //cout << v << matching[v] << endl;
    }
    return false;
}
void Hungarian()
{
    MST(matching,-1);
    int ans = 0;
    for(int i=1;i<=m*n;i++)
    {
        if(matching[i]==-1)
        {
            CLR(check);
            if(DFS(i)) ans++;
        }
    }
    int res = m*n-k-2*ans;
    //debug(ans);
    //for(int i=1;i<=n*m;i++) cout << matching[i] << endl;
    if(res) cout << "NO\n";
    else cout << "YES\n";
}
void solve()
{
    CLR(btu);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(tu[i][j]) continue;
            int a = (i-1)*n+j;
            for(int d=0;d<4;d++)
            {
                int ii = i+dir[d][0];
                int jj = j+dir[d][1];
                if(Check(ii,jj))
                {
                    int b = (ii-1)*n+jj;
                    btu[a][b] = btu[b][a] = 1;
                }
            }
        }
    }
    Dir[0] = 1;
    Dir[1] = -1;
    Dir[2] = n;
    Dir[3] = -n;
    Hungarian();
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(cin>>m>>n>>k)
    {
        CLR(tu);
        for(int i=0;i<k;i++)
        {
            int x,y;
            cin >> x >> y;
            tu[y][x] = 1;
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

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

#define MaxN 105
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}

int n,m,k;
int matching[MaxN];
bool tu[MaxN][MaxN],check[MaxN];

bool DFS(int u)
{
    for(int v=1;v<m;v++)
    {
        if(tu[u][v] && !check[v])//要求不在交替路中
        {  
            check[v] = true; //放入交替路
            if(matching[v] == -1 || DFS(matching[v])) //如果是未覆盖点，说明交替路为增广路，则交换路径，并返回成功
            {
                matching[v] = u;
                return true;
            }
        }
    }
    return false; //不存在增广路，返回失败
}

void Hungarian()
{
    int ans = 0;
    MST(matching, -1);
    for(int u =1;u<n;u++)    //左边点的序号从1开始
    {
        CLR(check);
        if(DFS(u))
            ans++;       
    }
    cout << ans << endl;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(cin>> n && n)
    {
        cin >> m >> k;
        CLR(tu);
        while(k--)
        {
            int i,a, b;
            cin >> i >> a >> b;
            //if(a==0||b==0) continue;
            tu[a][b] = 1;
        }
        Hungarian();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

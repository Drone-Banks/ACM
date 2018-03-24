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

#define MaxN 101
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
#define bug cout<<88888888<<endl;
int n,k;
vector<int> V[MaxN];
int num[MaxN];
int check(int x)
{
    if(num[x]!=-1) return num[x];
    else
    {
        int ans = 0;
        for(int i=0;i<V[x].size();i++)
        {
            ans++;
            ans += check(V[x][i]);
        }
        return num[x]=ans;
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &k))
    {
        MST(num,-1);
        for(int i=1;i<=n;i++) V[i].clear();
        for(int i=1;i<n;i++)
        {
            int a,b;
            scanf("%d%d", &a, &b);
            V[a].push_back(b);
        }
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            if(check(i)==k) ans++;
        }
        printf("%d\n", ans);
    }
    //system("pause");
}

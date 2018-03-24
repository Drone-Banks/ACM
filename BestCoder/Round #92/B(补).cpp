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
LL a[MaxN];
LL b[MaxN];
struct Edge{
    int u,v;
}edge[MaxN];
int T,n,m,k;
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m, &k);
        int u,v;
        CLR(a);CLR(b);
        for(int i=0;i<k;i++)
        {
            scanf("%d%d", &u, &v);
            a[u]++;
            b[v]++;
            edge[i].u = u;
            edge[i].v = v;
        }
        LL ans=0;
        for(int i=0;i<k;i++)
        {
            int u=edge[i].u;
            int v=edge[i].v;
            ans+=(a[u]-1)*(b[v]-1);
        }
        printf("%I64d\n",ans*2);
    }
    //system("pause");
}

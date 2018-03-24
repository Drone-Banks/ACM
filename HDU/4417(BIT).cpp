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

int n,m; 
int A[MaxN];
struct Node
{
    int id;
    int val;
}node[MaxN];
struct Query
{
    int l,r,h,id,ans;
}query[MaxN];

void init()
{
    CLR(A); 
}
int lowbit(int x)
{
    return x&(-x);
}
void update(int loc, int val)
{
    for(int i=loc;i<=n;i+=lowbit(i))
    {
        A[i]+=val;
    }
}
int sum(int loc)
{
    int ans = 0;
    for(int i=loc;i>0;i-=lowbit(i))
    {
        ans += A[i];
    }
    return ans;
}

int main()
{
    //std::ios::sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d", &n, &m);
        init();
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &node[i].val);
            node[i].id = i;
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d", &query[i].l, &query[i].r, &query[i].h);
            query[i].id = i;
        }
        sort(node+1, node+1+n, [](Node a, Node b){return a.val<b.val;});
        sort(query+1, query+1+m, [](Query a, Query b){return a.h<b.h;});
        int loc = 1;
        for(int i=1;i<=m;i++)
        {
            while(loc<=n && query[i].h>=node[loc].val)
            {
                update(node[loc].id, 1);
                loc++;
            }
            query[i].ans = sum(query[i].r+1)-sum(query[i].l);
        }
        sort(query+1, query+1+m, [](Query a, Query b){return a.id<b.id;});
        printf("Case %d:\n", t);
        for(int i=1;i<=m;i++)
        {
            printf("%d\n", query[i].ans);
        }
    }
    //system("pause");
}

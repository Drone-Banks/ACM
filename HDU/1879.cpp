/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 100000
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)
// Kruskal 是合用于边比较少的图中求最小生成树
// 时间复杂度： O(ElgV)

struct Edge
{
    int u,v;
    int w;
    bool operator<(const Edge &a)const
    {
        return w<a.w;
    }
}edge[MaxM];

int N,M;   //N代表点数，M代表边数
int father[MaxN];

int getFather(int x)  //并查集找父亲
{
    int r = x;
    while(father[r]!=r)
        r = father[r];
    int j = x;
    while(j!=r)
    {
        int k = father[j];
        father[j] = r;
        j = k;
    }
    return r;
}

int Kruskal()
{
    for(int i=0;i<=N;i++)
        father[i]=i;

    int cnt=1;   //记录加入的点数
    int ans = 0; //记录建边的花费
    for(int i=0;i<M;i++)
    {
        int u=edge[i].u, v=edge[i].v;
        int w=edge[i].w;
        int fu=getFather(u),fv=getFather(v);
        if(fu==fv)
            continue;
        
        ans+=w;          //加入该边
        father[fv] = fu;
        cnt++;

        if(cnt==N) break;
    }
    return ans;
}


int main()
{
    while(~scanf("%d", &N) && N)
    {
        M = N*(N-1)/2;
        for(int i=0;i<M;i++)
        {
            int a,b,c,d;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            edge[i].u = a;
            edge[i].v = b;
            if(d) edge[i].w = 0;
            else edge[i].w = c;
        }
        sort(edge, edge+M);   //记得将边从小到大排序
        printf("%d\n", Kruskal());
    }
    system("pause");
}
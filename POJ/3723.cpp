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

#define MaxN 20005
#define MaxM 50005
#define INF 1000000000
#define bug cout<<88888888<<endl;

// Kruskal 是合用于边比较少的图中求最小生成树

struct Edge
{
    int u,v;
    int w;
    bool operator<(const Edge &a)const
    {
        return w>a.w;
    }
}edge[MaxM];

int N,M,R;
int father[MaxN];

int getFather(int x)
{
    int r,k,j;
    r = x;
    while(father[r]!=r)
        r = father[r];
    j = x;
    while(j!=r)
    {
        k = father[j];
        father[j] = r;
        j = k;
    }
    return r;
}

int Kruskal()
{
    for(int i=0;i<N+M;i++)
        father[i]=i;

    int cnt=1;
    int ans = 0;
    for(int i=0;i<R;i++)
    {
        int u=edge[i].u, v=edge[i].v;
        int w=edge[i].w;
        int fu=getFather(u),fv=getFather(v);
        if(fu==fv)
            continue;
        
        ans+=w;
        father[fv] = fu;
        cnt++;

        if(cnt==N+M) break;
    }
    return ans;
}

int main()
{
    int T;

    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &N, &M, &R);
        for(int i=0;i<R;i++)
        {
            int a,b,c;
            scanf("%d%d%d", &a,&b,&c);
            edge[i].u = a;
            edge[i].v = b+N;
            edge[i].w = c;
        }
        sort(edge, edge+R);
        printf("%d\n", 10000*(N+M) - Kruskal());
    }
     
    system("pause");
}
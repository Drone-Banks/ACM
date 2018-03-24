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

#define MaxN 233
#define MaxM MaxN*MaxN
#define INF 1000000000
#define bug cout<<88888888<<endl;

// Kruskal 是合用于边比较少的图中求最小生成树

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
    for(int i=0;i<=N;i++)
        father[i]=i;

    int cnt=1;
    int ans = 0;
    for(int i=0;i<M;i++)
    {
        int u=edge[i].u, v=edge[i].v;
        int w=edge[i].w;
        int fu=getFather(u),fv=getFather(v);
        if(fu==fv)
            continue;
        
        ans+=w;
        father[fv] = fu;
        cnt++;

        if(cnt==N) break;
    }
    return ans;
}

int main()
{
    int a,b,c;
    while(cin >> N && N)
    {
        M = N*(N-1)/2;
        for(int i=0;i<M;i++)
        {
            cin >> a >> b >> c;
            edge[i].u = a;
            edge[i].v = b;
            edge[i].w = c;
        }
        sort(edge, edge+M);
        cout << Kruskal() << endl;
    }
     
    system("pause");
}
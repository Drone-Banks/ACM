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

#define MaxN 101
#define MaxM MaxN*MaxN
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

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
int father[MaxN],Rank[MaxN];

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
void Union(int a, int b)
{
    int r1 = getFather(a);
    int r2 = getFather(b);
    if(r1 == r2)
        return;
    if(Rank[r1] > Rank[r2])
        father[r2] = r1;
    else
    {
        father[r1] = r2;
        if(Rank[r1] == Rank[r2])
            Rank[r1]++;
    }
}

int Kruskal(int x)
{
    for(int i=0;i<=N;i++)
        father[i]=i;
    CLR(Rank);

    int cnt=1;   //记录加入的点数
    int Min = INF;
    int Max = 0;
    for(int i=(x==M?0:x);i<M;i++)
    {
        //if(x == i) continue;
        int u=edge[i].u, v=edge[i].v;
        int w=edge[i].w;
        int fu=getFather(u),fv=getFather(v);
        if(fu==fv) continue; 

        Min = MIN(Min, w);
        Max = MAX(Max, w);
        Union(u,v);
        cnt++;
        if(cnt==N) break;
    }
    if(cnt==N) return Max-Min;
    else return -1;
}


int main()
{
    while(~scanf("%d%d", &N, &M) && (M+N))
    {
        for(int i=0;i<M;i++) scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
        sort(edge,edge+M);
        int ans = Kruskal(M);
        for(int i=0;i<M;i++)
        {
            int tmp = Kruskal(i);
            if(tmp == -1) continue;
            else ans = MIN(ans, tmp);
        }
        printf("%d\n", ans);
    }
    system("pause");
}
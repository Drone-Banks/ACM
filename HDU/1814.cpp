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

#define R 1
#define B 2
#define W 0

int N,M;
struct Edge
{
    int from,to,next;
}edge[MaxM];
int head[MaxN],cont;

void add(int u,int v)
{
    edge[cont].from = u;
    edge[cont].to=v;
    edge[cont].next=head[u];
    head[u]=cont++;
}

void init()
{
    MST(head, -1);
    cont = 0;
}

int cnt;
int color[MaxN];
int ans[MaxN];

bool dfs(int u)
{
    if (color[u] == B)
        return false;
    if (color[u] == R)
        return true;
    color[u] = R;
    color[u^1] = B;
    ans[cnt++] = u;
    for (int i=head[u]; i!=-1; i=edge[i].next)
    {
        int k = edge[i].to;
        if (!dfs(k)) return false;
    }
    return true;
}
bool solve()
{
    CLR(color);
    for(int i=0; i<N; i++)
    {
        if(color[i])  continue;
        cnt = 0;
        if(!dfs(i))
        {
            for(int j=0; j<cnt; j++)
            {
                color[ans[j]] = W;
                color[ans[j]^1] = W;
            }
            if(!dfs(i^1)) return false;
        }
    }
    return true;
}
int main()
{
    while(~scanf("%d %d",&N, &M))
    {
        N <<= 1;
        int i;
        init();
        int a, b;
        while(M--)
        {
            scanf("%d %d",&a, &b);
            a--;
            b--;
            add(a, b^1);
            add(b, a^1);
        }

        if (solve())
        {
            for (i=0; i<N; i++)
                if(color[i] == R)
                    printf("%d\n",i+1);
        }
        else printf("NIE\n");
    }
    return 0;
}
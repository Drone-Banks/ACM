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
int N, M;
struct Edge
{
    int u,v,next;
}edge[MaxM];
int cont;
int head[MaxN];
void add(int u, int v)
{
    edge[cont].u = u;
    edge[cont].v = v;
    edge[cont].next = head[u];
    head[u] = cont++;
}
int match[MaxN];
bool check[MaxN];

bool DFS(int u)
{
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(!check[v])
        {
            check[v] = true;
            if(match[v] == -1 || DFS(match[v]))
            {
                //cout << u << "-" << v << endl;
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
    }
    return false;
}

int Hungarian()
{
    int ans = 0;
    MST(match, -1);
    for(int i=1;i<=N;i++)
    {
        if(match[i] == -1)
        {
            CLR(check);
            if(DFS(i)) ans++;
        }
    }
    return ans;
}
void init()
{
    cont = 0;
    MST(head,-1);
}

int main()
{
    while(~scanf("%d%d", &N, &M))
    {
        init();
        for(int i=0;i<M;i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            add(a,b);add(b,a);
        }
        printf("%d\n", Hungarian());
    }

    system("pause");
}
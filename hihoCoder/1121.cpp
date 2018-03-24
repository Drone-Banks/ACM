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

int T;
int N,M;
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
int col[MaxN];
bool BFS(int x)
{
    col[x] = 1;
    queue<int> Q;
    Q.push(x);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            if(col[v] == col[u]) return false;
            else
            {
                if(col[v] == -1)
                {
                    col[v] = col[u]^1;
                    Q.push(v);
                }
            }
        }
    }
    return true;
}
bool judge()
{
    for(int i=1;i<=N;i++)
    {
        if( col[i] == -1 && !BFS(i))
        {
            return false;
        }
    }
    return true;
}
void init()
{
    cont = 0;
    MST(head, -1);
    MST(col,-1);
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        init();
        scanf("%d%d", &N, &M);
        for(int i=0;i<M;i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            add(a,b);add(b,a);
        }
        if(judge())
        {
            printf("Correct\n");
        }
        else
        {
            printf("Wrong\n");
        }
    }
    system("pause");
}
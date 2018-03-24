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
#include <climits>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 100000
#define MaxM MaxN*10
#define INF INT_MAX
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

int N,C;
int A[MaxN];

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

void init()
{
    cont = 0;
    MST(head, -1);
}

int main()
{
    while(~scanf("%d%d", &N,&C))
    {
        int Mx = INF;
        int Cx = INF;
        for(int i=1;i<=N;i++) 
        {
            scanf("%d", &A[i]);
            if(Mx>=A[i])
            {
                Cx = Mx;
                Mx = A[i];
            }
        }
        for(int i=1;i<N;i++)
        {
            int a,b;
            scanf("%d%d", &a, &b);
            add(a,b);add(b,a);
        }

        if(Cx>C)
        {
            printf("0\n");
        }
        else
        {
            
        }

    }
    system("pause");
}
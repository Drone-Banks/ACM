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

#define MaxN 2333
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

int N, M;
int key[MaxN];
int dl[MaxM];
int dr[MaxM];

struct Edge
{
    int from,to,next;
}edge[MaxM];
int head[MaxN],cont;

int low[MaxN];
int dfn[MaxN];

int Stack[MaxN], top;
int belong[MaxN];
int inStack[MaxN];
int Index, cnt;


void init()
{
    MST(head,-1);
    MST(dfn,-1);
    CLR(low);
    CLR(inStack);
    cont=0;
    Index = cnt = 1;
    top=0;
}

void add(int u,int v)
{
    edge[cont].from = u;
    edge[cont].to=v;
    edge[cont].next=head[u];
    head[u]=cont++;
}

void Tarjan(int x)
{
    low[x] = dfn[x] = Index;                // 刚搜到一个节点时low = dfn
    Index++;
    Stack[++top] = x;                       // 将该节点入栈
    inStack[x] = 1;                         // 将入栈标记设置为1
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(dfn[v ]== -1)
        {
            Tarjan(v);
            low[x]=MIN(low[x], low[v]);     // 回溯的时候改变当前节点的low值
        }
        else if(inStack[v])
        {
            low[x] = MIN(low[x], dfn[v]);   // 更新当前节点的low值，这里的意思是两个节点之间有一条可达边，
        }
    }
    if(low[x] == dfn[x])
    {
        for(int v=-1;v!=x;top--)
        {
            v = Stack[top];
            inStack[v] = false;
            belong[v] = cnt;
        }
        cnt++;
    }
}

int main()
{
    while(~scanf("%d%d", &N, &M) && (N+M) )
    {
        int a,b;
        for(int i=1;i<=N;i++)
        {
            scanf("%d%d", &a, &b);
            key[a] = b;
            key[b] = a;
        } 
        for(int i=1;i<=M;i++) 
        {
            scanf("%d%d", &dl[i], &dr[i]);
        }

        int low = 0, high = M;
        int mid = (low+high)>>1, ans = mid;
        while(low <= high)
        {
            init();
            for(int i=1;i<=mid;i++)
            {
                add(dl[i], key[dr[i]]);
                add(dr[i], key[dl[i]]);
            }
            for(int i=0;i<2*N;i++)
                if(dfn[i]==-1)
                    Tarjan(i);
            int flag = 0;
            for(int i=0;i<2*N;i++)
            {
                if(belong[i] == belong[key[i]])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag) high = mid-1;
            else low = (ans = mid)+1;
            mid = (low+high)>>1;
        }
        cout << ans << endl;

    }
    system("pause");
}
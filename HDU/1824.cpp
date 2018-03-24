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

#define MaxN 2005
#define MaxM MaxN*20
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

struct Edge
{
    int from,to,next;
}edge[999999];

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
    low[x] = dfn[x] = Index++;                // 刚搜到一个节点时low = dfn
    Stack[++top] = x;                       // 将该节点入栈
    inStack[x] = 1;                         // 将入栈标记设置为1
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(dfn[v]== -1)
        {
            Tarjan(v);
            low[x] = MIN(low[x], low[v]);     // 回溯的时候改变当前节点的low值
        }
        else if(inStack[v])
        {
            low[x] = MIN(low[x], dfn[v]);   // 更新当前节点的low值，这里的意思是两个节点之间有一条可达边，
        }
    }
    if(low[x] == dfn[x])
    {
        int temp;
        while(1)                            // 一直出栈到此节点， 这些元素是一个强联通分量
        {
            temp = Stack[top--];            // 弹出栈元素
            belong[temp] = cnt;             // 为了方便计算，将强联通分量进行标记
            inStack[temp] = 0;              // 将栈内标记置为0
            if(temp == x)                   // 一直弹到x出现为止
                break;
        }
        cnt++;
    }
}


int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int B[3005];
        for(int i=0;i<n;i++)
        {
            int l,s1,s2;
            scanf("%d%d%d",&l,&s1,&s2);   //把2个队员存成一个
            B[l]=i<<1;
            B[s1]=i<<1|1;
            B[s2]=i<<1|1;
        }
        init();
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(B[a],B[b]^1);              //建图的时候2个队员建成一个点
            add(B[b],B[a]^1);
        }
        for(int i=0;i<n*2;i++)
            if(dfn[i]==-1) 
                Tarjan(i);

        int flag = 1;
        for(int i=0;i<n;i++)
        {
            if(belong[i<<1]==belong[i<<1|1])
            {
                puts("no");
                main();
                exit(0);
            }
        }
        puts("yes");
    }
}
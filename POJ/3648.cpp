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
int l[MaxN];
int r[MaxN];
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

//对立关系: 夫妻
//矛盾关系: 有不良关系的一对人不能同时坐在新娘的对面，夫妻对立。
//0~(N-1)    0 1 2 3 4 5 6 7    
//        w  0 2 4              i*2
//        h  1 3 5              i*2 | 1

int opposite[MaxN];
int degree[MaxN];
int color[MaxN];
const int W = 0;
const int R = 1;
const int B = 2;
int que[MaxN];
int ss,ee;
void topo()
{
    ss = ee = 0;
    MST(color,W);
    for(int i=1;i<cnt;i++)
    {
        if( !degree[i] ) que[ee++] = i;
    }   
    while(ss<ee)
    {
        int u = que[ss++];
        if(color[u]) continue;
        color[u] = R;
        color[opposite[u]] = B;
        for(int i = head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].to;
            degree[v]--;
            if(!degree[v]) que[ee++]=v;
        }
    }
}

int main()
{
    while(~scanf("%d%d", &N, &M) && (N+M) )
    {
        init();
        char c,d;
        add(0,1);
        for(int i=0;i<M;i++)
        {
            scanf("%d%c%d%c", &l[i], &c, &r[i], &d);
            if( c == 'h') l[i] = l[i]*2+1;
            else l[i] = l[i]*2;
            if( d == 'h') r[i] = r[i]*2+1;
            else r[i] = r[i]*2;
            add(l[i], r[i]^1);
            add(r[i], l[i]^1);   
        }
        for(int i=0;i<2*N;i++)
            if(dfn[i] == -1)
                Tarjan(i);
        int flag = 1;
        //cout << belong[0] << ':'<< belong[1] << endl;
        for(int i=0;i<N;i++)
        {
            int a = belong[i<<1];
            int b = belong[i<<1|1];
            opposite[a] = b;
            opposite[b] = a;
            if(a == b)
            {
                flag = 0;
                break;
            }
        }

        if(flag)
        {
            MST(head, -1);
            cont = 0;
            CLR(degree);
            add(belong[1],belong[0]);
            degree[belong[0]]++;
            for(int i=0;i<M;i++)
            {
                int ll = belong[l[i]];
                int rr = belong[r[i]];
                if( ll == opposite[rr] || rr == opposite[ll]) continue;
                add(opposite[ll], rr);
                add(opposite[rr], ll);
                degree[rr]++;
                degree[ll]++;
            }
            topo();
            for(int i=2;i<N*2;i++)
            {
                if(color[belong[i]]==B)
                {
                    if(i>3) putchar(' ');
                    if(i&1) printf("%dh",i>>1);
                    else printf("%dw",i>>1);
                }
            }
            puts("");
        }
        else puts("bad luck");
    }
    system("pause");
}
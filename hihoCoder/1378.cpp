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

#define MaxN 666
#define MaxM 41234
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)


int N,M; //N个点，M条边
struct Edge{
    int u,v,next;
    int flow;
}edge[MaxM];   //最大边数，一般都是实际边数的2倍甚至以上

int head[MaxN];
int cont;

void init(){        //记得init
    cont = 0;
    MST(head, -1);

}

void add(int u, int v, int flow){
    edge[cont].u = u;
    edge[cont].v = v;
    edge[cont].flow = flow;
    edge[cont].next = head[u];
    head[u] = cont++;
}

void Add(int u, int v, int flow){    //建正反两条边，反向流量为0
    add(u, v, flow);
    add(v, u, 0);
}

int dis[MaxN];
int num[MaxN];
int cur[MaxN];
int pre[MaxN];

set<int> ans;
bool flag;

void BFS(int source,int sink)
{
    queue<int>q;
    CLR(num);
    MST(dis,-1);

    q.push(sink);
    dis[sink]=0;
    num[0]=1;
	if(flag) ans.insert(sink);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            if(flag)
            {
                if(dis[v] == -1 && edge[i].flow)
                {
                    dis[v] = dis[u] + 1;
                    num[dis[v]]++;
                    q.push(v);
    				ans.insert(v);
                }
            }
            else
            {
                if(dis[v] == -1)
                {
                    dis[v] = dis[u] + 1;
                    num[dis[v]]++;
                    q.push(v);
                }
            }
        }
    }
}

int ISAP(int source,int sink,int n)      //从源点到汇点，n为总点数，返回最大流
{
    memcpy(cur,head,sizeof(cur));
    int flow=0, u = pre[source] = source;
    BFS( source,sink);
    while( dis[source] < n )
    {
        if(u == sink)
        {
            int df = INF, pos;
            for(int i =source;i != sink;i = edge[cur[i]].v)
            {
                if(df > edge[cur[i]].flow)
                {
                    df = edge[cur[i]].flow;
                    pos = i;
                }
            }
            for(int i = source;i != sink;i = edge[cur[i]].v)
            {
                edge[cur[i]].flow -= df;
                edge[cur[i]^1].flow += df;
            }
            flow += df;
            //cout << flow << endl;
            u = pos;
        }
        int st;
        for(st = cur[u];st != -1;st = edge[st].next)
        {
            if(dis[edge[st].v] + 1 == dis[u] && edge[st].flow)
            {
                break;
            }
        }
        if(st != -1)
        {
            cur[u] = st;
            pre[edge[st].v] = u;
            u = edge[st].v;
        }
        else
        {
            if( (--num[dis[u]])==0 ) break;
            int mind = n;
            for(int id = head[u];id != -1;id = edge[id].next)
            {
                if(mind > dis[edge[id].v] && edge[id].flow != 0)
                {
                    cur[u] = id;
                    mind = dis[edge[id].v];
                }
            }
            dis[u] = mind+1;
            num[dis[u]]++;
            if(u!=source)
            u = pre[u];
        }
    }
    return flow;
}

int u,v,w;
int main()
{
	while( ~scanf("%d%d", &N, &M))
    {
		flag = false;
        init();
		ans.clear();
        for(int i=0;i<M;i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            Add(u,v,w);
        }
        int S = 1, T = N;
        cout << ISAP(1,N,N);
        flag=true;
        BFS(N,1);
        printf(" %d\n", ans.size());
        for(int x:ans)printf("%d ",x);
        printf("\n");
    }
    //system("pause");
}
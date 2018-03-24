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

#define MaxN 200
#define MaxM MaxN*MaxN
#define INF 1000000000
#define bug cout<<88888888<<endl;

int N,M;

typedef pair<int,int> pii;


int cont=0;
int head[MaxN];
int dis[MaxN];

void init()
{
    memset(head,-1,sizeof(head));
    cont=0;
}

struct edge
{
	int from,to,w,next;
}e[MaxM];


void add(int from,int to,int w)
{    //若有向图则只需要前一半
    e[cont].to=to;
    e[cont].w=w;
    e[cont].next=head[from];
    head[from]=cont++;

    e[cont].to=from;
    e[cont].w=w;
    e[cont].next=head[to];
    head[to]=cont++;
}

struct cmp
{                        //将优先队列改为小根堆
    bool operator()(pii a,pii b)
    {
        return a.first>b.first;
    }
};

int Dijkstra(int s,int t)
{            
    int n = N; //n赋值为图中点数
    
    for(int i=1;i<=n;i++)
        dis[i] = INF;
    int i;
    priority_queue<pii,vector<pii>,cmp>q;
    q.push(make_pair(0,s));
    dis[s]=0;
    while(!q.empty())
    {
        pii u=q.top();
        q.pop();
        if(u.first>dis[u.second])continue;
        for(i=head[u.second];~i;i=e[i].next)
        {
            int j=e[i].to;
            if(dis[j]>u.first+e[i].w)
            {
                dis[j]=u.first+e[i].w;
                q.push(make_pair(dis[j],j));
            }
        }

    }
    
    return dis[t];
}

int main()
{
    while(cin >> N >> M && (N+M))
    {
        init();
        int a,b,c;
        while(M--)
        {
            cin >> a >> b >> c;
            add(a,b,c);
        }
        int ans = Dijkstra(1,N);
        cout << ans << endl;
    }

    system("pause");
}
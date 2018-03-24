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

#define MaxN 100005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

int N;
struct Edge{
    int u,v;
    int next;
}edge[MaxM];
int cont;
int head[MaxN];
void init()
{
    cont = 0;
    MST(head,-1);
}
void add(int u, int v)
{
    edge[cont].u = u;
    edge[cont].v = v;
    edge[cont].next = head[u];
    head[u] = cont++;
}

int DFS(int u)
{
    vector<int> V;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        V.push_back(DFS(v));
    }
    int ans;
    if(V.size()==0) ans = 0;
    else
    {
        sort(V.begin(), V.end());
        int Max = 0;
        for(int i=0;i<V.size();i++)
        {
            //cout << i << ":" << V[i] << endl;
            V[i]+=(V.size()-i);
            Max = MAX(Max, V[i]);
        }
        ans = Max;
    }
    V.clear();
    return ans;
}
int main()
{
    while(~scanf("%d", &N))
    {
        init();
        for(int i=2;i<=N;i++)
        {
            int x;
            scanf("%d", &x);
            add(x,i);
        }
        int ans = DFS(1);
        printf("%d\n", ans);
    }
    //system("pause");
}
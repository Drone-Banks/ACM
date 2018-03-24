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

int n,m;

struct Edge
{
    int u,v;
    int next;
}edge[MaxM];

int cont,flag;
int head[MaxN];
int vis[MaxN];

void add(int u, int v)
{
    edge[cont].u = u;
    edge[cont].v = v;
    edge[cont].next = head[u];
    head[u] = cont++;
}

void Add(int u, int v)
{
    add(u,v);
    add(v,u);
}
map<int,int> M;

vector<int> vec[2];

void init()
{
    cont = 0;
    MST(head, -1);
    CLR(vis);
    vec[0].clear();
    vec[1].clear();
    M.clear();
}

void DFS(int x)
{
    for(int p = head[x]; p != -1; p = edge[p].next)
    {
        int V = edge[p].v;
        if(vis[V])
        {
            if(M[V] == M[edge[p].u])
            {
                flag = 1;
                return;
            }
            continue;
        }
        M[V] = -M[x];
        vis[V] = 1;
        DFS(V);
    }
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        init();
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u, &v);
            Add(u,v);
        }
        flag = 0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            if(flag) break;
            vis[i] = 1;
            M[i] = 1;
            DFS(i);
            
        }
        
        if(flag)
        {
            cout << -1 << endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(M[i] == 1) vec[0].push_back(i);
            if(M[i] == -1) vec[1].push_back(i);
        }
        int l1 = vec[0].size();
        int l2 = vec[1].size();

        cout << l1 << endl;
        for(int i=0;i<l1-1;i++) cout << vec[0][i]<<" ";
        cout << vec[0][l1-1]<<endl;

        cout << l2<< endl;
        for(int i=0;i<l2-1;i++) cout << vec[1][i]<<" ";
        cout << vec[1][l2-1]<<endl;
    }
    //system("pause");
}
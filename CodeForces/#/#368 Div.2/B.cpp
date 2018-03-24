#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

int n,m,k;

int city[112345];
int sto[112345];
struct Edge
{
    int u,v;
    int w;
    int next;
}edge[233333];

int cont = 0;
int head[112345];

void init()
{
    cont = 0;
    memset(head, -1, sizeof(head));
}

void add(int u, int v, int val)
{
    edge[cont].u = u;
    edge[cont].v = v;
    edge[cont].w = val;
    edge[cont].next = head[u];
    head[u] = cont++;
}

void Add(int u, int v, int val)
{
    add(u,v,val);
    add(v,u,val);
}

int INF = 1000000001;

int BFS(int x)
{
    int dist = INF;
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        dist = min(edge[i].w, dist);
        cout << dist << endl;
    }
    return dist;
}


int main()
{
    init();
    scanf("%d%d%d", &n, &m, &k);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        Add(a, b, c);
    }

    for(int i=0;i<k;i++)
    {
        int kk;
        scanf("%d", &kk);
        city[kk] = 1;
        sto[i] = kk;
    }

    int ans = INF;
    for(int i=0;i<k;i++)
    {
        ans = min(BFS(sto[i]), ans);

    }
    if(ans == INF) cout<< -1 <<endl;
    else cout << ans << endl;
}

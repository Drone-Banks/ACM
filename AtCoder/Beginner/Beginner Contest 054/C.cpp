/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 100
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;

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
void Add(int u, int v)
{
    add(u,v),add(v,u);
}

void init()
{
    cont = 0;
    MST(head, -1);
}

int vis[MaxN];
int DFS(int u, int nums)
{
   // cout << u << " " << nums << endl;
    vis[u] = nums;
    if(nums == N) return 1;
    int ans = 0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(vis[v]&&vis[v]<nums) continue;
        else
        {
            ans += DFS(v, nums+1);
        }
    }
    vis[u] = 0;
    return ans;
}
void solve()
{
    int ans = DFS(1,1);
    printf("%d\n", ans);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    init();
    scanf("%d%d", &N, &M);
    int a,b;
    while(M--)
    {
        scanf("%d%d", &a, &b);
        Add(a,b);
    }
    solve();
    system("pause");
}

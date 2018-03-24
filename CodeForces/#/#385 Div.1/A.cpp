/*************************************************************************
	> File Name: A.cpp
	> Author: Akira
	> Mail: qaq.febr2.qaq@gmail.com
	> Created Time: 2017年01月13日 星期五 21时34分59秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<cmath>
#include<vector>
#include<set>
#include<list>
#include<ctime>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))

using namespace std;

#define MaxN 1005
#define MaxM MaxN*200
#define INF 0x3f3f3f3f
#define bug cout << 88888888 << endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

int n,m,k;
int c[MaxN];
int dian[MaxN];
int bian[MaxN];
int Size[MaxN];
int Father[MaxN];
int cnt;
struct Edge
{
    int u,v;
    int next;
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
    add(u, v);
    add(v, u);
}

void init()
{
    MST(head,-1);
    cont = 0;
    cnt = 0;
    CLR(dian);
    CLR(bian);
    CLR(c);
    CLR(Father);
}
int flag[MaxM];
int vis[MaxN];
int root;
void dfs(int x)
{
    vis[x] = 1;
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        int to = edge[i].v;
        Father[to] = root;
        if(flag[i] == 0 && flag[i^1] == 0)
        {
            bian[root]++;
            flag[i] = flag[i^1] = 1;
        }
        if(vis[to] == 1) continue;
        else
        {
            dian[root]++;
            dfs(to);
        }
    }
}

void Find(int x)
{
    vis[x] = 1;
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        int to = edge[i].v;
        if(flag[i] == 0 && flag[i^1] == 0)
        {
            cnt++;
            flag[i] = flag[i^1] = 1;
        }
        if(vis[to] == 1) continue;
        else
        {
            Find(to);
        }
    }
}

int main()
{
    while(~scanf("%d%d%d", &n, &m, &k))
    {
        init();
        CLR(flag);
        CLR(vis);
        for(int i=0;i<k;i++) scanf("%d", &c[i]);
        while(m--)
        {
            int a,b;
            scanf("%d%d", &a, &b);
            Add(a,b);
        }
        for(int i=0;i<k;i++) //计算每个国家的完全图的点数和边数
        {
            root = c[i];
            dian[root] = 1;
            Father[root] = root;
            dfs(c[i]);
            Size[root] = dian[root]*(dian[root]-1)/2 - bian[root];
        }
        int have = 0;
        for(int i=1;i<=n;i++)   //计算出来不属于任何国家的已有边的数量
        {
            if(Father[i]>0 || vis[i]>0) continue;
            cnt = 0;
            Find(i);
            have+=cnt;
        }
        int remain = n;
        int Max = 0;
        for(int i=0;i<k;i++)     //计算出来不属于任何国家的点，并找出含有点数最多的国家
        {
            remain -= dian[c[i]];
            Max = MAX(dian[c[i]], Max);
        }
        int ans = Max*remain + remain*(remain-1)/2 - have;
        
        for(int i=0;i<k;i++)   //计算每个国家可以加多少条边
        {
            ans += Size[c[i]];
        }
        cout << ans << endl;
    }
}


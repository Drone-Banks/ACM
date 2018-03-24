#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxe=1995+10;
const int maxv=44+10;
struct edge
{
    int u,v;
}edges[maxe];
int n,m;//n表示节点数,m表示边数,边与点都从1开始编号
int degree[maxv];//每个点的度数
int vis[maxe];//标记边是否被走过
int ans[maxe];//最终结果存在这里
int cnt;//当前存在ans中的边下标
bool ok()
{
    for(int i=1;i<=n;i++)if(degree[i]%2!=0) return false;
    return true;
}
void euler(int s)
{
    for(int i=1;i<=m;i++)if(!vis[i] && (edges[i].u==s||edges[i].v==s) )
    {
        vis[i]=1;
        euler(edges[i].u+edges[i].v-s);
        ans[cnt++]=i;
    }
}
int main()
{
    int x,y,z;
    while(scanf("%d%d",&x,&y)==2&&x)
    {
        cnt=n=m=0;
        int John_home = min(x,y);
        memset(degree,0,sizeof(degree));
        memset(vis,0,sizeof(vis));
        do
        {
            scanf("%d",&z);
            edges[z].u=x;
            edges[z].v=y;
            degree[x]++;
            degree[y]++;
            m++;
            n=max(n,max(x,y));
        }while(scanf("%d%d",&x,&y)==2&&x);
        if(!ok())
        {
            printf("Round trip does not exist.\n");
            continue;
        }
        euler(John_home);
        printf("%d",ans[m-1]);
        for(int i=m-2;i>=0;i--)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}

/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
#include <climits>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 1001
#define MaxM 25005
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
#define bug cout<<88888888<<endl;
// Kruskal 是合用于边比较少的图中求最小生成树
// 时间复杂度： O(ElgV)

struct Edge
{
    int u,v;
    int w;
    bool operator<(const Edge &a)const
    {
        return w<a.w;
    }
}edge[MaxM];

int N,M,K;   //N代表点数，M代表边数
int father[MaxN];
int len;
int getFather(int x)  //并查集找父亲
{
    int r = x;
    while(father[r]!=r)
        r = father[r];
    int j = x;
    while(j!=r)
    {
        int k = father[j];
        father[j] = r;
        j = k;
    }
    return r;
}

int Kruskal()
{
    int cnt=1;   //记录加入的点数
    int ans = 0; //记录建边的花费
    for(int i=0;i<M;i++)
    {
        int u=edge[i].u, v=edge[i].v;
        int w=edge[i].w;
        int fu=getFather(u),fv=getFather(v);
        if(fu==fv)
            continue;
        
        ans+=w;          //加入该边
        father[fv] = fu;
        cnt++;

        if(cnt==N) break;
    }
   // cout << ans << endl;
    int tmp = 0;
    for(int i=1;i<=N;i++)
    {
        if(father[i]==i) tmp++;
    }
    if(tmp>1) return -1;
    else return ans;
}
int city[600];
int main()
{
    //std::ios::sync_with_stdio(false);
    int T;
    scanf("%d",&T);
    while(T--){
        
        scanf("%d%d%d",&N,&M,&K);
        for(int i=0;i<=N;i++)
        father[i]=i;
        for(int i=0;i<M;i++)
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
        for(int i=0;i<K;i++)
        {
            int t,x,y;
            scanf("%d%d", &t,&x);
            for(int j=1;j<t;j++)
            {
                scanf("%d", &y);
                int fx = getFather(x);
                int fy = getFather(y);
                father[fy] = father[fx];
            }
        }
        sort(edge, edge+M);   //记得将边从小到大排序
        
        printf("%d\n",Kruskal());
    }
    //system("pause");
}

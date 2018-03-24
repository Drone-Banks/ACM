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

#define MaxN 110
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;

int n,m; //总点数
int Map[MaxN][MaxN],dis[MaxN][MaxN];  //dis[i][j]存储i到j的最短路
pair<int,int> edge[1001];

void Floyd()
{
    int ans = 0;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dis[i][j]>dis[i][k]+dis[k][j])
                {
                    dis[i][j]=dis[i][k]+dis[k][j];
                }

    for(int i=0;i<m;i++)
    {
        int x = edge[i].first, y = edge[i].second;
        if(dis[x][y]<Map[x][y]) ans++;
    }
    printf("%d\n", ans);
}
void init()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dis[i][j] = dis[j][i] = INF;
        }
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    init();
    int a,b,c;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        Map[a][b] = Map[b][a] = c;
        dis[a][b] = dis[b][a] = c;
        edge[i].first = a, edge[i].second = b;
    }
    Floyd();
    system("pause");
}

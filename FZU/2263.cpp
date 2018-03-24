#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int N, tt, n, m, i, j, cas, k, pp, x, l, y, z, ans, anss, X;
int dis[30][30], mm[30][30];
int sum[30], a[30], b[30], c[30], p[30];
int slack[30], match[30], vis[30], visa[30], visb[30], exa[30], exb[30];
int viss[300000];
int q[] = {0, 1, 2, 4, 8, 16, 32, 63, 128, 256, 512, 1024, 2048, 4096,
            8192, 16384, 32768, 65536, 131072, 262144, 524288};
int fmax(int a, int b){return a>b?a:b;}
int fmin(int a, int b){return a<b?a:b;}
bool dfs1(int x)
{
    visa[x] = 1;
    int y;
    for(y=1; y<=N; y++)
    {
        if (visb[y]) continue;
        int gap = exa[x]+exb[y]-mm[x][y];
        if (gap == 0){
            visb[y] = 1;
            if (match[y] == -1 || dfs1(match[y]))
            {
                match[y] = x;
                return true;
            }
        }else{
            slack[y] = fmin(slack[y], gap);
        }
    }
    return false;
}
int KM()
{
    memset(match, -1, sizeof(match));
    memset(exb, 0, sizeof(exb));
    int i, j;
    for(i=1; i<=N; i++)
    {
        exa[i] = mm[i][1];
        for(j=2; j<=N; j++)
            exa[i] = fmax(exa[i], mm[i][j]);
    }

    for(i=1; i<=N; i++)
    {
        for(j=1; j<=N; j++)
            slack[j] = 2147483647;
        //cout<<'a'<<endl;
        while(1)
        {
            //cout<<'n'<<endl;
            memset(visa, 0, sizeof(visa));
            memset(visb, 0, sizeof(visb));

            if (dfs1(i)) break;

            int d = 2147483647;
            for(j=1; j<=N; j++)
                if (!visb[j]) d = fmin(d, slack[j]);
            for(j=1; j<=N; j++)
            {
                if (visa[j]) exa[j] -= d;
                if (visb[j]) exb[j] += d;
                else slack[j] -= d;
            }
        }
    }
    //cout<<'c'<<endl;
    int res = 0;
    for(i=1; i<=N; i++)
        res += mm[match[i]][i];

        /*
    int ad, p, Y;
    for(i=1; i<=q[N+1]-1; i++)
    {
        Y = X;
        p = i; ad = 0;
        while(p)
        {
            ad++;
            if (p % 2) Y = Y - q[a[ad]] + q[b[match[ad]]];
            p /= 2;
        }
        viss[Y] = 1;
    }
    */
    return res;
}
void make()
{
    int i; X = 0;
    for(i=1; i<=l; i++)
        X += vis[i] * q[i];
    if (viss[X]) return;
    viss[X] = 1;
    //cout<<"X:"<<X<<endl;
    int x = 0;
    int y = 0;
    for(i=1; i<=l; i++)
        if (vis[i]) a[++x] = i; else b[++y] = i;

    N = l/2;

    for(i=1; i<=N; i++)
    {
        for(j=1; j<=N; j++)
        {
            mm[i][j] = -dis[c[a[i]]][c[b[j]]];
        }
    }
    anss = -KM();
    if (anss < ans) ans = anss;
}
void dfs(int x, int p)
{
    vis[x] = 0;
    if (l-x+1 < p) return;
    if (p == 0)
    {
        //cout<<"h"<<endl;
        make();
        return;
    }
    dfs(x+1, p);

    vis[x]=1;
    dfs(x+1, p-1);
}
int main()
{
    scanf("%d", &tt); cas=0;
    while(tt--)
    {
        memset(viss, 0, sizeof(viss));
        scanf("%d%d", &n, &m);
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                dis[i][j] = 2000;

        memset(sum, 0 ,sizeof(sum));
        for(i=1; i<=m; i++)
        {
            scanf("%d%d%d", &x, &y, &z);
            dis[x][y] = 1; dis[y][x] = 1;
            sum[x]+=z; sum[y] += z;
        }
        for(k=1; k<=n; k++)
            for(i=1; i<=n; i++)
                for(j=1; j<=n; j++)
                    if (dis[i][k]+dis[k][j] < dis[i][j])
                        dis[i][j] = dis[i][k]+dis[k][j];

        l= 0; ans = 100000;
        for(i=1; i<=n; i++)
            if (sum[i]%2) c[++l] = i;
        memset(vis, 0, sizeof(vis));
        dfs(1, l/2);
        printf("Case %d: %d\n", ++cas, ans);
    }
}
/*
1000
18
17
1 2 1
2 3 2
3 4 1
4 5 2
5 6 1
6 7 2
7 8 1
8 9 2
9 10 1
10 11 2
11 12 1
12 13 2
13 14 1
14 15 2
15 16 1
16 17 2
17 18 1
*/
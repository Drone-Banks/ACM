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

#define MaxN 110
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;

int n,m;
LL p; 

struct Edge
{
    int u, v, w;
    Edge(){}
    Edge(int u, int v, int w):u(u), v(v), w(w) {}
}edge[MaxM];

struct Matrix  
{  
    LL a[MaxN][MaxN];  
    Matrix()  
    {  
        for(int i = 0; i < MaxN; i++)  
            for(int j = 0; j < MaxN; j++)  
                a[i][j] = (i == j);  
    }  
    LL* operator[](int x)  
    {  
        return a[x];  
    }  
    LL det(int n)  
    {  
        for(int i = 1; i < n; i++)  
            for(int j = 1; j < n; j++)  
                a[i][j] %= p;  
        LL ret = 1;  
        for(int i = 1; i < n; i++)  
        {  
            for(int j = i + 1; j < n; j++)  
                while(a[j][i])  
                {  
                    LL tmp = a[i][i] / a[j][i];  
                    for(int k = i; k < n; k++) a[i][k] = (a[i][k] - a[j][k]*tmp) % p;  
                    for(int k = i; k < n; k++) swap(a[i][k], a[j][k]);  
                    ret = -ret;  
                }  
            if(a[i][i] == 0) return 0;  
            ret = ret*a[i][i] % p;  
        }  
        return (ret + p) % p;  
    }  
}K,A;  

Matrix operator - (const Matrix &m1, const Matrix &m2)  
{  
    Matrix ret;  
    for(int i = 0; i < MaxN; i++)  
        for(int j = 0; j < MaxN; j++)  
            ret[i][j] = m1.a[i][j] - m2.a[i][j];  
    return ret;  
}  

bitset<MaxN> vis;
int Fa[MaxN], Ka[MaxN];//Ka为新图的联通关系，Fa为整个图的联通关系
int find(int x, int *f)
{
    return x==f[x]?x:f[x]=find(f[x],f);
}
vector<int> gra[MaxN];  
LL matrixTree()  
{  
    for(int i = 1; i <= n; i++) 
        if(vis[i])//找出连通分量  
        {  
            gra[find(i, Ka)].push_back(i);//这里Ka能反映出新图的连通关系, 而Fa还没更新  
            vis[i] = 0;  
        }  
    LL ret = 1;  
    for(int i = 1; i <= n; i++) 
        if(gra[i].size() > 1)//枚举计算各个连通分量造成的不同生成树数量  
        {  
            CLR(K.a);
            int sz = gra[i].size();  
            for(int x = 0; x < sz; x++)  
            {  
                for(int y = x + 1; y < sz; y++)//每个连通分量求Kirchhoff矩阵  
                {  
                    int u = gra[i][x], v = gra[i][y];  
                    K[x + 1][y + 1] = 0 - A[u][v];  
                    K[y + 1][x + 1] = K[x + 1][y + 1];  
                    K[x + 1][x + 1] += A[u][v] - 0;  
                    K[y + 1][y + 1] += A[v][u] - 0;  
                }  
            }  
            ret = ret*K.det(sz) % p;  
            for(int j = 0; j < sz; j++) Fa[gra[i][j]] = i;//更新并查集  
        }  
    for(int i = 1; i <= n; i++)//连通图缩点, 将连通分量并查集的根节点变为一致  
    {  
        Fa[i] = find(i, Fa);  
        Ka[i] = Fa[i];  
        gra[i].clear();  
    }  
    return ret;  
}  


int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d%lld", &n, &m, &p) && (n||m||p) ) //n个点，m条边，p为mod
    {
        for(int i=0;i<m;i++) scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
        sort(edge, edge+m, [](Edge a, Edge b){return a.w<b.w;});
        for(int i=1;i<=n;i++) Fa[i]=Ka[i]=i; 
        vis.reset();
        CLR(A.a);//邻接矩阵  
        LL ans = 1;
        int pre = edge[0].w;
        for(int i=0;i<m;i++)
        {
            int fu = find(edge[i].u, Fa), fv = find(edge[i].v, Fa);
            if(fu != fv)
            {
                Ka[find(fu, Ka)] = find(fv, Ka);//只更新连通分量用的并查集  
                vis[fu] = 1;  
                vis[fv] = 1;  
                A[fu][fv]++;  
                A[fv][fu]++;  
                //注意这里不更新Kruskal的并查集, 在这一阶段结束才更新, 这是为了使得邻接矩阵代表出连通分量之间的关系  
            }
            if(i == m - 1 || edge[i + 1].w != pre)  //结束一个阶段
            {  
                ans = ans*matrixTree() % p;  
                pre = edge[i + 1].w;  
            }  
        }
        for(int i = 2; i <= n; i++)  
            if(Ka[i] != Ka[i - 1])//图不连通  
            {  
                ans = 0;  
                break;  
            }  
        printf("%lld\n", ans % p);  
    }
    //system("pause");
}

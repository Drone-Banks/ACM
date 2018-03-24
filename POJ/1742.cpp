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

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

int n,V;
int A[101];
int C[101];
int DP[MaxN];
int num[MaxN];
void ZeroOnePack(int cost, int weight)  //O(N*V)
{
    for(int v=V;v>=cost;v--)            //逆序遍历，保证每种物品只能被选择一次
        DP[v] |= DP[v-cost]; 
}
void CompletePack(int cost, int weight) //O(N*V)
{
    for(int v=cost;v<=V;v++)            // 顺序遍历，使得每种物品可以被选择无限次
        DP[v] |= DP[v-cost];
}
void MultiplePack(int cost, int weight, int amount)  //O(V*∑log(amount))
{
    if(cost*amount >=V)
    {
        CompletePack(cost, weight);
    }
    else
    {
        int k = 1;
        while(k<amount)         //指数拆分
        {
            ZeroOnePack(k*cost, k*weight);
            amount -= k;
            k*=2;
        }
        ZeroOnePack(amount*cost, amount*weight);
    }
}
void solve()
{
    CLR(DP);
    DP[0] = 1;
    for(int i=1;i<=n;i++)
        MultiplePack(A[i],A[i],C[i]);

    int ans = 0;
    for(int i=1;i<=V;i++) if(DP[i]) ans++;
    printf("%d\n", ans);
}

int main()
{
    while(~scanf("%d%d", &n, &V) && (n!=0 && V!=0) )
    {
        for(int i=1;i<=n;i++) scanf("%d", &A[i]);
        for(int i=1;i<=n;i++) scanf("%d", &C[i]);
        solve();
    }
    system("pause");
}
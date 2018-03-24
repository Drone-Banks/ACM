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

#define MaxN 2000
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;

int T;
int N,M;

int Map[MaxN][MaxN];
int Mark[MaxN][MaxN];
int Max[MaxN];
int Need[MaxN];

int flag[MaxN];

bool DFS(int x)
{
    for(int i=1;i<=N;i++)
    {
        if(!Map[x][i]||flag[i])
          continue;
        flag[i] = 1;

        if( Mark[i][0]<Max[i])
        {
            Mark[i][++Mark[i][0]] = x;
            return true;
        }

        for(int j=1;j<=Mark[i][0];j++)
        {
            if(DFS(Mark[i][j]))
            {
                Mark[i][j] = x;
                return true;
            }
        }
    }
    return false;
}

int Hungarian()
{
    int ans = 0;
    CLR(Mark);
    for(int i=1;i<=M;i++)
    {
        CLR(flag);
        while(Need[i])
        {
            if(!DFS(i))
            {
                return false;
            }
            Need[i]--;
        }
        
    }
    return true;
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        CLR(Map);
        scanf("%d%d", &N, &M);
        M.clear();
        for(int i=1;i<=M;i++)
        {
            scanf("%d", &Need[i]);
        }

        for(int i=1;i<=N;i++)
        {
            scanf("%d",&Max[i]);
            int k;
            A[i] = k;
            B[i] = k;
            scanf("%d", &k);
            while(k--)
            {
                int x;
                scanf("%d", &x);
                Map[x][i] = 1;
            }
        }
        sort
        int ans = Hungarian();

        if(ans) cout << "Yes\n";
        else cout << "No\n";
    }
    system("pause");
}
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

#define MaxN 2017
#define MaxM 2017*2017/2
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
int T,n;
char str[MaxN][MaxN];
struct Edge
{
    int v,next;
}edge[MaxM];
int cont,head[MaxN], in[MaxN];
bool topo()
{
    queue<int> Q;
    int cnt = 0;    
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
        {
            Q.push(i);
            cnt++;
        }
    }
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            in[v]--;
            if(in[v]==0) Q.push(v),cnt++;
        }
    }
    if(cnt<n) return false;
    return true;
}
void inline init()
{
    cont = 0;
    MST(head,-1);
    CLR(in);
}
void inline add(int u, int v)
{
    in[v]++; 
    edge[cont].v = v, edge[cont].next = head[u], head[u] = cont++;
}
void solve()
{
    init();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(str[i][j]=='P') add(i,j);
            if(str[i][j]=='Q') add(i,j);
        }
    }
    if(!topo()) 
    {
        puts("N");
        return;
    }
    init();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(str[i][j]=='P') add(i,j);
            if(str[i][j]=='Q') add(j,i);
        }
    }
    if(!topo())  puts("N");
    else puts("T");
}
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i=1;i<=n;i++)
        {
            scanf("%s", str[i]+1);
        }
        solve();
    }
    //system("pause");
}

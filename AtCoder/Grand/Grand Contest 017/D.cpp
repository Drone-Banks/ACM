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

#define MaxN 100001
#define MaxM MaxN*4
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
int N;
struct Edge
{
    int v,next;
}edge[MaxM];
int cont,head[MaxN];
void add(int u, int v)
{
    edge[cont].v = v, edge[cont].next = head[u], head[u] = cont++;
}

int DFS(int u, int pre)
{
    int flag = 0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(v==pre) continue;
        flag ^= (DFS(v,u)+1);
    }
    return flag;
}
void solve()
{
    if(DFS(1,0)) puts("Alice");
    else puts("Bob");
}

void init()
{
    cont = 0;
    MST(head,-1);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(scanf("%d", &N)!=EOF)
    {
        init();
        int a,b;
        for(int i=1;i<N;i++)
        {
            scanf("%d%d", &a, &b);
            add(a,b);add(b,a);
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

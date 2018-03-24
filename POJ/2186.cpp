/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <iomanip>
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

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}

struct Edge
{
    int u,v,next;
}edge[MaxM];
int cont, head[MaxN];
void add(int u, int v)
{
    edge[cont].u = u;
    edge[cont].v = v;
    edge[cont].next = head[u];
    head[u] = cont++;
}

int N,M;
int dfn[MaxN], low[MaxN],index, Stack[MaxN], top;
bool instack[MaxN];
int  belong[MaxN], scc;
void Tarjan(int u)
{
    dfn[u] = low[u] = ++index;
    instack[u] = true;
    Stack[++top] = u;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(!dfn[v])
        {
            Tarjan(v);
            if( low[u] > low[v]) low[u] = low[v];
        }
        else if( instack[v] && dfn[v] < low[u] ) 
        {
            low[u] = dfn[v];
        }
    }
    if( dfn[u] == low[u] )
    {
        ++scc;
        int node;
        do
        {
            node = Stack[top--];
            instack[node] = false;
            belong[node] = scc;
        }while(node!=u);
    }
}
int out[MaxN], in[MaxN];
void solve()
{
    CLR(dfn);
    CLR(low);
    index = 0, top = 0, scc = 0;
    CLR(in);
    CLR(out);
    for(int i=1;i<=N;i++)
    {
        if(!dfn[i])
            Tarjan(i);
    }
    for(int i=0;i<cont;i++)
    {
        int u = edge[i].u, v = edge[i].v;
        if(belong[u]!=belong[v])
        {
            //cout << u << " - " << endl;
            out[belong[u]]++;
        }
    }
    int ans = -1;
    for(int i=1;i<=scc;i++)
    {
        //debug(i)
        //debug(out[i])
        if(out[i]==0)
        {
            if(ans==-1) ans = i;
            else 
            {
                ans = -1;
                break;
            }
        }
        
    }
    if(ans == -1) cout << 0 << endl;
    else 
    {
        int cnt = 0;
        for(int i=1;i<=N;i++)
        {
            if(belong[i]==ans) cnt++;
        }
        cout << cnt << endl;
    }
}


void init()
{
    cont = 0;
    MST(head,-1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>N>>M)
    {
        init();
        int a, b;
        while(M--)
        {
            cin >> a >> b;
            add(a,b);
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

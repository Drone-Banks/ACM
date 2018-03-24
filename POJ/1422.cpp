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
int T,N,M;
struct Edge
{
    int v,next;
}edge[MaxM];
int cont,head[MaxN];
void add(int u, int v)
{
    edge[cont].v = v;
    edge[cont].next = head[u];
    head[u] = cont++;
}
int match[MaxN];
bool check[MaxN];
bool DFS(int u)
{
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(!check[v])
        {
            check[v] = true;
            if(match[v]==-1 || DFS(match[v]))
            {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
    }
    return false;
}
void Hungarian()
{
    int ans = 0;
    MST(match,-1);
    for(int i=1;i<=N;i++)
    {
        if(match[i]==-1)
        {
            CLR(check);
            if(DFS(i)) ans++;
        }
    }   
    cout << N-ans << endl;
}
void solve()
{
    Hungarian();
}
void init()
{
    cont = 0;
    MST(head,-1);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        init();
        while(M--)
        {
            int u, v;
            cin >> u >> v;
            add(u,N+v);
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

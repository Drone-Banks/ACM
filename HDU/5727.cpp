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

#define MaxN 12
#define MaxM MaxN*20
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
int N,M,ans;
struct Edge
{
    int v,next;
}edge[MaxM];
int cont,head[10];
void add(int u, int v)
{
    edge[cont].v = v;
    edge[cont].next = head[u];
    head[u] = cont++;
}
int yin[10];
bool Map[10][10];
int match[10];
bool check[10];
bool DFS(int u)
{
    for(int v=1;v<=N;v++)
    {
        if(Map[u][v] && !check[v])
        {
            check[v] = true;
            if(match[v]==-1 || DFS(match[v]))
            {
                match[v] = u; 
                return true;
            }
        }
    }
    return false;
}
void Hungarian()
{
    MST(match,-1);
    int tmp = 0;
    for(int i=1;i<=N;i++)
    {
        CLR(check);
        if(DFS(i)) tmp++;
    }
    ans = max(ans, tmp);
}
void solve()
{
    ans = 0;
    for(int i=1;i<=N;i++) yin[i] = i; 
    do
    {
        MST(Map,1);
        for(int i=1;i<=N;i++)
        {
            for(int j=head[i];j!=-1;j=edge[j].next)
            {
                int v = yin[edge[j].v];
                int last = v-1 ? v-1 : N;
                Map[i][v] = Map[i][last] = false;
            }
        }
        Hungarian();
        if(ans==N) break;
    }while(next_permutation(yin+2, yin+1+N));
    printf("%d\n", N-ans);
}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d",&N,&M))
    {
        cont = 0;
        MST(head,-1);
        while(M--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}
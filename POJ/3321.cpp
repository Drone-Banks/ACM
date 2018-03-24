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
#define MaxM MaxN*4
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
int cont,head[MaxN];
void add(int u, int v)
{
    edge[cont].u = u, edge[cont].v = v, edge[cont].next = head[u], head[u] = cont++;
}
int N,M,low[MaxN],high[MaxN],flag[MaxN];
int DFS(int u,int &index)
{
    low[u] = ++index;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        DFS(v,index);
    }
    high[u] = index;
}
struct BIT{
    int n;
    int tree[MaxN];
    void init(int n)
    {
        this->n = n;
        CLR(tree);
    }
    int lowbit(int x)
    {
        return x & (-x);
    }
    int sum(int n)
    {
        int ans = 0;
        for(int i=n;i;i-=lowbit(i))
        {
            ans = (ans + tree[i]) % mod;
        }
        return ans;
    }
    void update(int x, int val)
    {
        for(int i=x;i<=n;i+=lowbit(i))
        {
            tree[i] = (tree[i]+val)%mod;
        }
    }
}bit;
void init()
{
    cont = 0;
    MST(head,-1);
    bit.init(N);
    for(int i=1;i<=N;i++)
    {
        bit.update(i,1);
        flag[i] = true;
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &N))
    {
        init();
        int a,b;
        for(int i=1;i<N;i++)
        {
            scanf("%d%d", &a, &b);
            add(a,b);
        }
        int index = 0;
        DFS(1,index);
        char ch;
        scanf("%d", &M);
        while(M--)
        {
            getchar();
            ch = getchar();
            scanf("%d", &a); 
            //debug(a);
            if(ch == 'C')
            {
                //debug(flag[a]);
                if(flag[a]) bit.update(low[a],-1);
                else bit.update(low[a],1);
                flag[a]^=1;
            }
            else
            {
                printf("%d\n", bit.sum(high[a]) - bit.sum(low[a]-1) );
            }
        }
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

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
#define ALL(a) a.begin(), a.end()
using namespace std;

#define MaxN 100005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
inline int max2(int a, int b) {return ((a > b)? a : b);}
inline int min2(int a, int b) {return ((a < b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}
inline int min3(int a, int b, int c) {return min2(a, min2(b, c));}
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
struct Node
{
    int id,step;
    Node(){}
    Node(int a, int b):id(a),step(b){}
};
int N;
bool vis[MaxN];
void solve()
{
    CLR(vis);
    queue<Node> Q,ans;
    Q.push(Node(1,0));
    vis[1] = true;
    bool flag = true;
    int limit = INF;
    while(!Q.empty())
    {
        Node tmp = Q.front();
        Q.pop();
        ans.push(tmp);
        int u = tmp.id;
        for(int i=head[u];i!=-1&&flag;i=edge[i].next)
        {
            int v = edge[i].v;
            if(vis[v]) continue;
            vis[v] = true;
            if(v==N)
            {
                limit = min(limit, tmp.step);
            }
            Q.push(Node(v,tmp.step+1));
        }
        if(!flag) break;
    }
    CLR(vis);
    limit = (limit+1)/2;
    //debug(limit)
    while(!ans.empty())
    {
        Node tmp = ans.front();
        ans.pop();
        if(tmp.step<=limit)
        {
            vis[tmp.id]=true;
            //debug(tmp.id);
        }
    }
    Q.push(Node(N,0));
    vis[N] = true;
    int cnt = 0;
    while(!Q.empty())
    {
        Node tmp = Q.front();
        Q.pop();
        int u = tmp.id;
        for(int i=head[u];i!=-1&&flag;i=edge[i].next)
        {
            int v = edge[i].v;
            //debug(v) debug(vis[v])
            if(vis[v]) continue;
            vis[v] = true;
            
            cnt++;
            Q.push(Node(v,tmp.step+1));
        }
    }
    int a = N-2-cnt;
    //debug(a) debug(cnt)
    if(cnt<a) puts("Fennec");
    else puts("Snuke");
}
void init()
{
    cont = 0;
    MST(head,-1);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &N))
    {
        init();
        int a, b;
        for(int i=1;i<N;i++)
        {
            scanf("%d%d", &a, &b);
            add(a,b);
            add(b,a);
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

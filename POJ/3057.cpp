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

#define MaxN 101400
#define MaxM MaxN*20
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;

int T,N,M,n;
char Map[30][30];
int Index[30][30];
int Exits,Peoples;
struct Node
{
    int x,y;
    int step;
    Node(){};
    Node(int a,int b,int c){x=a;y=b;step=c;};
}node[MaxN];
struct Edge
{
    int u,v,next;
}edge[MaxM];
int cont;
int head[MaxN];
void add(int u, int v)
{
    edge[cont].u = u;edge[cont].v = v;
    edge[cont].next = head[u];
    head[u] = cont++;
}
void Add(int u, int v)
{
    add(u,v);add(v,u);
}
int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
int flag[MaxN];
bool judge(int x, int y)
{
    if(x<0 || x>=N || y<0 || y>=M || Map[x][y]!='.' || flag[Index[x][y]]==1) return false;
    else return true; 
}
void BFS(Node P, int num)
{
    CLR(flag);
    P.step = 0;
    queue<Node> Q;
    Q.push(P);
    while(!Q.empty())
    {
        Node tmp = Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            int xx = tmp.x + dir[i][0];
            int yy = tmp.y + dir[i][1];
            if(judge(xx,yy))
            {
                flag[Index[xx][yy]] = 1;
                Node cnt(xx,yy,tmp.step+1);
                Q.push(cnt);
                //Add( (num-1)*Peoples+cnt.step, Index[xx][yy]+Exits*Peoples);
                int times = cnt.step;
                while(times<=n)
                {
                    //cout << (times-1)*Exits+num << " " << n*Exits+Index[xx][yy] << endl;
                    Add( (times-1)*Exits+num, n*Exits+Index[xx][yy]);
                    times++;
                }
            }
        }
    }
}

int match[MaxN];
bool check[MaxN];
bool DFS(int u)
{
    check[u] = true;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        int w = match[v];
        if( w==-1|| !check[w] && DFS(w))
        {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}
void Hungarian()
{
    //cout << Exits << " " << Peoples << endl;
    int ans = 0;
    MST(match, -1);
    for(int i=0;i<n*Exits;i++)
    {
        CLR(check);
        if(DFS(i))
        {
            //cout << i << endl;
            if(++ans == Peoples)
            {
                printf("%d\n", i/Exits+1);
                return;
            }
        }
    }
    printf("impossible\n");
}
void solve()
{
    if(Peoples==0) 
    {
        printf("0\n");
        return;
    }
    if(Exits==0)
    {
        printf("impossible\n");
        return;
    }
    for(int i=0;i<Exits;i++)
    {
        BFS(node[i], i);
    }
    Hungarian();
}
void init()
{
    Exits = 0;
    Peoples = 0;
    cont = 0;
    MST(head, -1);
    MST(Index,0);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &T);
    while(T--)
    {
        init();
        scanf("%d%d", &N,&M);
        n = N*M;
        for(int i=0;i<N;i++) scanf("%s", Map[i]);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(Map[i][j] == 'D') 
                {
                    node[Exits].x = i;
                    node[Exits].y = j;
                    Index[i][j] = Exits++;
                }
                else if(Map[i][j] == '.') Index[i][j] = Peoples++;
            }
        }
        solve();
    }
    //system("pause");
}
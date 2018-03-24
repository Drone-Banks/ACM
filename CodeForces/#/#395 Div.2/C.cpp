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
#define MaxM MaxN*2
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

int n;

struct Edge
{
    int u,v;
    int next;
}edge[MaxM];
int cont;
int head[MaxN];

void add(int u, int v)
{
    edge[cont].u = u;
    edge[cont].v = v;
    edge[cont].next = head[u];
    head[u] = cont++;
}

int c[MaxN];
int flag[MaxN];
int tip[MaxN];
int ans;
void init()
{
    cont = 0;  
    MST(head, -1);
    CLR(flag);
}

void dfs(int u)
{
    //cout << u <<"  :color:  " << color  << " "<<ans<< endl; 
    tip[u] = 1;
    if(ans != 0 ) return;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(!tip[v])
        {
            if(c[v] == c[u]) dfs(v);
            else
            {
                ans = u;
                return;
            }
        }
    }
}

bool solve(int x)
{
    flag[x] = 1;
    int count = 0;
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        CLR(tip);
        tip[x] = 1;
        tip[v] = 1;
        //cout << ans << endl;
        dfs(v);
        //cout << ans << endl;
        //cout << x << "--" << v << " : " << ans << endl;
        if(ans == 0) continue;
        else
        {
            if(flag[ans])
            {
                count++;
                ans = 0;
            }
            else
            {
                return false;   
            }
        }
    }
    if(count == 0) return true;
    else return false;
}


int main()
{
    while(~scanf("%d", &n))
    {
        init();
        for(int i=1;i<n;i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            add(a,b);add(b,a);
        }
        for(int i=1;i<=n;i++) scanf("%d", &c[i]);
        ans = 0;
        int cnt = 1;
        int times = 0;
        while(!solve(cnt))
        {
            //cout << cnt << "__" << ans << endl;
            times++;
            if(ans == 0 || times>=3)
            {
                cnt = -1;
                break;
            }
            
            cnt = ans;
            ans = 0;
        }
        if(cnt == -1) printf("NO\n");
        else
        {
            printf("YES\n");
            printf("%d\n",cnt);
        }
    }
    //system("pause");
}
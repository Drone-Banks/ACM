/*************************************************************************
	> File Name: K.cpp
	> Author: Akira
	> Mail: qaq.febr2.qaq@gmail.com
	> Created Time: 2017年05月05日 星期五 21时08分56秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<cmath>
#include<vector>
#include<set>
#include<list>
#include<ctime>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))

using namespace std;

#define MaxN 2000
#define MaxM MaxN*20
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1e9+7;
const int eps = 1e-8;
#define bug cout << 88888888 << endl;

int T;
int n,s,x;

struct Edge
{
    int u, v, next;
}edge[MaxM];
int cont, head[MaxN];

void add(int u, int v)
{
    edge[cont].v = v;
    edge[cont].next = head[u];
    head[u] = cont++;
}

void init()
{
    cont = 0;
    MST(head, -1);
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
                match[u]=  v;
                return true;
            }
        }
    }
    return false;
}

int Hungarian()
{
    int ans = 0;
    MST(match, -1);
    for(int i=1;i<=x;i++)
    {
        if(match[i] == -1)
        {
            CLR(check);
            if(DFS(i)) ans++;
        }
    }
    //for(int i=1;i<=n;i++) cout << i << " - " << match[i] << endl;
    return ans;
}


int main()
{
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d", &n, &s);
        printf("Case #%d: ",  t);
        int sta = max(s,n);
        if(s==0||s==1||s==2) puts("Yes");
        else if( (s+n - sta )>=600) puts("No");
        else 
        {
            init();
            x = s+n - sta;
            for(int i=sta+1; i<=s+n; i++)
            {
                for(int j=1;j<=x;j++)
                {
                    if(i%j==0) add(i-sta+x, j), add(j, i-sta+x);
                }
            }
            int cnt = Hungarian();
            if(cnt==x) puts("Yes");
            else puts("No");    
        }
    }
}
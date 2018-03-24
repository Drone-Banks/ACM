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

int N;
bool Map[110][110];

int dfn[110],low[110],index;
int sum[110];
int ans;
void Tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++index;
    bool flag = false;
    for(int v=1; v<=N; v++)
    {
        if(Map[u][v] && v!=fa)
        {
            if(!dfn[v])
            {
                Tarjan(v,u);
                if( low[v] < low[u]) low[u] = low[v];
                if(low[v] >= dfn[u]) ++sum[u];
            }
            else if( dfn[v] < low[u] ) low[u] = dfn[v];
        }
    }
    if(u==fa) sum[u]--;
}
void solve()
{
    for(int i=1;i<=N;i++)
    {
        if(!dfn[i]) Tarjan(i,i);
    }
    for(int i=1;i<=N;i++)
    {
        if(sum[i]) ans++;
    }
    cout << ans << endl;
}
void init()
{
    CLR(sum);
    CLR(Map);
    CLR(dfn);
    CLR(low);
    index = ans = 0;
}
int main()  
{  
    //fread();  
    //fwrite();  
  
    int u,v;  
    while(~scanf("%d",&N) && N)  
    {  
        init();  
        while(~scanf("%d",&u) && u)  
        {  
            while(getchar() != '\n')  
            {  
                scanf("%d",&v);  
                Map[u][v] = Map[v][u] = 1;  
            }  
        }  
  
        solve();
    }  
  
    return 0;  
}  
/*
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin >> N && N)
    {
        init();
        //debug(N);
        char ch = getchar();
        int u = ch - '0';
        while(u)
        {
            ch = getchar();
            //debug(ch);
            while(ch!='\n')
            {
                ch = getchar();
                int v = ch - '0';
                Map[u][v] = Map[v][u] = true;
                //debug(v);
                ch = getchar();
            }
            ch = getchar();
            u = ch - '0';
        }
        ch = getchar();
        solve();
    }

    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}
*/
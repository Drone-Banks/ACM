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
#include <Map>
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

#define MaxN 505
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

int n,m,qq;
int Map[MaxN][MaxN]; 

int dis[MaxN];
int cnt[MaxN];
bool vis[MaxN];

int SPFA(int s)  
{
    for(int i=0;i<=n;i++)  dis[i]=INF;  
    dis[s]=0;
    CLR(vis);
    CLR(cnt);
    queue<int> q;  
    q.push(s);
    vis[s]=1;  
    while(!q.empty())  
    {  
        int cur=q.front();  
        q.pop();  
        vis[cur]=0;  
        for(int i=1;i<=n;i++)  
        {  
            if(dis[cur] + Map[cur][i] < dis[i])
            {  
                dis[i]=dis[cur] + Map[cur][i];  
                if(!vis[i])  
                {  
                    if(cnt[i]>=n) return true;
                    q.push(i);
                    cnt[i]++;  
                    vis[i]=true;  
                }  
            }  
        }  
    }
    return false;
}


int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int a,b,c;;
        scanf("%d%d%d",&n,&m, &qq);
        memset(Map, INF, sizeof(Map));
        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if (Map[a][b]) Map[a][b]=MIN(Map[a][b],c);
			else Map[a][b]=c;
			if (Map[b][a]) Map[b][a]=MIN(Map[b][a],c);
			else Map[b][a]=c;
        }
        for(int i=1;i<=qq;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if (Map[a][b])
				Map[a][b]=min(Map[a][b],-c);
			else Map[a][b]=-c;
        }
        if( SPFA(1) ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    system("pause");
}
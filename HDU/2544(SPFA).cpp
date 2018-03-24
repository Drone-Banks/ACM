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

#define MaxN 200
#define MaxM MaxN*10
#define INF 1000000000
#define bug cout<<88888888<<endl;

int N,M;

int Map[MaxN][MaxN];  
int dis[MaxN];  
bool vis[MaxN];

int SPFA(int s,int t)  
{
    int n = N; 
    for(int i=1;i<=n;i++)  //n表示图中的点数
        dis[i]=INF;  
    CLR(vis);
    vis[s]=1;  
    dis[s]=0;  
    queue<int> q;  
    q.push(s);  
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
                    q.push(i);  
                    vis[i]=true;  
                }  
            }  
        }  
    }
    if(dis[t] == INF)
        return -1;
    return dis[t];  
}  


int main()
{
    while(cin >> N >> M && (N+M))
    {
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                Map[i][j] = INF;


        for(int i=0;i<M;i++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            Map[a][b] = Map[b][a] = c;
        }
        int ans = SPFA(1,N);
        cout << ans << endl;
    }

    system("pause");
}
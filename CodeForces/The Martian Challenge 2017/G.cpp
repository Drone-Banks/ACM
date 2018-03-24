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
using namespace std;

#define MaxN 100001
#define MaxM MaxN*10
#define INF 1E9+7
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
int n;
struct Node
{
    int val,ord;
}node[110];
int vis[110];
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &node[i].val);
    for(int i=1;i<=n;i++) {int x;scanf("%d", &x);node[x].ord = i;}
    sort(node+1,node+n+1,[](Node x,Node y){return x.ord<y.ord;});
    int ans = 0;
    for(int i=2;i<=n;i+=2)
    {
        vis[i-1] = 1;
        int MIN = INF,loc;
        for(int j=1;j<i;j++)
        {
            if(vis[j] && MIN > node[j].val) 
            {
                MIN = node[j].val;
                loc = j;
            }
        }
        if( node[i].val > MIN ) 
        {
            vis[loc] = 0;
            vis[i] = 1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) ans += node[i].val;
        else ans -= node[i].val;
    }
    printf("%d\n", ans);
    //system("pause");
}

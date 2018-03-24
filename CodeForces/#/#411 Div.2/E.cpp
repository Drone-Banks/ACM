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
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
int color[MaxN];
set<int> Tree[MaxN];
vector<int> Graph[MaxN];
map<int,int> M[MaxN];

int n,m;

void solve()
{
    for(int i=1;i<=n;i++)
    {
        for (int j=0;j )
        {
            cout << node.id << " : " << color[node.id] << endl;
            if(color[node.id] == INF) 
            {
                bug;
                if(!Q.empty())
                {
                    color[node.id] = Q.top();
                    Q.pop();
                }
                else color[node.id] = cnt++;
            }
            else 
            {
                if(color[node.id] == cnt) cnt++;
                else
                {
                    while(cnt!=color[node.id] && Q.size() <= Tree[i].size() )
                    {
                        Q.push(cnt);
                        cnt++;
                    }
                    if(cnt==color[node.id]) cnt++;
                }
            }
            cout << node.id << " : " << color[node.id] << endl;
        }
    }
    int ans = 0;
    for(int i=1;i<=m;i++) ans = max(ans, color[i]);
    printf("%d\n", ans);
    for(int i=1;i<=m;i++) 
    {
        printf("%d", color[i]);
        if(i!=m) printf(" ");
        else printf("\n");        
    }
}

int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    for(int i=1;i<=m;i++) color[i] = INF;
    int num;
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &num);
        int x;
        while(num--)
        {
            scanf("%d", &x);
            Tree[i].insert(x);
            Graph[x].push_back(i);
        }
    }
    int a,b;
    for(int i=1;i<n;i++) scanf("%d%d", &a, &b);
    solve();
    system("pause");
}

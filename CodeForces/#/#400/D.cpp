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
#define debug(x) cout << #x" = " << x;

struct TwoSAT
{
    int n;
    vector<int> G[MaxN*2];
    int S[MaxN*2],c;
    bool mark[MaxN*2];

    bool dfs(int x)
    {
        if(mark[x^1]) return false;
        if(mark[x]) return true;
        mark[x]=true;
        S[c++]=x;
        for(int i=0;i<G[x].size();i++)
            if(!dfs(G[x][i])) return false;
        return true;
    }

    void init(int n)
    {
        this->n=n;
        for(int i=0;i<n*2;i++) G[i].clear();
        memset(mark,0,sizeof(mark));
    }

    void add_clause(int x,int xval,int y,int yval)//这里做了修改,指x与y值有冲突
    {
        x=x*2+xval;
        y=y*2+yval;
        G[x].push_back(y^1);
        G[y].push_back(x^1);
    }

    bool solve()
    {
        for(int i=0;i<2*n;i+=2)if(!mark[i] && !mark[i+1])
        {
            c=0;
            if(!dfs(i))
            {
                while(c>0) mark[S[--c]]=false;
                if(!dfs(i+1)) return false;
            }
        }
        return true;
    }
}TS;
int n,m;
int unlock[MaxN];
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &m))
    {
        TS.init(m);
        vector<int> door_key[MaxN];
        for(int i=0;i<n;i++) scanf("%d", unlock+i);
        for(int i=0;i<m;i++)
        {
            int sz;
            scanf("%d", &sz);
            while(sz--)
            {
                int x;
                scanf("%d", &x);
                door_key[x-1].push_back(i);
            }
        }
        for(int i=0;i<n;i++)
        {
            //cout << door_key[i][0]<<" " << door_key[i][1] << endl;
            if(unlock[i])
            {
                TS.add_clause(door_key[i][0], 1, door_key[i][1], 0);
                TS.add_clause(door_key[i][0], 0, door_key[i][1], 1);
            }
            else
            {
                TS.add_clause(door_key[i][0], 0, door_key[i][1], 0);
                TS.add_clause(door_key[i][0], 1, door_key[i][1], 1);
            }
        }
        if(!TS.solve()) puts("NO");
        else puts("YES");
    }
    //system("pause");
}

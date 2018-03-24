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
int now,ans;
bool MARK[MaxN*2];
int n,m;
int x[MaxM];
int y[MaxM];
char ch[MaxM];
vector<int> ans1,ans2;
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
		if( x&1) now++;
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
		int re=0,x;
        for(int i=0;i<2*n;i+=2)
		if(!mark[i] && !mark[i+1])
        {
			now = 0;
            c=0;
            if(!dfs(i))
            {
                while(c>0) mark[S[--c]]=false;
                if(!dfs(i+1)) return false;
				re+=now;
            }
			else
			{
				x = now;
				now = 0;
				while(c>0) mark[S[--c]]=false;
				if(!dfs(i+1)||now>x)
				{
					now = 0;
					while(c>0) mark[S[--c]]=false;
					dfs(i);
				}
				re += now;
			}
        }
		if(re<ans)
		{
			ans = re;
			memcpy(MARK,mark,sizeof(mark));
		}
        return true;
    }
}TS,TT;

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n,&m))
    {
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %c",x+i,y+i,ch+i);
            x[i]-=1;
            y[i]-=1;
        }
        TS.init(n);
        TT.init(n);
        for(int i=0;i<m;i++)
        {
            if(ch[i]=='R') 
            {
                TS.add_clause(x[i], 1, y[i], 0);
                TS.add_clause(x[i], 0, y[i], 1);
                TT.add_clause(x[i], 1, y[i], 1);
                TT.add_clause(x[i], 0, y[i], 0);
            }
            else
            {
                TS.add_clause(x[i], 1, y[i], 1);
                TS.add_clause(x[i], 0, y[i], 0);
                TT.add_clause(x[i], 1, y[i], 0);
                TT.add_clause(x[i], 0, y[i], 1);
            }
        }
        ans = INF;
		TS.solve();
		TT.solve();
		if(ans==INF) puts("-1");
		else
		{
			printf("%d\n", ans);
			int cnt = 0;
			for(int i=0;i<n;i++)
			{
				if(MARK[i*2+1])
				{
					cnt++;
					printf("%d%c",i+1, cnt<ans?' ':'\n');
				}
			}
		}
    }
    //system("pause");
}
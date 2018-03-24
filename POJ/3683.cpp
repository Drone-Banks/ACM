/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

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

#define MaxN 1010
#define MaxM MaxN*20
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x;
int N;
struct Time
{
    int s,e,d;//开始,结束,持续
    Time(){}
    Time(int s,int e,int d):s(s),e(e),d(d){}
}t[MaxN];
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
        for(int i=0;i<2*n;i+=2)
            if(!mark[i] && !mark[i+1])
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

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &N))
    {
        for(int i=0;i<N;i++)
        {
            int sh,sm,eh,em,d;
            scanf("%d:%d %d:%d %d",&sh,&sm,&eh,&em,&d);
            t[i]=Time(sh*60+sm,eh*60+em,d);
        }
        TS.init(N);
        for(int i=0;i<N;i++)
            for(int j=i+1;j<N;j++)
            {
                if(t[i].s < t[j].s+t[j].d && t[j].s < t[i].s+t[i].d )
                    TS.add_clause(i,0,j,0); 
                if(t[i].s < t[j].e && t[j].e-t[j].d < t[i].s+t[i].d )
                    TS.add_clause(i,0,j,1);
                if(t[i].e-t[i].d < t[j].s+t[j].d && t[j].s < t[i].e)
                    TS.add_clause(i,1,j,0);
                if(t[i].e-t[i].d < t[j].e && t[j].e-t[j].d < t[i].e)
                    TS.add_clause(i,1,j,1);
            }
        if(!TS.solve()) printf("NO\n");
        else
        {
            printf("YES\n");
            for(int i=0;i<N;i++)
            {
                if(TS.mark[i*2])
                    printf("%02d:%02d %02d:%02d\n",t[i].s/60,t[i].s%60,(t[i].s+t[i].d)/60,(t[i].s+t[i].d)%60);
                else
                    printf("%02d:%02d %02d:%02d\n",(t[i].e-t[i].d)/60,(t[i].e-t[i].d)%60,t[i].e/60,t[i].e%60);
            }
        }
    }
    //system("pause");
}

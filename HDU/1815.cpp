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

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x;
int N,A,B;
struct Node
{
    int x,y;
}node[510],S1,S2;
pair<int,int> Hate[1010],Like[1010];
int dist1[510],dist2[510],dist;
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

bool judge(int x)
{
    TS.init(N);
    for(int i=0;i<A;i++)
    {
        int x = Hate[i].first, y = Hate[i].second;
        TS.add_clause(x, 0, y, 0);
        TS.add_clause(x, 1, y, 1);
    }
    for(int i=0;i<B;i++)
    {
        int x = Like[i].first, y = Like[i].second;
        TS.add_clause(x, 0, y, 1);
        TS.add_clause(x, 1, y, 0);
    }
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if( dist1[i]+dist1[j] > x) TS.add_clause(i,0,j,0);
            if( dist1[i]+dist2[j]+dist > x) TS.add_clause(i,0,j,1);
            if( dist2[i]+dist1[j]+dist > x) TS.add_clause(i,1,j,0);
            if( dist2[i]+dist2[j] > x) TS.add_clause(i,1,j,1);
        }
    }
    if(TS.solve()) return true;
    else return false;
}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d%d", &N, &A, &B))
    {
        scanf("%d%d%d%d", &S1.x, &S1.y, &S2.x, &S2.y);
        dist = abs(S1.x-S2.x)+abs(S1.y-S2.y);
        for(int i=0;i<N;i++) 
        {
            scanf("%d%d", &node[i].x, &node[i].y);
            dist1[i] = abs(node[i].x-S1.x)+abs(node[i].y-S1.y);
            dist2[i] = abs(node[i].x-S2.x)+abs(node[i].y-S2.y);
        }
        for(int i=0;i<A;i++) {scanf("%d%d", &Hate[i].first, &Hate[i].second);Hate[i].first--,Hate[i].second--;}
        for(int i=0;i<B;i++) {scanf("%d%d", &Like[i].first, &Like[i].second);Like[i].first--,Like[i].second--;}

        int l = 0, r = 8000000, ans=-1;
        while(l<=r)
        {
            int mid = (l+r)>>1;
            if( judge(mid) ) {r = mid-1;ans = mid;}
            else l = mid+1;
        }
        printf("%d\n", ans);
    }
    //system("pause");
}

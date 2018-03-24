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
#define bug cout<<88888888<<endl;
int N;
struct Node
{
    int L,R,id;
    bool operator<(const Node & a) const 
    {
        if(a.L == L) return a.R>R;
        else return a.L>L;
    }
}node[MaxN];
struct Right
{
    int x;
    int pos;
    Right(int a = 0, int b = 0){x = a, pos = b;}
    bool operator<(const Right & a) const
    {
        return a.x < x;
    }
};
priority_queue<Right> Q;
int vis[MaxN];
int main()
{
    //std::ios::sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        for(int i=1;i<=N;i++)scanf("%d", &node[i].L);
        for(int i=1;i<=N;i++)
        {
            scanf("%d", &node[i].R);
            node[i].id = i;
        }
        sort(node+1,node+1+N);
        CLR(vis);
        int now = 0;
        int _begin = 1;
        vector<int>ans;
        while(now<N)
        {
            for(;_begin<=N;_begin++)
            {
                if(node[_begin].L<=now)
                {
                    Q.push(Right(node[_begin].R,node[_begin].id));
                }
                else break;
            }
            if(!Q.empty())
            {
                Right tmp = Q.top();Q.pop();
                //cout <<now <<"--"<< tmp.x << endl;
                if(tmp.x>=now)
                {
                    //bug;
                    vis[tmp.pos] = 1;
                    ans.push_back(tmp.pos);
                    now++;
                }
            }
            else break;
        }
        printf("%d\n", ans.size());
        for(int i=1;i<=N;i++)
        {
            if(!vis[i]) ans.push_back(i);
        }
        for(int i=0;i<ans.size();i++)
            printf("%d%c", ans[i], i==ans.size()-1 ? '\n' : ' ');
    }
    //system("pause");
}

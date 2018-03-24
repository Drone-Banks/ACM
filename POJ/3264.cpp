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

#define MaxN 50005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
int N,Q;
int minV,maxV;
struct Node
{
    int L,R;
    int minV,maxV;
    int mid(){return (L+R)/2;}
}node[MaxN*3];

void build(int root, int L, int R)
{
    node[root].L = L;
    node[root].R = R;
    node[root].minV = INF;
    node[root].maxV = -INF;
    if(L!=R)
    {
        build(2*root,L,(L+R)/2);
        build(2*root+1,(L+R)/2+1,R);
    }
}

void insert(int root, int i, int v)
{
    if (node[root].L==node[root].R)  
    {  
        node[root].minV=v;  
        node[root].maxV=v;  
        return ;  
    }  
    node[root].minV=min(node[root].minV,v);  
    node[root].maxV=max(node[root].maxV,v);  
    if(i<=node[root].mid())  
        insert(root*2,i,v);  
    else  
        insert(root*2+1,i,v);
}

void query(int root, int s, int e) //查询区间[s,e]间最大值和最小值的差
{
    if(node[root].minV>=minV && node[root].maxV <= maxV) return;
    if(node[root].L==s && node[root].R == e) 
    {
        minV = min(node[root].minV, minV); 
        maxV = max(node[root].maxV, maxV);
        return;
    }
    if(e<=node[root].mid()) query(root*2,s,e);
    else if(s>node[root].mid()) query(root*2+1,s,e);
    else
    {
        query(root*2,s,node[root].mid());
        query(root*2+1,node[root].mid()+1,e);
    }
}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &N, &Q))
    {
        build(1,1,N);
        for(int i=1;i<=N;i++) 
        {
            int x;
            scanf("%d", &x);
            insert(1,i,x);
        }
        while(Q--)
        {
            int s,e;
            scanf("%d%d", &s, &e);
            minV = INF;
            maxV = -INF;
            query(1,s,e);
            printf("%d\n", maxV-minV);
        }
    }
    //system("pause");
}

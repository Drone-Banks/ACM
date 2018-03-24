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

#define MaxN 100000
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

struct Node{
    int dl;
    int cost;
}node[1001];
bool cmp(Node &a, Node &b)
{
    if(a.cost == b.cost) return a.dl<b.dl;
    return a.cost > b.cost;
}
int T;
int N;
int flag[MaxN];
int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        for(int i=0;i<N;i++) scanf("%d", &node[i].dl);
        for(int i=0;i<N;i++) scanf("%d", &node[i].cost);
        sort(node, node+N,cmp);
        CLR(flag);
        int ans = 0;
        for(int i=0;i<N;i++)
        {
            int dl = node[i].dl;
            int cost = node[i].cost;
            if( flag[dl] == 0) flag[dl] = 1;
            else
            {
                while(flag[dl]==1) dl--;
                if(dl ==0 ) ans += cost;
                else flag[dl] = 1;
            }
        }
        cout << ans << endl;
    }
    system("pause");
}
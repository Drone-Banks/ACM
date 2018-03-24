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

#define MaxN 200010
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x;
int N,K;
int fa[MaxN];
int getfather(int x)
{
    int fx=fa[x];
    if(fx!=x) 
    {
        fx=getfather(fa[x]);
    }
    return fa[x]=fx;
}
void U(int x,int y){
    int fx=getfather(x),fy=getfather(y);
    if(fx!=fy) fa[fy]=fx;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d%d", &N, &K);
    for(int i=1;i<=3*N;i++){
        fa[i]=i;
    }
    int ans = 0;
    int type,x,y;
    while(K--)
    {
        scanf("%d%d%d", &type, &x, &y);
        if(x<0||x>N||y<0||y>N||(type==2&&x==y)) 
        {
            ans++;
            continue;
        }
        if(type==1)
        {
            // A  B   C
            // x  x+N x+2N
            // y  y+N y+2N
            int fx = getfather(x);
            int fy1 = getfather(y+N);
            int fy2 = getfather(y+2*N);
            if( fx == fy1 || fx == fy2) ans++;
            else{
                U(x,y);
                U(x+N, y+N);
                U(x+2*N, y+2*N);
            }
        }
        else
        {   
            int fx = getfather(x);
            int fy1 = getfather(y);
            int fy2 = getfather(y+2*N);
            if( fx == fy1 || fx == fy2) ans++;
            else{
                U(x,y+N);
                U(x+N, y+2*N);
                U(x+2*N, y);
            }
        }
    }
    printf("%d\n", ans);
    system("pause");
}

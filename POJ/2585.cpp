/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <iomanip>
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
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}

bool Map[10][10];
char str[20];
int tu[4][4],in[10];
bool topo()
{
    queue<int> Q;
    for(int i=1;i<=9;i++)
    {
        if(!in[i]) Q.push(i);
    }
    int cnt = 0;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        //debug(u);
        cnt++;
        for(int i=1;i<=9;i++)
        {
            if(Map[u][i])
            {
                Map[u][i] = false;
                in[i]--;
                if(!in[i])
                {
                    Q.push(i);
                }
            }
        }
    }
    if(cnt>=9) return true;
    else return false;
}

void solve()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int ii=0;ii<2;ii++)
            for(int jj=0;jj<2;jj++)
            {
                int v = tu[i+ii][j+jj];
                int u =(i*3+j+1); 
                if(u!=v&&!Map[u][v])
                {
                    Map[u][v] = true;
                    ++in[v];
                }
            }
        }
    }
    printf("THESE WINDOWS ARE ");  
    puts(topo() ? "CLEAN" : "BROKEN");
}
void init()
{
    CLR(Map);
    CLR(in);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(scanf("%s", str), str[0] !='E')
    {
        for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        scanf("%d", &tu[i][j]);
        scanf("%s", str);
        init();
        solve(); 
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

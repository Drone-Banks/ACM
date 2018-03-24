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
#define ALL(a) a.begin(), a.end()
using namespace std;

#define MaxN 110
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
inline int max2(int a, int b) {return ((a > b)? a : b);}
inline int min2(int a, int b) {return ((a < b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}
inline int min3(int a, int b, int c) {return min2(a, min2(b, c));}

int weight[55][55];
int lx[MaxN], ly[MaxN], slack[MaxN];  
bool visitx[MaxN], visity[MaxN];  
int match[MaxN];  
int n, m;  
  
bool Hungary(int u)  
{  
    int temp;  
    visitx[u] = true;  
    for(int i = 1; i <= m; ++i)  
    {  
        if(visity[i])  
            continue;  
        temp = lx[u] + ly[i] - weight[u][i];  
        if(temp == 0)  
        {  
            visity[i] = true;  
            if(match[i] == - 1 || Hungary(match[i]))  
            {  
                match[i] = u;  
                return true;  
            }  
        }  
        else  
            slack[i] = min(slack[i], temp);  
    }  
    return false;  
}  
  
bool KM_Perfect_Match()  
{  
    int temp;  
    CLR(lx);  
    CLR(ly);  
    for(int i = 1; i <= n; ++i)  
        for(int j = 1; j <= m; ++j)  
            lx[i] = max(lx[i], weight[i][j]);  
    for(int i = 1; i <= n; ++i)  
    {  
        for(int j = 1; j <= m; ++j)  
            slack[j] = INF;  
        while(1)  
        {  
            CLR(visitx);  
            CLR(visity);  
            if(Hungary(i))  
                break;  
            else  
            {  
                temp = INF;  
                for(int j = 1; j <= m; ++j)  
                    if(!visity[j])  
                        temp = min(temp, slack[j]);  
                if(temp == INF)  
                    return false;  
                for(int j = 1; j <= n; ++j)  
                    if(visitx[j])  
                        lx[j] -= temp;  
                for(int j = 1; j <= m; ++j)  
                    if(visity[j])  
                        ly[j] += temp;  
                    else  
                        slack[j] -= temp;  
            }  
        }  
    }  
    return true;  
} 

int main()
{ 
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &m))
    {
        int ans = 0, res = 0;
        CLR(weight);
        MST(match,-1);
        int x;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d", &x);
                weight[i][j] = (100)*x;
            }
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &x);
            res += weight[i][x];  
            weight[i][x]++;
        }
        KM_Perfect_Match();  
        for(int i = 1; i <= m; ++i)  
        {  
            if(match[i] != -1)  
                ans += weight[ match[i] ][i];  
        }  
        printf("%d %d\n", n - ans % 100, ans / 100 - res / 100);  

    }
    //system("pause");
    //printf("%lld\n", (x+mod)%mod );
}

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
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define pb push_back
using namespace std;

#define MaxN 100005
#define MaxM 1005
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

inline void out(LL x) {
   if(x>9) out(x/10);
   putchar(x%10+'0');
}


void read(int &o) {
    o = 0;
    char c = getchar();
    while (!isdigit(c))
        c = getchar();
    while (isdigit(c)) {
        o = o * 10 + c - '0';
        c = getchar();
    }
}

int n,m,a[MaxN],b[MaxN],p[MaxM],k[MaxM];

LL DP[11][1001];
int kind[11][1001];
void CompletePack(int i, int cost, int weight) 
{
    DP[i][0] = 0;
    for(int v=1;v<=cost;v++)
        DP[i][v] = min(DP[i][v], 1LL*weight);
    for(int v=cost;v<=1000;v++)           
        DP[i][v] = min(DP[i][v], DP[i][v-cost]+1LL*weight);
}

void solve()
{
    MST(DP,INF);
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<=10;j++)
        {
            if(p[i]<=j) break;
            CompletePack(j, p[i]-j, k[i]);
        }
    }
    LL ans = 0;
    for(int i=0;i<=10;i++)
    {
        for(int j=1;j<=1000;j++)
        {
            if(kind[i][j]>0) 
            {
                ans += 1LL*kind[i][j]*DP[i][j];
            }
        }
    }
    out(ans);puts("");
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        CLR(kind);
        int best_defender = -1, best_attack = -1;
        for(int i=1;i<=n;i++) 
        {
            read(a[i]);read(b[i]);
            kind[b[i]][a[i]]++;
            best_defender = max(best_defender, b[i]);
        }
        for(int i=1;i<=m;i++) 
        {
            read(k[i]);read(p[i]);
            best_attack = max(best_attack, p[i]);
        }
        if(best_attack<=best_defender) puts("-1");
        else solve();
    }
}

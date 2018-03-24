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
#define ps push_back
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
inline int max2(int a, int b) {return ((a > b)? a : b);}
inline int min2(int a, int b) {return ((a < b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}
inline int min3(int a, int b, int c) {return min2(a, min2(b, c));}

int n,m;
priority_queue<LL> Q1,Q2,Q3;
LL DP[5][MaxN];

void solve()
{
    //全部用1
    for(int i=1;i<=m;i++)
    {
        DP[1][i] = DP[1][i-1] + Q1.top();
        Q1.pop();
    }

    //尝试用2替换
    for(int i=2;i<=m;i++)
    {
        if( DP[2][i] < DP[1][i-2] + Q2.top() )
        {
            DP[2][i] = DP[1][i-2] + Q2.top();
            Q2.pop();
        }
        else DP[2][i] = DP[2][i-1]+DP[1][i]-DP[1][i-1];
    }

    //尝试3

}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &m))
    {
        
        while(!Q1.empty()) Q1.pop();
        while(!Q2.empty()) Q2.pop();
        while(!Q3.empty()) Q3.pop();
        LL w,v;
        for(int i=1;i<=n;i++) 
        {
            scanf("%lld%lld", &w, &v);
            if(w==1) Q1.push(v);
            else if(w==2) Q2.push(v);
            else Q3.push(v);
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

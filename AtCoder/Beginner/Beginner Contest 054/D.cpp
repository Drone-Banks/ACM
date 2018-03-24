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
using namespace std;

#define MaxN 42
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
int N,Ma,Mb;
int A[MaxN],B[MaxN],C[MaxN];
int DP[MaxM][MaxM];
void solve()
{
    MST(DP,INF);
    DP[0][0] = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=400;j>=1;j--)
        {
            for(int k=400;k>=1;k--)
            {
                if(j>=A[i] && k>=B[i])
                {
                    DP[j][k] = min(DP[j-A[i]][k-B[i]]+C[i], DP[j][k]);
                }
                else break;
            }
        }
    }
    int ans = INF;
    for(int j=1;j<=400;j++)
    {
        for(int k=1;k<=400;k++)
        {
            if(j*Mb == k*Ma)
            {
                //cout << j << " " << k  << " " << DP[j][k] << endl;
                ans = min(ans, DP[j][k]);
            }
        }
    }
    if(ans==INF) ans = -1;
    printf("%d\n", ans);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d%d%d", &N, &Ma, &Mb);
    for(int i=0;i<N;i++)
    {
        scanf("%d%d%d", &A[i], &B[i], &C[i]);
    }
    solve();
    system("pause");
}

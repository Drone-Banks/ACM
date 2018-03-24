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

#define MaxN 100001
#define MaxM 20
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;

int N,M,X;
double P;
double dp[2][(1<<MaxM)+1];

void solve(int t)
{
    int n = 1<<M;
    double *prv = dp[0], *nxt = dp[1];
    memset(prv, 0, sizeof(double)*(n+1));
    prv[n] = 1.0;
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<=n;j++)
        {
            int gap = min(j, n-j);
            double cnt = 0.0;
            for(int k=0;k<=gap;k++)
            {
                cnt = max(cnt, (1-P)*prv[j-k]+(P)*prv[j+k]);
            }
            nxt[j] = cnt;
        }
        swap(prv,nxt);
    }
    int index = (LL)X*n/1000000;
    printf("Case #%d: %.6lf\n", t, prv[index]);
}

int main()
{
    //std::ios::sync_with_stdio(false);
    freopen("C-large-practice.in","r",stdin);
	freopen("C.out","w",stdout);
	/********************************************/
    scanf("%d", &N);
    for(int i=1;i<=N;i++)
    {
        scanf("%d%lf%d", &M, &P, &X);
        solve(i);
    }
    /********************************************/
    fclose(stdin);
    fclose(stdout);
    //system("pause");
}

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
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
int N,A,B;
LL V[MaxN];
LL dp[51][51];
void init()
{
    for(int i=0;i<=50;i++)
        for(int j=0;j<=i;j++)
         {
            if(!j || i==j)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                 //cout << i << "  " << j << ":  " << dp[i][j] << endl;
         }
    return;
}

void solve()
{
    sort(V+1,V+1+N);
    reverse(V+1,V+1+N);
    LL sum = 0;
    LL num = 1;
    LL pro = 0;
    for(int i=A; i<=B; i++)
    {
		LL tot = 0;
		LL AA = 0, BB = 0;
		for(int j=1; j<=N; j++) if(V[j] == V[i])AA++;
		for(int j=1; j<=i; j++)
        {
			tot += V[j];
			if(V[j] == V[i])BB++;
		}
		LL qq = dp[AA][BB];
		if(tot * num > sum * i)
        {
			sum = tot;
			num = i;
			pro = qq;
		}
        else if(tot * num == sum * i)
        {
			pro += qq;
		}
	}
    double ans = sum*1.0/num*1.0;
    //debug(ans);
    printf("%.6lf\n%lld\n", ans , pro);
}
int main()
{
    init();
    //std::ios::sync_with_stdio(false);
    scanf("%d", &N);
    scanf("%d%d", &A, &B);
    for(int i=1;i<=N;i++) scanf("%lld", V+i);
    solve();
    system("pause");
}

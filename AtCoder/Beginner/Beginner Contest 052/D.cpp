#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

int N;
LL A,B,X[100005];
LL DP[100005];

void solve()
{
    LL ans = 0;
    for(int i=2;i<=N;i++)
    {
        LL cnt = X[i] - X[i-1];
        //printf("%lld\n", cnt);
        ans += min(cnt*A,B);
    }
    printf("%lld\n",ans);
}
int main()
{
    scanf("%d%lld%lld", &N, &A, &B);
    for(int i=1;i<=N;i++) scanf("%lld", &X[i]);
    solve();
    system("pause");
}
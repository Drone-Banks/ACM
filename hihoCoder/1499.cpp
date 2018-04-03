#include <bits/stdc++.h>

using namespace std;

int N;
long long ans, Coins[100005][2];

int main()
{
    while(~scanf("%d", &N))
    {
        long long sum = 0;
        for(int i=1;i<=N;i++) {
            scanf("%d%d", &Coins[i][0], &Coins[i][1]);
            sum += Coins[i][0];
            sum += Coins[i][1];
        }
        long long avg = sum/2/N;

        ans = 0;
        Coins[0][0] = Coins[0][1] = 0;
        for(int i=1;i<=N;i++)
        {
            ans += abs(Coins[0][0]);
            ans += abs(Coins[0][1]);

            Coins[0][0] += Coins[i][0]-avg;
            Coins[0][1] += Coins[i][1]-avg;

            if( Coins[0][0]>0 && Coins[0][1]<0) {
                long long tmp = min(Coins[0][0], abs(Coins[0][1]));
                Coins[0][0] -= tmp, Coins[0][1] += tmp, ans += tmp;
            }
            if( Coins[0][1]>0 && Coins[0][0]<0) {
                long long tmp = min(Coins[0][1], abs(Coins[0][0]));
                Coins[0][1] -= tmp, Coins[0][0] += tmp, ans += tmp;
            }
        }
        printf("%lld\n", ans);
    }
}
#include<bits/stdc++.h>

using namespace std;

long long N, Q;
vector<long long> base;

void init()
{
    long long num = 2LL;
    while(num<=1E12)
    {
        base.push_back(num);
        num*=2LL;
    }
}

int main()
{
    init();
    while(~scanf("%lld%lld", &N, &Q))
    {
        if( N/Q <= 2){printf("%lld\n", N);continue;}
        int index = lower_bound(base.begin(), base.end(), N/Q)-base.begin();
        long long ans = 1LL*index*Q + ceil(1.0*N/base[index-1]);
        printf("%lld\n", ans);
    }
}
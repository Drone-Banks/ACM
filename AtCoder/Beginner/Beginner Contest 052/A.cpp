#include <bits/stdc++.h>
typedef long long LL;
LL A,B,C,D;
int main()
{
    scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
    LL ans = A*B > C*D ? A*B : C*D;
    printf("%lld\n", ans );
}
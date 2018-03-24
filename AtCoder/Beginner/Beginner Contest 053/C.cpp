#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    LL x;
    scanf("%lld", &x);
    if(x<7) puts("1");
    else
    {
         LL rem = x-6;
         LL ans = rem/11*2;
         int s = rem%11;
         if(s>5) ans+=2;
         else if(s>0) ans+=1;
         printf("%lld\n", ans+1);
     }
}
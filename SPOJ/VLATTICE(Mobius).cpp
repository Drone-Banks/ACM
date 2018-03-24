/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
#define MaxN 1000005
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}

int mu[MaxN],prime[MaxN];
bool not_prime[MaxN];
void Mobius()
{
    int tot = 0;
    mu[1] = 1;
    for(int i=2;i<=MaxN;i++)
    {
        if(!not_prime[i])
        {
            prime[++tot] = i;
            mu[i] = -1;
        }
        for(int j=1;prime[j]*i<=MaxN;j++)
        {
            not_prime[prime[j]*i] = 1;
            if(i%prime[j]==0)
            {
                mu[prime[j]*i] = 0;
                break;
            }
            mu[prime[j]*i] = -mu[i];
        }
    }
}
int main()
{
    Mobius();
    int t,n;
    read(t);
    while(t--)
    {
        read(n);
        LL ans = 3;
        for(int i=1;i<=n;i++)
        {
            ans += 1LL * mu[i] * (n/i) * (n/i) * (n/i + 3);
        }
        out(ans);puts("");
    }
}

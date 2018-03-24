#include <bits/stdc++.h>
#define zyy 20101009
#define MaxN 10000005
const long long mod = 20101009;
#define ll long long
using namespace std;
ll mu[MaxN],prime[MaxN];
bool not_prime[MaxN];
ll sum[MaxN];
ll ans, x, y;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void write(ll a){
	if(a>9)write(a/10);
	putchar(a%10+'0');
}
void Mobius()
{
    int tot = 0;
    mu[1] = 1;
    for(int i=2;i<=min(x, y);i++)
    {
        if(!not_prime[i])
        {
            prime[++tot] = i;
            mu[i] = -1;
        }
        for(int j=1;prime[j]*i<=min(x, y);j++)
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
    for(int i=1;i<=min(x, y);i++) 
    {
        sum[i] = (sum[i-1] + mu[i]*i*i%mod )%mod;
    }
}
ll cal(ll a, ll b)
{
    return (a*(a+1)/2)%mod * (b*(b+1)/2%mod)%mod;
}
ll f(ll n, ll m)
{   
    if(n>m) swap(n,m);  
    ll ans = 0;
    for(ll i=1,last=1;i<=n;i=last+1)
    {
        last = min( n/(n/i), m/(m/i));
        ans = (ans + (sum[last] - sum[i-1]) * cal(n/i, m/i)%mod )%mod  ;
    } 
    return ans;
}
int main(){
    cin >> x >> y;
    Mobius();
	for(ll i = 1, last; i <= min(x, y); i = last+1){
		last = min(x/(x/i), y/(y/i));
		ans = (ans+(i+last)*(last-i+1)/2%zyy*f(x/i, y/i)%zyy)%zyy;
		// printf("ans2 = %d\n", ans);
	}
	cout<<(ans+zyy)%zyy<<endl;
}
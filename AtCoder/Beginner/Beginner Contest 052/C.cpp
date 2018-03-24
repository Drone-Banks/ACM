#include<bits/stdc++.h>
#define MAXN 1001
const int mod = 1000000007;
typedef long long LL;
using namespace std;
int N;
int DIV[1001];
int primes[MAXN],tot=0;
bool isPrime[MAXN];

void getPrime()
{
    memset(isPrime,true,sizeof(isPrime));
    for(int i=2;i<MAXN;i++)
    {
        if(isPrime[i])
            primes[++tot]=i;
        for(int j=1;j<=tot;j++)
        {
            if(i*primes[j]>=MAXN) break;
            isPrime[i*primes[j]]=false;
            if(i%primes[j]==0) break;
        }
    }
}
int main()
{
    getPrime();
    scanf("%d", &N);
    LL ans = 1;
    for(int i=2;i<=N;i++)
    {
        for(int t=1;primes[t]<=i&&t<=tot;t++)
        {
            int x = i;
            while(x%primes[t]==0&&x) DIV[primes[t]] ++, x/=primes[t];
        }
    }
    for(int i=2;i<=N;i++) 
    {
        //cout <<i << " " << DIV[i] << endl;
        if(DIV[i]) ans*=(DIV[i]+1);
        if(ans>mod) ans = ans%(mod);
    }
    printf("%lld\n", ans);
    system("pause");

}
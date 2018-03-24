#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

const long long N=50001;
long long prime[N]={0};
long long num_prime=0;
long long isNotPrime[N]={1,1};
long long PowerMod(long long a, long long b) 
{
	long long ans = 1;
	while(b>0)
    {
		if(b % 2 == 1)
			ans = (ans * a);
		b = b/2;
		a = (a * a);
	}
	return ans;
}
int T;
long long n,p;

int main()
{
    for(long long i=2;i<N;i++)
    {
        if(!isNotPrime[i])
            prime[num_prime++]=i;
        for(long long j=0;j<num_prime && i*prime[j]<N;j++)
        {
            isNotPrime[i*prime[j]]=1;
            if(!(i%prime[j])) break;
        }
    }
    
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld %lld",&n,&p);
        bool flag=false;
        for(long long i=0;i<num_prime;i++)
        {
            if(n%prime[i]==0)
            {
                if(PowerMod(prime[i], p-1)==n)
                    printf("YES\n");
                else
                    printf("NO\n");
                flag=true;
                break;
            }
        }
        if(!flag)
        {
            if(p!=3)
            {
                printf("NO\n");
                continue;
            }
            long long tmp=sqrt(n);
            if(tmp*tmp==n)
            {
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }
    //system("pause");
}

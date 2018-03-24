//poj 2460 
//sepNINE
#include <iostream>
#include <cstdio>
using namespace std;
const int maxN=200024;
int x[maxN],y[maxN];

int main()
{
	int n;
	while(scanf("%d",&n)==1&&n){
		int i,sum1=0,sum2=0,t=n/2+1;
		for(i=1;i<=zn;++i)
			scanf("%d%d",&x[i],&y[i]);	
		for(i=1;i<=n;++i)
			if((x[i]>x[t]&&y[i]>y[t])||(x[i]<x[t]&&y[i]<y[t]))
				++sum1;
			else if((x[i]>x[t]&&y[i]<y[t])||(x[i]<x[t]&&y[i]>y[t]))
				++sum2;
		printf("%d %d\n",sum1,sum2);
	}
	return 0;	
} 
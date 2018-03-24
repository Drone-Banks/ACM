#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#define lson d*2,l,mid
#define rson d*2+1,mid+1,r
#define ll long long
#define Maxn 1010
using namespace std;

int main()
{
freopen("alex.in", "r", stdin);
    freopen("alex.out", "w", stdout);
	int a,b;
	while(~scanf("%d%d",&a,&b))
	{
		if(a>b) swap(a,b); 
		if(a*3>=b*2)
		{
			printf("%.6f\n",a/2.0);
		}
		else 
		{
			double ans=min(a*1.0,b/3.0);
			printf("%.6f\n",ans);
		}
	}
}
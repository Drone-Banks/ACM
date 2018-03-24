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

void out(char a,char b,int n) //b是多的 
{
	for(int i=0;i<3;i++) printf("%c",a);
	puts("");
	while(n--)
	{
		printf("%c%c%c\n",a,b,a);
		printf("%c%c%c\n",a,a,a);
	 } 
}
int main()
{
freopen("black.in", "r", stdin);
    freopen("black.out", "w", stdout);
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		char b='@',w='.';
		if(n>m) 
		{
			char tem=b;
			b=w;
			w=tem;
			swap(n,m);
		}
		int cha=m-n;
		if(cha) printf("%d 3\n",cha+n+m);
		else printf("%d 3\n",2*n);
		out(b,w,cha); //w是多的 
		n--;
		for(int i=0;i<3;i++) printf("%c",w);
		puts("");
		while(n--)
		{
			printf("%c%c%c\n",b,b,b);
			printf("%c%c%c\n",w,w,w);
		}
	}
}
close
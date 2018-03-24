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

int mp[110][110];
int main()
{
        freopen("lucky.in", "r", stdin);
        freopen("lucky.out","w", stdout);
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int mx=-1;
			for(int j=1;j<=m;j++)
			{
				if(mp[i][j]>mx)
				{
					mx=mp[i][j];
					ans++;
				}
			}
			mx=-1;
			for(int j=m;j>=1;j--)
			{
				if(mp[i][j]>mx)
				{
					mx=mp[i][j];
					ans++;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			int mx=-1;
			for(int j=1;j<=n;j++)
			{
				if(mp[j][i]>mx)
				{
					mx=mp[j][i];
					ans++;
				}
			}
			mx=-1;
			for(int j=n;j>=1;j--)
			{
				if(mp[j][i]>mx)
				{
					mx=mp[j][i];
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
}
close
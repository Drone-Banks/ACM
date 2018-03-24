#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int sum[3005], ufs[3005];
int Find(int x)
{
	if(ufs[x]==0)
		return x;
	return ufs[x] = Find(ufs[x]);
}
int main(void)
{
	int n, m, i, x, y, z, cnt, t1, t2;
	while(scanf("%d%d", &n, &m)!=EOF)
	{
		cnt = n-1;
		memset(ufs, 0, sizeof(ufs));
		memset(sum, 0, sizeof(sum));
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d", &x, &y, &z);
			if(x==y)
				continue;
			sum[x] += z;
			sum[y] += z;
			t1 = Find(x);
			t2 = Find(y);
			if(t1!=t2)
			{
				ufs[t1] = t2;
				cnt--;
			}
		}
		if(cnt==0)
		{
			sort(sum+1, sum+n+1);
			printf("%d\n", sum[1]);
		}
		else
			printf("0\n");
	}
	return 0;
}
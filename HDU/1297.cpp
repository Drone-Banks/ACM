#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1010;
long dp[maxn][maxn];

void cal ()
{
    dp[1][0] = 1;
    dp[2][0] = 2;
    dp[3][0] = 4;
    dp[4][0] = 7;
    for(int i = 5; i <= 1000; i++)
	{
		int temp = 0;
		for(int j = 0; j < 1000; j++)
		{
			temp = dp[i-1][j] + dp[i-2][j] + dp[i-4][j] + temp;
			dp[i][j] = temp % 10;
			temp = temp / 10;
		}
	}
}


int main()
{
    int n;
    memset(dp, 0, sizeof(dp));
    cal();
    while(cin>>n)
    {
        int q = 999;
		while(dp[n][q] == 0)
			q--;
		while(q >= 0)
		{
			printf("%d", dp[n][q]);
			q--;
		}
		printf("\n");
    }
    return 0;
}

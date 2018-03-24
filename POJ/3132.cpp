#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define N 1125

using namespace std;

bool pri[N];

int prime[233];

int number;

int dp[N][15];

void init()
{
    memset(pri, true, sizeof(pri));
	pri[0] = pri[1] = false;
	for (int i = 2; i < sqrt((float)N); i++)
	{
		for (int j = i + i; j < N; j += i)
		{
			pri[j] = false;
		}
	}
	number = 1;
	for (int i = 0; i < N; i++)
	{
		if (pri[i])
		{
			prime[number] = i;
			number++;
		}
	}
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
	for (int k = 1; k < number; k++)
	{
		for (int i = 1120; i >= 0; i--)
		{
			for (int j = 1; j <= 14; j++)
			{

				if (i - prime[k] >= 0)
				{
                    dp[i][j] += dp[i - prime[k]][j - 1];
				}
				printf("%d %d %d \n", i, j, dp[i][j]);
			}
		}
	}

}


int main()
{
    init();
    int n,k;
    while(cin >> n >> k)
    {
        if(n == 0 && k == 0) break;
        printf("%d\n", dp[n][k]);
    }
    return 0;
}

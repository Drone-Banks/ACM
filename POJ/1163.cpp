#include <iostream>
#include <algorithm>


using namespace std;

int a[110][110];
int dp[110][110];

int main()
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin >> a[i][j];
        }
    }

    for(int i=N;i>0;i--)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j] = max(dp[i+1][j]+a[i][j], dp[i+1][j+1]+a[i][j]);
            //cout << dp[i][j] << endl;
        }
    }

    cout << dp[1][1] << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <cstring>

using namespace std;
const int maxn = 1010;
int dp[maxn][maxn];

int main()
{
    string X,Z;
    while( cin>>X && cin>>Z )
    {
        memset(dp, 0, sizeof(dp));
        int n = X.length();
        int m = Z.length();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(X[i-1] == Z[j-1])  dp[i][j] = dp[i-1][j-1] + 1;
                else                  dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}

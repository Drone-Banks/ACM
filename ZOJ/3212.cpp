#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct tree
{
    int a,b;
    bool operator <(const tree &a) const
    {
        return b < a.b;
    }
};

tree ss [300];
int dp[300][300];

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        memset(dp, 0, sizeof(dp));
        int n,m;
        cin >> n >> m;
        for(int i = 1;i <= n;i++)
            cin >> ss[i].a;
        for(int i = 1;i <= n;i++)
            cin >> ss[i].b;
        sort(ss+1,ss+n+1);
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-1] + ss[i].a + ss[i].b*(j-1));
            }
        }
        cout << dp[n][m] << "\n";

    }
    return 0;
}

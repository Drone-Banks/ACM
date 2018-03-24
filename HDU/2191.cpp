#include <iostream>
#include <cstring>
using namespace std;

struct rice
{
    int p,h,c;

};

rice q[110];
int dp[110][110];
int main()
{
    int C;
    cin >> C;
    while(C--)
    {
        memset(dp, 0, sizeof(dp));
        int m,n;
        cin >> n >> m;
        for(int i=1;i<=m;i++)
            cin >> q[i].p >> q[i].h >> q[i].c;


        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                for(int k=0;k<=q[i].c;k++)
                {
                    if( j>=k*q[i].p)
                    {
                        int cur = dp[i-1][j-k*q[i].p]+k*q[i].h;
                        dp[i][j] = dp[i][j]>cur ? dp[i][j] : cur;

                    }
                    else
                        break;
                }
            }
        }
        cout << dp[m][n] << endl;
    }
    return 0;
}

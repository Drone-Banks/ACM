#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int c[1111];
int p[1111];
int dp[1111];

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        memset(c, 0, sizeof(c));
        memset(p, 0, sizeof(p));
        memset(dp, 0, sizeof(dp));

        int N,V;
        cin >> N >> V;
        for(int i=1;i<=N;i++)
            cin >> p[i];
        for(int i=1;i<=N;i++)
            cin >> c[i];

        for(int i=1;i<=N;i++)
        {
            for(int j=V;j>=0;j--)
            {
                if(j>=c[i]) dp[j] = max(dp[j], dp[j-c[i]]+p[i]);
            }
        }
        cout << dp[V] << endl;
    }
    return 0;
}

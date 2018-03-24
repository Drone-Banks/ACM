#include <bits/stdc++.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define LL long long
#define rep1(i,a,b) for (int i = a;i <= b;i++)
#define rep2(i,a,b) for (int i = a;i >= b;i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ms(x,y) memset(x,y,sizeof x)
#define Open() freopen("F:\\rush.txt","r",stdin)
#define debug(x) cout << #x" = " << x << endl;
#define Close() ios::sync_with_stdio(0),cin.tie(0)

typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

const int dx[9] = {0,1,-1,0,0,-1,-1,1,1};
const int dy[9] = {0,0,0,-1,1,-1,1,-1,1};
const double pi = acos(-1.0);
const int N = 1e6;
const int MOD = 1e9+7;

int dp[N+100][21],lp[N+10];

void pre()
{
    lp[1] = 1;
    rep1(i,2,N)
        if (lp[i]==0)
            for (int j = i;j<=N;j+=i)
                lp[j] = i;

    rep1(i,1,20)
        dp[0][i] = 2;
    rep1(i,0,N)
        dp[i][0] = 1;
    rep1(i,1,N)
        rep1(j,1,20)
            dp[i][j] = (dp[i][j-1] + dp[i-1][j])%MOD;
}

int main()
{
    //Open();
    pre();
    for(int i=1;i<=N;i++)
    {
        //debug(i) debug(lp[i])
    }
    int q;
    scanf("%d",&q);
    while (q--)
    {
        int r,n;
        scanf("%d%d",&r,&n);
        LL ans = 1;
        while (n>1)
        {
            int cnt = 0,x = lp[n];
            while (n%x==0)
            {
                cnt++;
                n/=x;
            }
            ans = (ans*dp[r][cnt])%MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define LL long long
#define rep1(i,a,b) for (int i = a;i <= b;i++)
#define rep2(i,a,b) for (int i = a;i >= b;i--)
#define mp make_pair
#define ps push_back
#define fi first
#define se second
#define rei(x) cin >> x
#define pri(x) cout << x
#define ms(x,y) memset(x,y,sizeof x)

typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

const int dx[9] = {0,1,-1,0,0,-1,-1,1,1};
const int dy[9] = {0,0,0,-1,1,-1,1,-1,1};
const double pi = acos(-1.0);
const int N = 110;
const int M = (1<<20)+20;
const int MOD = 1e9+7;

int n,num[N][N],f[N][M],ans;
char s[N];

void add(int &a,int &b)
{
    a = a+b;
    if (a>=MOD) a-=MOD;
}

int main()
{
    //freopen("F:\\rush.txt","r",stdin);
    ios::sync_with_stdio(false);
    rei(n);
    rei((s+1));
    rep1(i,1,n)
    {
        for (int j = i,k = 0;j <= n;j++)
            if ((k=(k<<1)+s[j]-'0')>20)
                break;
            else
                num[i][j] = k;
    }
    rep1(i,1,n)
    {
        f[i][0]++;
        rep1(j,0,(1<<20)-1)
            if (f[i][j])
                rep1(k,i,n)
                    if (num[i][k])
                        add(f[k+1][j|1<<(num[i][k]-1)],f[i][j]);
    }
    rep1(i,2,n+1)
        rep1(j,1,20)
            add(ans,f[i][(1<<j)-1]);
    pri(ans<<endl);
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
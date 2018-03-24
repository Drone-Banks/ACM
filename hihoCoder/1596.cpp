/*************************************************************************
> File Name: test.cpp
> Author: Akira 
> Mail: qaq.febr2.qaq@gmail.com 
************************************************************************/

//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define pb push_back
using namespace std;                                                                                              

#define MaxN 100005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}

int n,b[61];
map<int,int> M;
int f[61][61][61][61][2];
 
void solve()
{
    sort(b+1, b+1+n);
    f[1][1][1][1][0] = 1;
    for(int i = 2;i<=n;i++)
    {
        if(b[i]==b[1])
        {
            memcpy(f[i], f[i-1], sizeof(f[0]));
            continue;
        }
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                for(int l=1;l<=n;l++)
                {
                    for(int r=0;r<2;r++)
                    {
                        if(!f[i-1][j][k][l][r]) continue;
                        int la,lb,rb,ra,x=f[i-1][j][k][l][r];
                        if(!r)
                            la = i-1, lb = j, rb = k, ra = l;
                        else
                            la = j, lb = k, rb = l, ra = i-1;
                        if(b[la]-b[i] <= b[lb]-b[la])
                            (f[i][la][rb][ra][0]+=x)%=mod;
                        if(b[ra]-b[rb]<= b[i]-b[ra])
                            (f[i][la][lb][ra][1]+=x)%=mod;
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int j=1;j<=n;j++)
        for(int k=1;k<=n;k++)
            for(int l=1;l<=n;l++)
                for(int r=0;r<2;r++)
                    (ans+=f[n][j][k][l][r])%=mod;
    int num = M[b[1]];
    for(int i=1;i<=num;i++)
        ans =  (LL)ans*i%mod;                 
    ans = (ans%mod+mod)%mod;
    out(ans);puts("");
}

int main()
{
    while(~scanf("%d", &n))
    {
        M.clear();CLR(f);
        for(int i=1;i<=n;i++) scanf("%d", &b[i]), M[b[i]]++;
        solve();
    }
}

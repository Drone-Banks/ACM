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

#define MaxN 200005
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

int n;
int a[MaxN];
vector<int> loc[MaxN],loss;
int num[MaxN];
bool vis[MaxN];
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &n))
    {
        for(int i=1;i<=n;i++) loc[i].clear();
        CLR(num);CLR(vis);
        loss.clear();
        for(int i=1;i<=n;i++) 
        {
            scanf("%d", &a[i]);
            
            loc[a[i]].pb(i);

        }
        for(int i=1;i<=n;i++)
        {
            if(loc[i].size()==0) loss.pb(i);
            else num[i] = loc[i].size();
        }
        int cnt = 0;
        for(int i=1;i<=n;i++)
        {
            if(num[a[i]]==1) continue;
            else if(vis[a[i]])
            {
                num[a[i]]--;
                a[i] = loss[cnt];
                cnt++;
            }
            else
            {
                if(a[i]>loss[cnt]) 
                {
                    num[a[i]]--;
                    a[i] = loss[cnt];
                    cnt++;
                }
                else vis[a[i]] = 1;
            }
        }
        printf("%d\n", loss.size());
        for(int i=1;i<=n;i++)
        printf("%d%c",a[i]," \n"[i==n]);
    }
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

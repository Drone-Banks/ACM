/*************************************************************************
> File Name: test.cpp
> Author: Akira 
> Mail: qaq.febr2.qaq@gmail.com 
************************************************************************/

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
inline int max2(int a, int b) {return ((a > b)? a : b);}
inline int min2(int a, int b) {return ((a < b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}
inline int min3(int a, int b, int c) {return min2(a, min2(b, c));}
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}

int n,a[1001],dis[1001];
bool vis[1001];
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &n))
    {
        for(int i=1;i<=n;i++) scanf("%d", a+i);
        for(int i=1;i<n;i++) dis[i] = a[i+1]-a[i];
        if(n<=3)
        {
            bool flag = true;
            for(int i=2;i<n;i++)
            {
                if(dis[i]!=dis[i-1]) flag = false;
            }
            if(flag) puts("No");
            else puts("Yes");
            continue;
        }
        //__1
        int dis1 = a[2]-a[1], loc=-1;
        CLR(vis);
        for(int i=1;i<=n;i++)
        {
            if( a[i] == a[1] + (i-1)*dis1 ) 
            {
                vis[i] = true;
            }
            else  
            {
                if(loc==-1) loc = i;
            }
        }
        if(loc==-1) 
        {
            puts("No");
            continue;
        }
        vis[loc] = true;
        int pre = INF, len;
        for(int i=loc+1;i<=n;i++)
        {
            if(vis[i]) continue;
            if(pre==INF) 
            {
                vis[i] = true;
                pre = a[i]-a[loc];
                len = i-loc;
            }
            else
            {
                int len1 = i-loc, pre1 = a[i] - a[loc];
                if(1LL*len1*pre == 1LL*len*pre1)
                {
                    vis[i] = true;
                }
            }
        }
        bool flag = true;
        for(int i=1;i<=n;i++) if(!vis[i]) {flag = false; break;}
        if(flag && (pre==INF || (dis1*len == pre) ) )
        {
            puts("Yes");
            continue;
        }
        
        //_2        
        dis1 = a[3] - a[1], loc=2;
        CLR(vis);
        vis[1] = true;
        for(int i=3;i<=n;i++)
        {
            if( (a[i]-a[1])*2 == (i-1)*dis1 ) 
            {
                vis[i] = true;
            }
        }
        vis[loc] = true;
        pre = INF, len;
        for(int i=loc+1;i<=n;i++)
        {
            if(vis[i]) continue;
            if(pre==INF) 
            {
                vis[i] = true;
                pre = a[i]-a[loc];
                len = i-loc;
            }
            else
            {
                int len1 = i-loc, pre1 = a[i] - a[loc];
                if(1LL*len1*pre == 1LL*len*pre1)
                {
                    vis[i] = true;
                }
            }
        }
        flag = true;
        for(int i=1;i<=n;i++) if(!vis[i]){flag = false;break;}
        if(flag && (pre==INF || (dis1*len == pre*2) ) ) 
        {
            puts("Yes");
            continue;
        }
        
        //_3
        dis1 = a[3]-a[2], loc=1;
        CLR(vis);
        vis[2] = true;
        for(int i=3;i<=n;i++)
        {
            if( a[i] == a[2] + (i-2)*dis1 ) 
            {
                vis[i] = true;
            }
        }
        vis[loc] = true;
        pre = INF, len;
        for(int i=loc+1;i<=n;i++)
        {
            if(vis[i]) continue;
            if(pre==INF) 
            {
                vis[i] = true;
                pre = a[i]-a[loc];
                len = i-loc;
            }
            else
            {
                int len1 = i-loc, pre1 = a[i] - a[loc];
                if(1LL*len1*pre == 1LL*len*pre1)
                {
                    vis[i] = true;
                }
            }
        }
        flag = true;
        for(int i=1;i<=n;i++) if(!vis[i]) {flag = false; break;}
        if(flag && (pre==INF || (dis1*len == pre) ) )
        {
            puts("Yes");
            continue;
        }
        
        puts("No");
    }
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}
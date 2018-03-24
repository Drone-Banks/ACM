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

int n,m,q;
string str[MaxN];
map<string,int> M;

int f[MaxN*2];
int finds(int x)
{
    return f[x]==x?x:f[x]=finds(f[x]);
}
void uni(int a, int b)
{
    a=finds(a);
    b=finds(b);
    if (a==b) return;
    f[a] = b;
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin >> n >> m >> q)
    {
        M.clear();
        for(int i=1;i<=n;i++) cin >> str[i], M[str[i]] = i, f[i*2] = (i<<1), f[i*2+1]=((i<<1)|1);
        int type;
        string a,b;
        for(int i=1;i<=m;i++)
        {
            cin >> type >> a >> b;
            int ida = M[a], idb = M[b];
            ida<<=1, idb<<=1;
            if(type==1) 
            {
                int loca = finds(ida), locb = finds(idb);
                // cout << loca << " " << (locb^1) << endl;
                if(loca != (locb^1) )
                {
                    uni(loca, locb);
                    uni(loca^1, locb^1);
                    cout << "YES" << endl;
                } 
                else cout << "NO" << endl;
            } 
            else
            {
                int loca = finds(ida), locb = finds(idb);
                if(loca != locb)
                {
                    uni(loca, locb^1);
                    uni(loca^1, locb);
                    cout << "YES" << endl;
                }
                else cout << "NO" << endl;
            }
            // for(int i=1;i<=n;i++) cout << finds(M[str[i]]*2) << endl;
        }
        // for(int i=1;i<=n;i++) cout << finds(M[str[i]]*2) << endl;
        for(int i=1;i<=q;i++)
        {
            cin >> a >> b;
            int ida = M[a], idb = M[b];
            ida<<=1, idb<<=1;
            int loca = finds(ida), locb = finds(idb);
            // cout << loca << " " << locb << endl;
            if(loca == locb) cout << 1 << endl;
            else if(loca == (locb^1)) cout << 2 << endl;
            else cout << 3 << endl;
        }
    }
}
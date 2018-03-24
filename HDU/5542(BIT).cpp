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

#define MaxN 1002
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

int T,N,M,a[MaxN];
vector<int> V;
struct BIT
{
    int arr[MaxN][MaxN],n,m;
    void init(int n, int m)
    {
        this->n = n;
        this->m = m;
        CLR(arr);
    }
    int lowbit(int x )  
    {  
        return x & (-x);  
    }  
    void update(int x ,int y ,int num)  
    {  
        for (int i = x ;i <= n ;i += lowbit(i))   
        {
            arr[i][y] += num ;  
            if(arr[i][y]>mod) arr[i][y]%=mod;
        }
    }  
    int sum(int x ,int y )  
    {  
        LL ans = 0 ;  
        for (int i = x ;i > 0 ;i -= lowbit(i))  
        {
             ans += arr[i][y] ;  
             if(ans>mod) ans%=mod;
        }
        return ans%mod ;  
    }  
}bit;
void solve(int t)
{
    V.clear();
    for(int i=1;i<=N;i++) V.pb(a[i]);
    sort(V.begin(), V.end());
    for(int i=1;i<=N;i++) a[i]=lower_bound(V.begin(),V.end(),a[i])-V.begin()+1;
    bit.init(N,N);
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(j==1) bit.update(a[i], j, 1);
            else
            {
                int tmp = bit.sum(a[i]-1, j-1);
                bit.update(a[i],j,tmp);
            }
        }
    }
    int ans = bit.sum(N,M)%mod;
    printf("Case #%d: ", t);out(ans);puts("");
}
int main()
{
    //std::ios::sync_with_stdio(false);
    read(T);
    for(int t=1;t<=T;t++)
    {
        read(N), read(M);
        for(int i=1;i<=N;i++) read(a[i]);
        solve(t);
    }
    //system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

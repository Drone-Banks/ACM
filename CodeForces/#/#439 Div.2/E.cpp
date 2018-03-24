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
#define pb emplace_back
using namespace std;                                                                                              

#define MaxN 2505
#define MaxM MaxN
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}

struct BIT
{
    LL arr[MaxM][MaxM],n,m;
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
    void add(int x ,int y ,LL num)  
    {  
        for (int i = x ;i <= n ;i += lowbit(i))  
            for (int j = y ; j <= m ;j += lowbit(j) )  
                arr[i][j] ^= num ;  
    }  
    void update(int r1, int c1, int r2, int c2, LL val)
    {
        add(r1,c1,val);   add(r1,c2+1,val);
        add(r2+1,c1,val); add(r2+1,c2+1,val);
    }
    LL query(int x ,int y )  
    {  
        LL ans = 0 ;  
        for (int i = x ;i > 0 ;i -= lowbit(i))  
            for (int j = y ;j > 0 ; j -= lowbit(j))  
                ans ^= arr[i][j] ;  
        return ans ;  
    }
}bit;


int seed = 23333;
inline LL Hash(int x1, int y1, int x2, int y2) {
    LL val = x1;
    val = (val*seed + y1)%mod;
    val = (val*seed + x2)%mod;
    val = (val*seed + y2)%mod;
    return val;
}
  

int main()
{
    //std::ios::sync_with_stdio(false);
    int n,m,q;
    while(~scanf("%d%d%d", &n, &m, &q))
    {
        bit.init(n,m);
        int op, r1, c1, r2, c2;
        while(q--)
        {
            scanf("%d%d%d%d%d", &op, &r1, &c1, &r2, &c2);
            if(op<=2){
                int val = Hash(r1,c1,r2,c2);
                bit.update(r1,c1,r2,c2,val);
            }else{
                puts(bit.query(r1,c1) == bit.query(r2,c2) ? "Yes" : "No");
            }
        }
    }
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

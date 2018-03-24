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

const LL P =  998244353;
LL f[5005], C[5005][5005];

void init()
{
    f[0] = 1; 
    for (int i = 1; i <= 5000; i++) //1e6以内的组合数
    {
        f[i] = f[i - 1] * i % P;
    }
    for(int i=0;i<=5000;i++){
        C[i][1]=i%P;
        C[i][0]=C[i][i]=1;
    }
    for(int i=2;i<=5000;i++){
        for(int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
        }
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    init();
    int a,b,c;
    while(~scanf("%d%d%d", &a, &b, &c))
    {
        LL aa = 0, bb = 0, cc = 0;
        int ab = min(a,b);
        for(int i=1;i<=ab;i++)
        {
            aa = (aa + ((C[a][i]*C[b][i])%P * f[i])%P )%P;
        }
        aa++;
        int bc = min(b,c);
        for(int i=1;i<=bc;i++)
        {
            bb = (bb + ((C[b][i]*C[c][i])%P * f[i])%P )%P;
        }
        bb++;
        int ac = min(a,c);
        for(int i=1;i<=ac;i++)
        {
            cc = (cc + ((C[a][i]*C[c][i])%P * f[i])%P )%P;
        }
        cc++;
        LL ans = ((aa*bb)%P*cc)%P;
        printf("%lld\n", ans);
    }
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

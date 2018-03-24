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

LL pre[26],suf[26];
char str1[MaxN], str2[MaxN];
LL cnt[26][MaxM];
int main()
{
    //std::ios::sync_with_stdio(false);
    freopen("concatenation.in", "r", stdin);
    freopen("concatenation.out", "w", stdout);
    while(~scanf("%s%s", &str1, &str2))  
    {
        for(int i=0;i<26;i++) pre[i] = suf[i] = 0;
        CLR(cnt);

        int len1 = strlen(str1), len2 = strlen(str2), loc=-1;
        for(int i=0;i<len1;i++)
        {
            loc = str1[i]-'a';
            pre[loc]++;
        }
        loc = -1;
        for(int i=0;i<len2;i++)
        {
            loc = str2[i]-'a';
            suf[loc]++;
        }
        pre[str1[0]-'a']--;
        suf[str2[len2-1]-'a']--;
        LL ans = 1LL*len1*len2;
        for(int i=0;i<26;i++) ans -= pre[i]*suf[i];
        printf("%lld\n", ans);
    }
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}
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

#define MaxN 1005
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

int T,ans[MaxN],Next[MaxN],len;
char str[MaxN],temp[MaxN];
void makeNext(const char P[], int next[])
{
    int q,k, m = strlen(P);
    next[0] = 0;
    for(q=1,k=0;q<m;++q)
    {
        while(k>0 && P[q]!=P[k])
            k = next[k-1];
        if(P[q] == P[k])
            k++;
        next[q] = k;
    }
}
void solve(){
    for(int i=0;i<len;i++)
    {
        strcpy(temp, str+i);
        makeNext(temp,Next);
        for(int j=len-i-1;j>=0;j--)        
        {
            int L = j+1; 
            int length = L-Next[L-1];
            if(L%length!=0) continue;
            int num = L/length;
            ans[num] = max(ans[num],L);
            for(int k=1;k*k<=num;k++)
            {
                if(num%k==0)
                {
                    ans[num/k] = max(ans[num/k], L);
                    ans[k] = max(ans[k], L);
                }
            }
            // cout << L << " " << i << ": " << length << endl;
        }
    }
}


int main()
{
    // std::ios::sync_with_stdio(false);
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
    {
        CLR(ans);
        scanf("%s", str);
        len = strlen(str);
        solve();
        printf("Case #%d: ", t);
        ans[1] = len;
        for(int i=1;i<=len;i++) printf("%d%c", ans[i]," \n"[i==len]);
    }
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}
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

int T,DP[301];
char str[301];

int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("A-small-attempt0.in","r",stdin);
	//freopen("A.out","w",stdout);
    /********************************************/
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
    {
        scanf("%s", str);
        int len = strlen(str);
        if(len<=4)
        {
            printf("Case #%d: %d\n", t, len);
            continue;
        }
        for(int i=0;i<len;i++) DP[i] = i+1;
        for(int i=4;i<len;i++)
        {
            CLR(Next);
            Next[0] = 0;
            int k = 0;
            for(int j=i-1;j>i/2;j--)
            {
                int q = i-j;
                while(k>0 && str[i-q]!=str[i-k] ) k = Next[k-1];
                if(str[i-q] == str[i-k]) k++;
                Next[q] = k;
                int m = i-j+1;
                for(int s=0, q=0; s<j;s++)
                {
                    while(q>0 && str[i-q] != str[j-1-s]) q = Next[q-1];
                    if(str[i-q] == str[j-1-s]) q++;
                    if(q==m)
                    {
                        int loc = j-1-s+m-1;
                        DP[i] = min(DP[i], DP[j]+)
                    }
                }
            }
        }

        printf("Case #%d: %d\n", t, t);
    }
    /********************************************/
    //fclose(stdin);
    //fclose(stdout);
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

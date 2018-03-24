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
using namespace std;

#define MaxN 2000005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}

int n,k,x;
char ans[MaxN], str[MaxN];
int f[MaxN];
int finds(int x) //非递归
{
     return f[x]==x?x:f[x]=finds(f[x]);
}
void init()
{
    int i = 2000000;
    while(i)
    {
        f[i] = i;
        i--;
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    cin >> n;
    init();
    int fin = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%s%d", &str, &k);
        int len = strlen(str);
        while(k--)
        {
            scanf("%d", &x);
            fin = max(fin,x+len);
            for(int i=finds(x);i<len+x;i=f[i]=finds(i+1))
            {
                ans[i] = str[i-x];
            }
        }
    }
    for(int i=1;i<fin;++i) putchar(ans[i]?ans[i]:'a');puts("");
    //system("pause");  
    //printf("%lld\n", (x%mod+mod)%mod );
}

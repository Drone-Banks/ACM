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
#define ps push_back
using namespace std;

#define MaxN 100010
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

int N;
LL a[MaxN];
LL sum[MaxN];
map<LL,bool> Mp,Ms;
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &N))
    {
        Mp.clear(), Ms.clear();
        LL ss = 0;
        for(int i=1;i<=N;i++)
        {
            scanf("%d", &a[i]);
            ss += a[i];
        }
        if(ss&1) puts("NO");
        else
        {
            LL mid = ss/2;
            sum[0] = 0;
            bool flag = true, ans = false;
            for(int i=1;i<=N;i++)
            {
                if(Mp[a[i]])
                {
                    ans = true;
                    break;
                }
                Ms[a[i]] = 1;
                sum[i] = sum[i-1] + a[i];
                if(sum[i]==mid) 
                {
                    ans = true;
                    break;
                }
                if(sum[i]>mid)
                {
                    if(Ms[sum[i]-mid]==1) 
                    {
                        ans = true;
                        break;
                    }
                }
                if(sum[i]<mid) 
                {
                    Mp[mid-sum[i]] = 1;
                }
            }
            if(ans) puts("YES");
            else puts("NO");
        }
    }
    //system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

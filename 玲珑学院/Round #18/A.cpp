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

#define MaxN 100001
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

int Map[11][11][11];
LL ans[33];
LL sum[33];
void init()
{
    CLR(ans);
    for(int x1=0;x1<=10;x1++)
    for(int y1=0;y1<=10;y1++)
    for(int z1=0;z1<=10;z1++)
    {
        if(Map[x1][y1][z1]==0) continue;
        //debug(Map[x1][y1][z1])
        for(int x2=0;x2<=10;x2++)
        for(int y2=0;y2<=10;y2++)
        for(int z2=0;z2<=10;z2++)
        {
            if(Map[x2][y2][z2]==0) continue;
            if(x1==x2 && y1==y2 && z1==z2)
            {
                //bug;
                ans[0] += (LL)Map[x1][y1][z1]*(Map[x1][y1][z1]-1)/2;
                //debug(x1) debug(y1) debug(z1)
                //debug(Map[x2][y2][z2])
            }
            else{
                int dis = abs(x1-x2)+abs(y1-y2)+abs(z1-z2);
                ans[dis]+=(LL)Map[x1][y1][z1]*Map[x2][y2][z2];
            }
        }
    }
    sum[0] = ans[0];
    //debug(ans[0])
    for(int i=1;i<=30;i++)
    {
        //debug(ans[i])
        sum[i] = sum[i-1] + ans[i]/2;
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    int T,n,q;
    scanf("%d", &T);
    while(T--)
    {
        CLR(Map);
        scanf("%d%d", &n, &q);
        int a,b,c;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            Map[a][b][c]++;
        }
        init();
        int R;
        while(q--)
        {
            scanf("%d", &R);
            printf("%lld\n", sum[min2(R,30)]);
        }
    }

    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

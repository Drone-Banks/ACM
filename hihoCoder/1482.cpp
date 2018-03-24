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
using namespace std;

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x;
inline void up(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}

int DP[MaxN][2][3];
//DP[i][j][k]表示前i个字符有j个A和连续K个L
void init()
{
    DP[0][0][0] = 1;
    for(int i=0;i<=100000;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<3;k++)
            {
                up(DP[i+1][j][0], DP[i][j][k]);
                if(j!=1) up(DP[i+1][j+1][0],DP[i][j][k]);
                if(k!=2) up(DP[i+1][j][k+1],DP[i][j][k]);
            }
        }
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    init();
    int N;
    while(~scanf("%d", &N))
    {
        int ans = 0;
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<3;k++)
            {
                up(ans, DP[N][j][k]);
            }
        }
        printf("%d\n", ans);
    }
    //system("pause");
}

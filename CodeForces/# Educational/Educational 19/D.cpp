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
#define debug(x) cout << #x" = " << x << endl;
int n,q,p,k;
int A[MaxN];
int times[MaxN][110];
void init()
{
    for(int kk=1;kk<=100;kk++)
    {
        for(int i=1;i<=kk;i++)
        {
            int tmp = i,  cnt = 0;
            while(tmp<=n)
            {
                tmp = tmp + A[tmp] + kk;
                cnt ++;
                times[tmp][kk] = cnt;
            }
            times[i][kk] = cnt;

        }
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &n))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &A[i]);
        }
        init();
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d%d", &p, &k);
            int cnt = 0;
            if(k<=100)
            {
                cnt = times[p][k];
            }
            else
            {
                while(p<=n)
                {
                    p = p+A[p]+k;
                    cnt++;
                }
            }
            printf("%d\n",cnt );
        }
    }
    //system("pause");
}

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


int n,sum;

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &n))
    {
        sum=0;
        int x, mino1 = 1E9+7, mino2 = 0;
        for(int i=0;i<n;i++)
        {
            scanf("%d", &x);
            if(x%2)
            {
                if(x>0)
                {
                    sum+=x;
                    mino1 = min(mino1, x);
                }
                else
                {
                    if(mino2==0) mino2 = x;
                    else mino2 = max(mino2,x); 
                }
            }
            else
            {
                if(x>0) sum+=x;
            }
            //debug(mino1);debug(mino2);
        }
       // debug(sum);
        
        if(sum%2==0 && mino1==1E9+7 ) sum+=mino2;
        else if(mino2==0) 
        {
            if(sum%2==0) sum-=mino1;
        }
        else
        {
            if(sum%2==0)
            {
                if(mino1+mino2>0) sum+=mino2;
                else sum-=mino1;
            }
        }
        printf("%d\n", sum);
    }
    //system("pause");
}

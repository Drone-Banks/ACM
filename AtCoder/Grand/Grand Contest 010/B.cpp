/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/
 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
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
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)
 
LL N;
LL A[MaxN];
//a2-a1 - num / N
int main()
{
    LL sum = 0;
    scanf("%lld", &N);
    for(int i=0;i<N;i++)
    {
        scanf("%lld", &A[i]);
        sum+=A[i];
    }
    LL tmp = (1+N)*N/2;
    if(sum%tmp) printf("NO\n");
    else
    {
        int flag = 0;
        LL num = sum/tmp;
        LL x=0;
        LL y=0;
        for(int i=0;i<N;i++)
        {
            LL d;
            if(i==0) d = A[0]-A[N-1];
            else d = A[i] - A[i-1];
            d = d + num*(N-1);
            
            if( d % N !=0  )
            {
                flag = 1;
                break;
            }
            else
            {
                d = d/N;
                if(d<0 || d>num)
                {
                    flag = 1;
                    break;
                }
                else
                {
                    x+=d;
                    y+=(num-d);
                }
            }
 
        }
        if(flag) printf("NO\n");
        else
        {
            //cout << x << " " << y << endl;
            if( (x - y*(N-1)) == 0) printf("YES\n");
            else printf("NO\n");
        }
    }
   // system("pause");
}
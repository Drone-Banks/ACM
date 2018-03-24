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

#define MaxN 100000
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

LL A[MaxN];
LL B[MaxN];
int N;

int main()
{
    while(~scanf("%d", &N))
    {
        for(int i=1;i<=N;i++)
        {
            scanf("%lld%lld", &A[i], &B[i] );
        }
        LL tmp = 0;
        for(int i=N;i>0;i--)
        {
            if(A[i]==0) continue;
            A[i] += tmp;
            if(A[i]<B[i])
            {
                tmp+=B[i]-A[i];
            }
            else if(A[i]%B[i] == 0) continue;
            else
            {
                LL cnt = A[i]%B[i];
                tmp += (B[i]-cnt);
            }
            //cout << tmp << endl;
        }
        printf("%lld\n", tmp);
    }
    //system("pause");
}
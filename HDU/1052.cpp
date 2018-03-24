 /*************************************************************************
    > File Name: 1052.cpp
    > Author: Akira
    > Mail: qaq.febr2.qaq@gmail.com
    > Created Time: 2017年01月17日 星期二 20时49分05秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<cmath>
#include<vector>
#include<set>
#include<list>
#include<ctime>
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
#define EPS 1e-8
#define bug cout << 88888888 << endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

int n;
int A[1005];
int B[1005];
bool cmp(int a, int b)
{
    return a>b;
}
int main()
{
    while(~scanf("%d", &n) && n)
    {
        for(int i=0;i<n;i++) scanf("%d", &A[i]);
        for(int i=0;i<n;i++) scanf("%d", &B[i]);
        sort(A,A+n,cmp);
        sort(B,B+n,cmp);
        
        int win = 0;

        int Ts = 0,Qs = 0;
        int Te = n-1,Qe = n-1;

        while(n--)
        {
            if(A[Ts] > B[Qs])
            {
                Ts++;
                Qs++;
                win++;
            }
            else
            {
                if(A[Te] > B[Qe])
                {
                    Te--;
                    Qe--;
                    win++;
                }
                else if(A[Te]<B[Qs])
                {
                    Te--;
                    Qs++;
                    win--;
                }
            }
        }
        printf("%d\n", win*200);
    }
    return 0;
}
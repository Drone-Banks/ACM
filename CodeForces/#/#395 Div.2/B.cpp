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

#define MaxN 200001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

int n;
int a[MaxN];

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=1;i<=n;i++) scanf("%d", &a[i]);
        for(int i=1;i<=n/2;i++)
        {
            if(i&1)
            {
                swap(a[i], a[n-i+1]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(i!=1) printf(" ");
            printf("%d", a[i]);
        }
        printf("\n");
    }
    //system("pause");
}
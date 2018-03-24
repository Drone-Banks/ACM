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

#define MaxN 1501
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

LL Ugly[MaxN];

void init()
{
    LL x = 1;
    LL y = 1;
    LL z = 1;
    Ugly[1] = 1;
    for(int i=2;i<=1500;i++)
    {
        LL Min = MIN(Ugly[x]*2,MIN(Ugly[y]*3,Ugly[z]*5));
        Ugly[i] = Min;
        if(Ugly[i] == Ugly[x]*2) x++;
        if(Ugly[i] == Ugly[y]*3) y++;
        if(Ugly[i] == Ugly[z]*5) z++;
    }
}
int main()
{
    init();
    int n;
    while(scanf("%d", &n) && n)
    {
        cout << Ugly[n] << endl;
    }
    system("pause");
}
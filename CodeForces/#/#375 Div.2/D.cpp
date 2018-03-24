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

#define MaxN 2123
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)
int n,m,k;
int Map[66][66];


int main()
{
    while(~scanf("%d%d%d", &n, &m, &k))
    {
        char ch;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int x;
                scanf("%c", &ch);
                if(ch == '*') x = 1;
                else x = 0;
                Map[i][j] = x;
            }
        }



    }
    system("pause");
}
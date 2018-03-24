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
int x, y;

int main()
{
    while(~scanf("%d%d", &x, &y))
    {
        int a,b,c;
        a = b = c = y;
        LL cnt = 0;
        int num = 0;
        while(num!=3)
        {
            cnt++;
            int tmp = a+b-1;
            if(tmp >= x)
            {
                num++;
                tmp = x;
            }
            c = b;
            b = a;
            a = tmp;
        }
        cout << cnt << endl;
    }
    //system("pause");
}
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

int get(char ch){
    switch(ch)
    {
    case 'a':
        return 4;
    case 'b':
        return 5;
    case 'c':
        return 6;
    case 'd':
        return 3;
    case 'e':
        return 2;
    case 'f':
        return 1;
    }
}

int main()
{
    char ch;
    LL n;
    while(~scanf("%I64d%c", &n, &ch))
    {
        LL ans = 0;
        LL number = n/4;
        LL mod = n%4;
    
        if(mod == 0)
        {
            ans += (number-1) * 16;
            ans += 7;
            ans += get(ch);
        }
        else
        {
            LL x = mod%2;
            ans += number * 16;
            if(x)
            {
                ans += get(ch);
            }
            else
            {
                ans += 7;
                ans += get(ch);
            }
        }
        cout << ans << endl;
    }
    system("pause");
}
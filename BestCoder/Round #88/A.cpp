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

int T;
char str[112345];

LL cal(int x)
{
    return (1+x)*x/2;
}


int main()
{
    cin >> T;
    while(T--)
    {
        scanf("%s", str);
        LL ans = 0;
        int count = 0;
        for(int i=0;i<strlen(str);i++)
        {
            if( str[i] != 'q' && count)
            {
                ans += cal(count);
                count=0;
            }
            if(str[i] == 'q')
            {
                count++;
                if( i==strlen(str)-1)
                {
                    ans+=cal(count);
                    break;
                }
            }
        }
        cout << ans << endl;

    }
    system("pause");
}
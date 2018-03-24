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

#define MaxN 200005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

int A[MaxN];

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        char str[MaxN];
        scanf("%s", str);
        for(int i=1;i<=n;i++)
        {
            int x;
            if(str[i-1] == '<') x = -1;
            else x = 1;
            A[i] = x;
        }

        int ans = 0;

        int left = 0, right = 0;
        for(int i=1;i<=n;i++)
        {
            if(A[i] == 1) 
            {
                left = 1;
                ans += (i-1);
                break;
            }
        }
        if(!left) ans += n;
        for(int i=n;i>=1;i--)
        {
            if(A[i] == -1)
            {
                right = 1;
                ans += (n-i);
                break;
            }
        }
        if(!right) ans += n;
        cout << ans << endl;
    }
    system("pause");
}
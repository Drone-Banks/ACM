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

int n;
string str;
int ans[110];

int main()
{
    while(~scanf("%d", &n))
    {
        CLR(ans);
        cin >> str;
        int cnt = 0;
        int count = 0;
        for(int i=0;i<str.length();i++)
        {
            if(str[i] == 'W' && count)
            {
                ans[cnt] = count;
                count = 0;
            }

            if(str[i] == 'B')
            {
                if(count == 0) cnt++;
                count++;
                if(i == str.length()-1)
                {
                    ans[cnt] = count;
                }
            }
        }
        if(cnt) cout << cnt << endl;
        for(int i=1;i<cnt;i++)
        {
            cout << ans[i] <<" ";
        }
        cout << ans[cnt] << endl;
    }
    //system("pause");
}
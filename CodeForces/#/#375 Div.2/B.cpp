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

int n;
string str;
int main()
{
    while(~scanf("%d", &n))
    {
        cin >> str;
        int cnt = 0;
        int Max = 0;
        int i=0;
        int flag = 0;
        while(i<n)
        {
            if(i==n) break;
            //cout << str[i] <<" " <<Max << "_" << cnt << endl;
            if(str[i] == '_' || str[i] == ')')
            {
                if(flag) Max = MAX(Max, flag);
                i++;
                flag = 0;
                while(i<n)
                {
                    if(str[i] == '_')
                    {
                        if(flag) Max = MAX(Max, flag);
                        flag = 0;
                    }
                    else if(str[i] == '(')
                    {
                        if(flag) Max = MAX(Max, flag);
                        flag = 0;
                        break;
                    }
                    else flag++;
                    i++;
                }
                if(i==n) break;
            }
            else if(str[i] == '(')
            {
                i++;
                int flag = 0;
                while(i<n)
                {
                    if(str[i] == '_')
                    {
                        if(flag) cnt++;
                        flag = 0;
                    }
                    else if(str[i] == ')')
                    {
                        if(flag) cnt++;
                        flag = 0;
                        break;
                    }
                    else flag++;
                    i++;
                }
                if(i==n) break;        
            }
            else
            {
                i++;
                flag++;
            }
        }
        if(flag) Max = MAX(Max, flag);
        cout << Max << " " << cnt << endl;
    }
    system("pause");
}
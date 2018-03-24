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

int n,k;

int pwd[110];

int main()
{
    while(~scanf("%d%d", &n, &k))
    {
        CLR(pwd);
        string str;
        for(int i=0;i<n;i++)
        {
            cin >> str;
            pwd[str.length()]++;
        }
        cin >> str;
        int x = str.length();
        
        int cnt = 0;
        for(int i=0;i<x;i++)
        {
            cnt+=pwd[i];
        }
        
        int a = cnt/k;
        int b = (cnt+pwd[x]-1)/k;

        cout << a*5+cnt+1 << " " << b*5+cnt+pwd[x]<< endl;
    }
}
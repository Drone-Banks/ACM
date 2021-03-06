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

#define MaxN 1001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;

string Map[MaxN];
int N;

int main()
{
    scanf("%d", &N);
    for(int i=0;i<N;i++)
    {
        cin >> Map[i];
    }

    int flag = 0;
    for(int i=0;i<N;i++)
    {
        if(Map[i][0]=='O' && Map[i][1]=='O')
        {
            flag = 1;
            Map[i][0] = '+';
            Map[i][1] = '+';
            break;
        }

        if(Map[i][3]=='O' && Map[i][4]=='O')
        {
            flag = 1;
            Map[i][3] = '+';
            Map[i][4] = '+';
            break;
        }
    }

    if(flag)
    {
        cout << "YES\n";
        for(int i=0;i<N;i++)
        {
            cout << Map[i] << endl;
        }
    }
    else
        cout << "NO\n";


    return 0;
}
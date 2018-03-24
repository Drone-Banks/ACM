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


int main()
{
    int sta;
    string time;
    while( ~scanf("%d", &sta))
    {
        cin >> time;
        if(sta == 12)
        {
            if(time[0] == '0' && time[1] == '0') time[1] = '1';

            if(time[0] == '1' && time[1] > '2') time[1] = '2';

            if(time[0] > '1' && time[1] == '0') time[0] = '1';
            if(time[0] > '1' && time[1] != '0')  time[0] = '0';

            if(time[3] > '5') time[3] = '5';
        }
        else
        {
            if(time[0] == '2' && time[1] > '3') time[1] = '3';
            if(time[0] > '2') time[0] = '1';
            if(time[3] > '5') time[3] = '5';
        }
        for(int i=0;i<5;i++) cout<<time[i];
        cout << endl;
    }
    system("pause");
}
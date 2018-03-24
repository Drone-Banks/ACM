/*************************************************************************
	> File Name: A.cpp
	> Author: Akira
	> Mail: qaq.febr2.qaq@gmail.com
	> Created Time: 2017年03月18日 星期六 12时02分58秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<cmath>
#include<vector>
#include<set>
#include<list>
#include<ctime>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))

using namespace std;

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1e9+7;
const int eps = 1e-8;
#define bug cout << 88888888 << endl;
int T,N,R,X;
int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &N,&R,&X);
        int l = max(1, X-R);
        int r = min(N, X+R);
        cout << (r-l)+1 << endl;
    }
}


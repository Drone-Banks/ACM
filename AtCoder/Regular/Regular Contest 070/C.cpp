/*************************************************************************
	> File Name: A.cpp
	> Author: Akira
	> Mail: qaq.febr2.qaq@gmail.com
	> Created Time: 2017年03月18日 星期六 20时12分20秒
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

int arr[MaxN];
map<int, int> M;
void init()
{
    arr[0] = 0;
    for(int i=1;i<=1E5;i++)
    {
        arr[i] = arr[i-1] + i;
        M[arr[i]] = i;
    }
}

int X;
int main()
{
    init();
    while(~scanf("%d", &X))
    {
        int num = *(upper_bound(arr+1, arr+1+MaxN, X)-1);
        if( num == X ) printf("%d\n", M[num]);
        else printf("%d\n", M[num]+1);
    }
}


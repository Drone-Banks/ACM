/*************************************************************************
	> File Name: B.cpp
	> Author: Akira
	> Mail: qaq.febr2.qaq@gmail.com
	> Created Time: 2017年05月06日 星期六 17时00分40秒
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

int T;

LL N;
int K;

int main()
{
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
    {
        scanf("%lld%d", &N, &K);
        LL tmp = (1<<K)-N;
        printf("Case #%d:\n", t);
        for(int i=1;i<K;i++)
        {
            if( tmp & (1<<(i)) ) printf("%lld -\n", (1LL<<(i-1)) );
            else printf("%lld +\n", (1LL<<(i-1)) );
        }
        if(N&1LL) printf("%lld +\n", (1LL<<(K-1)) );
        else printf("%lld +\n", (1LL<<(K-1))+1LL);
    }
}

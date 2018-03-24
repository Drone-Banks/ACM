/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
#include <climits>
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
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
int T;
LL M,N;
int K;
LD Power(LD a, int b) 
{
    LD ans = 1.0;
    a = a;
    while(b>0)
    {
        if(b % 2 == 1) ans = (ans * a);
        b = b/2;
        a = (a * a);
    }
    return ans;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
    {
        scanf("%lld%lld%d", &M, &N, &K);
        LL fenmu = (M*N)*(M*N);
        LD tmp = 0.0;
        for(LL i=1;i<=M;i++)
        {
            for(LL j=1;j<=N;j++)
            {
                
                LL cnt = (Sqr(N*(i-1)) + Sqr(N*(M-i)) + Sqr(M*(j-1)) + Sqr(M*(N-j)) - Sqr((i-1)*(j-1)) - Sqr((j-1)*(M-i)) - Sqr((N-j)*(M-i)) - Sqr((N-j)*(i-1)));
                LD pro = cnt*1.0/fenmu;
                tmp += (1.0-pow(pro,K));
            }
        }
        LL ans = round(tmp);
        printf("Case #%d: %lld\n",t, ans);
    }
    //system("pause")  ;
}

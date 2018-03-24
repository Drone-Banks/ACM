/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <iomanip>
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

#define MaxN 5005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
int N;
int cow[MaxN],flip[MaxN];
int check(int K)
{
    CLR(flip);
    int op = 0, cnt = 0;
    for(int i=1;i+K-1<=N;i++)
    {
        if( (cow[i]+cnt)&1 ) 
        {
            op++;
            flip[i] = 1;
        }
        cnt += flip[i];
        if(i-K+1>0)
        {
            cnt -= flip[i-K+1];
        }
    }
    for(int i=N-K+2;i<=N;i++)
    {
        if( (cow[i]+cnt)&1 )
        {
            return -1;
        }
        if(i-K+1>0)
        {
            cnt -= flip[i-K+1];
        }
    }
    return op;
}
void solve()
{
    int K=1,M=N;
    for(int k=1;k<=N;k++)
    {
        int m = check(k);
        if(m>=0 && M>m)
        {
            M = m;
            K = k;
        }
    }
    printf("%d %d\n", K, M);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &N))
    {
        char ch;
        for(int i=1;i<=N;i++)
        {
            getchar();
            ch = getchar();
            if(ch=='F') cow[i] = 0;
            else cow[i] = 1;
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

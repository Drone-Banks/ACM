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

#define MaxN 1010
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
int N;
int X[MaxN], Y[MaxN], Z[MaxN];

int gcd(int a, int b)
{
    return b==0?a:gcd(b, a%b);
}

bool cal(int t, int a, int b, int c, int d)
{
    if( a%t==0 || b%t==0 || c%t==0 || d%t ==0 ) return true;
    return false;
}

bool judge(int i, int j)
{
    int t = gcd(X[i], X[j]);
    if( cal(t, Y[i]-Z[j], Z[i]-Y[j], Y[i]-Y[j], Z[i]-Z[j]) )
    {
        return true;
    }
    else return false;

}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &N))
    {
        for(int i=1;i<=N;i++) 
        {
            scanf("%d%d%d", &X[i], &Y[i], &Z[i]);
        }
        bool flag = false;
        for(int i=1;i<=N;i++)
        {
            for(int j=i+1;j<=N;j++)
            {
                if(judge(i,j))
                {
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) puts("Cannot Take off");
        else puts("Can Take off");
    }

    //system("pause");
}
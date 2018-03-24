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

int T,n;

int A[MaxN];

bool judge()
{
    int use = 0;
    for(int i=n;i>=2;i--)
    {
        if(A[i]==1) use++;
        else
        {
            if(use==0) return false;
            else
            {
                use--;
            }
        }
    }
    return true;
}

void solve()
{
    if(judge()) puts("Yes");
    else puts("No");
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i=2;i<=n;i++) scanf("%d", &A[i]);
        if( n&1 || A[n]==2) puts("No");
        else solve();
    }

}
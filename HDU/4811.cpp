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

#define MaxN 2017
#define MaxM 2017*2017/2
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;

LL A[4];

int main()
{
    while(~scanf("%lld%lld%lld", &A[0], &A[1], &A[2]))
    {
        sort(A,A+3);
        int loc = 0;
        while(A[loc]==0&&loc<3) loc++; 
        //debug(loc);
        LL ans = 0;
        if(loc==2)
        {
            A[2]--;
            if(A[2]>0)
            {
                A[2]--;
                ans++;
            }
           ans += 2LL *(LL)A[2];
        }
        else if(loc==1)
        {
            if(A[2]==1) ans = 1;
            else 
            {
                if(A[1]==1)
                {
                    A[2] -= 2;
                    ans = 3;
                    ans += 3LL * (LL)A[2];
                }
                else 
                {
                    A[2]-=2;
                    A[1]-=2;
                    ans = 6;
                    ans += 4LL *(LL)(A[2]+A[1]);
                }
            }
        }
        else if(loc == 0)
        {
            if(A[2]==1) ans = 3;
            else 
            {
                if(A[1]==1)
                {
                    A[2] -= 2;
                    ans = 6;
                    ans += 4LL *(LL)(A[2]);
                }
                else if(A[0]==1)
                {
                    A[2]-=2;
                    A[1]-=2;
                    ans = 10;
                    ans += 5LL*(LL)(A[2]+A[1]);
                }
                else
                {
                    A[2]-=2;
                    A[1]-=2;
                    A[0]-=2;
                    ans = 15;
                    ans+=6LL * (LL)(A[2]+A[1]+A[0]);
                }
            }
        }
        printf("%lld\n", ans);
    }
}
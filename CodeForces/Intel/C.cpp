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

#define MaxN 100005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;

int n;
LL A[MaxN];
int P[MaxN];
int vis[MaxN];
int sum[MaxN];
LL ans[MaxN];
int main()
{
    while(~scanf("%d", &n))
    {
        CLR(vis);
        CLR(sum);
        map<int, LL> M;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld", &A[i]);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &P[i]);  
        }
        ans[n] = 0;
        ans[n-1] = A[P[n]];
        vis[P[n]] = 1;
        sum[P[n]] = P[n];
        M[P[n]] = A[P[n]];
        LL Max = A[P[n]];
        for(int i=n-1;i>=2;i--)
        {
            vis[P[i]] = 1;
            if(P[i] == 1)
            {
                if(vis[2])
                {
                    sum[1] = sum[2];
                    M[sum[1]]+=A[1];
                }
                else
                {
                    sum[1] = 1;
                    M[1] = A[1];
                }
                
            }
            if(P[i] == n)
            {
                if(vis[n-1])
                {
                    sum[n] = sum[n-1];
                    M[sum[n]]+=A[n];
                }
                else
                {
                    sum[n] = n;
                    M[n] = A[n];
                }
            }

            if( P[i] > 1 && P[i] < n)
            {
                if( !vis[P[i]-1] && !vis[P[i]+1] )
                {
                    sum[P[i]] = P[i];
                    M[P[i]] = A[P[i]];
                }

                if( vis[P[i]-1] && !vis[P[i]+1] )
                {
                    sum[P[i]] = sum[P[i]-1];
                    M[sum[P[i]]]+=A[P[i]];
                }

                if( !vis[P[i]-1] && vis[P[i]+1] )
                {
                    sum[P[i]] = sum[P[i]+1];
                    M[sum[P[i]]]+=A[P[i]];
                }

                if( vis[P[i]-1] && vis[P[i]+1] )
                {
                    sum[P[i]] = sum[P[i]-1];
                    M[sum[P[i]]]= M[sum[P[i]]]+ A[P[i]] + M[sum[P[i]+1]];
                    int x = P[i]+1;
                    while(vis[x]&&x<=n)
                    {
                        sum[x] = sum[P[i]];
                        x++;
                    }
                }
            }

            if(M[sum[P[i]]] > Max)
            {
                ans[i-1] = M[sum[P[i]]];
                Max = M[sum[P[i]]];
            }
            else ans[i-1] = Max;
        }

        for(int i=1;i<=n;i++)
        {
            cout << ans[i] << endl;
        }


    }
    system("pause");
}
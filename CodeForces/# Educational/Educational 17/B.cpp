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

#define MaxN 400000
#define MaxM MaxN*10
#define INF 10e9
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

int a,b,c;
int m;
LL U[MaxN];
LL P[MaxN]; 
char str[6];

int main()
{
    while(~scanf("%d%d%d", &a, &b, &c))
    {
        scanf("%d", &m);
        U[0] = P[0] = 0;
        while(m--)
        {
            int x;
            scanf("%I64d %s", &x, str);
            if(str[0] == 'U')
            {
                U[ ++U[0] ] = x;
            }
            else
            {
                P[ ++P[0] ] = x;
            }
        }
        
        sort( U+1, U+1+U[0]);
        sort( P+1, P+1+P[0]);
        U[U[0]+1] = INF+1;
        P[P[0]+1] = INF+1;
        LL ans = 0;
        
        int n1 = MIN(U[0], a);
        for(int i=1;i<=n1;i++) ans+=U[i];
        int n2 = MIN(P[0], b);
        for(int i=1;i<=n2;i++) ans+=P[i];
        //cout << ans << endl;
        //cout << n1+n2 << endl;
        while( c && (n1<U[0] || n2<P[0]) )
        {
            if(n1 >= U[0])
            {
                n2++;
                ans += P[n2];
                c--;
            }
            else if( n2 >= P[0])
            {
                n1++;
                ans += U[n1];
                c--;
            }
            else
            {
                if( P[n2+1] <= U[n1+1])
                {
                    n2++;
                    ans += P[n2];
                    c--;
                }
                else 
                {
                    n1++;
                    ans += U[n1];
                    c--;
                }
            }
        }
        printf("%d %I64d\n", n1+n2, ans );


    }
    //system("pause");
}
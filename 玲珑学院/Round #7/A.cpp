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

#define MaxN 1000050
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

int T;
int n;
int a[MaxN];
int b[MaxN];

bool solve(int loc, int dist)
{
    //cout << loc << " " << dist << endl;
    if(loc == n) return false;
    else
    {
        if(b[loc+1] == -dist)
        {
            if(loc+1 != n)
            {
                b[loc+2] -= dist;
            }
            b[loc+1] = dist;
            b[loc] -= dist;
            return true;
        }
        else
        {
            int Ndist = b[loc+1]+dist;
            if(solve(loc+1, Ndist) && solve(loc, dist)) return true;
            else  return false;
        }
    }
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i=1;i<=n;i++) scanf("%d", &a[i]);
        for(int i=1;i<=n;i++) scanf("%d", &b[i]);
        int flag = 0;
        for(int i=1;i<=n;i++)
        {
            if(a[i] == b[i]) continue;
            else
            {
                int dist = b[i] - a[i];
                if(solve(i, dist)) continue;
                else 
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag) cout << "No\n";
        else cout << "Yes\n";
    }
    system("pause");
}
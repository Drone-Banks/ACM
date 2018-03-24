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

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

int T;
int n;
LL A[MaxN];
map<LL, int> M;
int main()
{
    scanf("%d", &T);
    while(T--)
    {
        M.clear();
        scanf("%d", &n);
        for(int i=0;i<n;i++) scanf("%lld", &A[i]);
        for(int i=0;i<n;i++)
        {
            M[A[i]]++;
        }
        int Min = MaxN;
        for(int i=0;i<n;i++)
        {
            Min = MIN(M[A[i]], Min);
        }
        int ans[MaxN];
        int tail = 0;
        for(int i=0;i<n;i++)
        {
            if(M[A[i]] == Min)
            {
                ans[tail++] = A[i];
                M[A[i]] = 0;
            }
        }   
        sort(ans, ans+tail);
        for(int i=0;i<tail;i++)
        {
            if(i!=0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
    system("pause");
}
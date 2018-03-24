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
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

int T;
map<int ,int> M;
int ans[MaxN];
int main()
{
    int n;
    scanf("%d", &T);
    while(T--)
    {
        CLR(ans);
        M.clear();
        int x;
        int tot = 0;
        scanf("%d", &n);
        for(int i=0;i<n;i++)
        {
            scanf("%d", &x);
            if(M[x]<0) continue;
            if(M[x]>0)
            {
                ans[tot++] = x;
                M[x] = -1;
            }
            if(M[x] == 0) M[x] = 1;
        }
        sort(ans, ans+tot);
        if(tot == 0) cout <<"none\n";
        else
        {
            for(int i=0;i<tot;i++)
            {
                if(i!=0) cout << " ";
                cout << ans[i];
            }
            cout << endl;
        }
    }
    system("pause");
}
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

#define MaxN 10000001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

LL n,k;

int main()
{
    while(~scanf("%I64d%I64d", &n, &k))
    {
        if(n==1) 
        {
            if(k>1) cout << -1 << endl;
            else cout << 1 << endl;
            continue;
        }
        vector<LL> ans;
        int flag = 0;
        for(LL i=1;i*i<=n;i++)
        {
            if( n%i ==0 )
            {
                ans.push_back(i);
            }
            if(ans.size()==k)
            {
                printf("%I64d\n", ans[k-1]);
                flag = 1;
                break;
            }
             
        }
        if(flag) continue;
        if( ans.size()*2 < k)
        {
            printf("-1\n");
        }
        else
        {
            if(ans.size()<k)
            {
                int loc = 2*ans.size()-k+1;
                //cout << ans.size() << endl;
                if( n == Sqr((LL)sqrt(n))  ) 
                {
                    //bug;
                    loc-=1;
                }
                //cout << loc << endl;
                LL ANS = n/ans[loc-1];
                if(ANS==0) printf("-1\n");
                else printf("%I64d\n", n/ans[loc-1]);
            }
            else
            {
                printf("%I64d\n", ans[k-1]);
            }
        }
    }
    //system("pause");
}
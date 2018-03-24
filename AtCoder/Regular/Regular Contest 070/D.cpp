/*************************************************************************
    > File Name: B.cpp
    > Author: Akira
    > Mail: qaq.febr2.qaq@gmail.com
    > Created Time: 2017年03月18日 星期六 20时30分11秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<cmath>
#include<vector>
#include<set>
#include<list>
#include<ctime>
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
const int mod = 1e9+7;
const int eps = 1e-8;
#define bug cout << 88888888 << endl;
int N;
LL K;
LL node[MaxN];
int main()
{
    while(~scanf("%d%lld", &N, &K))
    {
        LL sum = 0;
        for(int i=1;i<=N;i++)
        {
            scanf("%lld", node+i);
        }
        sort(node+1, node+1+N);
        for(int i=1;i<=N;i++)
        {
            if(sum<K)
            {
                sum += node[i];
            }
            else break;
        }
        if(sum<K) 
        {
            printf("%d\n", N);
            continue;
        }
        LL* it = (upper_bound(node+1,node+1+N, K));
        it -=1;
        int ans = 0;

        for(int i=1;i<=N;i++)
        {
            if(sum>=K)
            {
                sum -= node[i];
            }
            
            if(sum<K)
            {
                ans = i-1;
                break;
            }
        }
        LL* low = it;
        LL* high = it;
        int lim = ans;
        while( low!= node+lim )
        {
            int cnt = 0;
            for(LL* i = low;i<=high;i++)
            {
                cnt += *i;
            }
            while(cnt>=K)
            {
                cnt -= *high;
                high--;
            }
            //cout << cnt << endl;
            int i = ans;
            while(i>0)
            {
                int tmp = cnt+node[i];
                if(tmp>=K) ans--,i--;
                else
                {
                    int j = i-1;
                    for(j;j>0;j--)
                    {
                        tmp += node[j];
                        if(tmp>=K)
                        {
                            ans -= (i-j+1);
                            break;
                        }
                    }
                    i = j;
                }
            }
            if(ans==0) break;
            low--;
        }
        printf("%d\n", ans);

    }
}
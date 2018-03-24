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

#define MaxN 5005
#define MaxM MaxN*10
#define INF 1e18
#define bug cout<<88888888<<endl;

LL n,s,e;

LL Map[MaxN];
LL a[MaxN], b[MaxN], c[MaxN], d[MaxN];
LL Next[MaxN];
LL ans;
LL dis(LL i, LL j)  
{    
    return abs(Map[i]-Map[j]) + ( Map[j]<Map[i] ? c[i]+b[j] : d[i]+a[j] );   
}  
void solve()
{
    ans = 0;
    Next[s] = e;
    ans += dis(s,e);   
    for(LL i=1;i<=n;i++)
    {  
        if(i==s||i==e)continue;  
        LL Min=INF;
        LL index;  
        for(LL j=s; j!=e; j=Next[j])
        {  
            LL tmp = dis(j,i) + dis(i, Next[j]) - dis(j,Next[j]);  
            if(tmp<Min) Min = tmp, index = j;   
        }
        ans += Min;  
        Next[i] = Next[index]; 
        Next[index] = i;  
    }  
}

int main()
{
    while(~scanf("%I64d%I64d%I64d", &n, &s, &e))
    {
        CLR(Next);
        for(LL i=1;i<=n;i++)
            scanf("%I64d", &Map[i]);
        for(LL i=1;i<=n;i++)
            scanf("%I64d", &a[i]);
        for(LL i=1;i<=n;i++)
            scanf("%I64d", &b[i]);
        for(LL i=1;i<=n;i++)
            scanf("%I64d", &c[i]);
        for(LL i=1;i<=n;i++)
            scanf("%I64d", &d[i]);

        solve();

        cout << ans << endl;

    }
    //system("pause");
}
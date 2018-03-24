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
#define INF (LL)1e15
#define bug cout<<88888888<<endl;
int n;
LL cost[MaxN];

string str[MaxN];
string Rstr[MaxN];

LL dp[MaxN][2];  

string Re(string str)
{
    string s;
    for(int i=str.length()-1;i>=0;i--)
    {
        s+=str[i];
    }
    return s;
}

bool judge(string a, string b)
{
    if(a==b) return true;

    int alen = a.length();
    int blen = b.length();
    if(alen > blen)
    {
        int i=0;
        while(a[i]==b[i] && i<blen) i++;
        if(i>=blen) return true;
        if( a[i]>b[i] ) return true;
        else  return false;
    }
    else 
    {
        int i=0;
        while(a[i]==b[i] && i<alen) i++;
        if(i>=alen) return false;
        if( a[i]>b[i] ) return true;
        else  return false;
    }
}

void solve()
{
    for(int i=1;i<=n;i++)
    {
        Rstr[i] = Re(str[i]);
        //cout << Rstr[i] << endl;
    }
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=INF;
        dp[i][1]=INF;
        //cout << dp[i][1] << endl;
    }
    dp[1][0] = 0;
    dp[1][1] = cost[1];

    for(int i=2;i<=n;i++)
    {
        int flag0 = judge(str[i], str[i-1]);
        int flag1 = judge(str[i], Rstr[i-1]);
        //cout << flag0 << " " << flag1 << endl;
        if( flag0 && flag1 ) dp[i][0] = min(dp[i][0], min(dp[i-1][0], dp[i-1][1]) );
        if( flag0 && !flag1 ) dp[i][0] = min(dp[i][0], dp[i-1][0]);
        if( !flag0 && flag1 ) dp[i][0] = min(dp[i][0], dp[i-1][1]);
        if( !flag0 && !flag1 ) dp[i][0] = INF;
        
        flag0 = judge(Rstr[i], str[i-1]);
        flag1 = judge(Rstr[i], Rstr[i-1]);
        if( flag0 && flag1 ) dp[i][1] = min(dp[i][1], min(dp[i-1][0], dp[i-1][1])+cost[i] );
        if( flag0 && !flag1 ) dp[i][1] = min(dp[i][1], dp[i-1][0]+cost[i] );
        if( !flag0 && flag1 ) dp[i][1] = min(dp[i][1], dp[i-1][1]+cost[i] );
        if( !flag0 && !flag1 ) dp[i][1] = INF;
        //cout << flag0 << " " << flag1 << endl;

        //cout << dp[i][0] << " " << dp[i][1] << endl;
    }
}


int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=1;i<=n;i++)
            scanf("%I64d", &cost[i]);
        
        for(int i=1;i<=n;i++)
        {
            cin >> str[i];
        }

        solve();
        LL ans = min(dp[n][0], dp[n][1]);

        if(ans >= INF) cout << -1 << endl;
        else cout << ans << endl;
    }

    system("pause");
}
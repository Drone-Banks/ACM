/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include<bits/stdc++.h>
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
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;

int base[10] = {1000000, 100000, 10000, 1000, 100, 10, 1};
char tar[111], now[111];
int digit[10];
vector<int> state;
int cost[666666];

void init()
{
    MST(cost,-1);
    int pre = 123456;
    queue<int> Q;
    Q.push(pre);
    state.push_back(pre);
    cost[pre] = 0;
    while(!Q.empty())
    {
        int tmp = Q.front();
        Q.pop();
        for(int i=1;i<=6;i++)
        {
            for(int j=1;j<=6;j++)
            {
                if(i!=j)
                {
                    int next = 0;
                    for(int k=1;k<=6;k++)
                    {
                        digit[k] = tmp% base[k - 1] / base[k];
                        if( digit[k]==i) digit[k] = j;
                        next = digit[k] + next*10;
                    }
                    if(cost[next]!=-1) continue;
                    cost[next] = cost[tmp]+1;
                    Q.push(next);
                    state.push_back(next);
                }
            }
        }
    }
    //debug(state.size())
}

void solve()
{
    int len = strlen(tar);
    int ans = len;
    for(int i=0;i<state.size();i++)
    {
        int tmp = state[i];
        for(int k=1;k<=6;k++)
        {
            digit[k] = tmp% base[k - 1] / base[k];
        }
        int res = cost[tmp];
        for(int j=0;j<len;j++)
        {
            int to = tar[j]-'0';
            int cnt = now[j]-'0';
            if( digit[cnt]==to) continue;
            else res++;
        }
        //if(res<ans) debug(res);
        ans = min(ans, res);
        
    }
    printf("%d\n",  ans);
}

int main()
{
    init();
    while(~scanf("%s%s", tar, now))
    {
        solve();
    }
}

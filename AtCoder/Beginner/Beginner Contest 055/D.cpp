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

int N;
char str[MaxN];
char ans[MaxN];
char dif(char ch)
{
    if (ch=='S') return 'W';
    else return 'S';
}
bool dfs(int index)
{
    if(index > N)
    {
        bool flag;
        if(ans[1] =='S')
        {
            if(str[1] == 'o') flag = ans[N]==ans[2];
            else flag = ans[N]!=ans[2];
        }
        else
        {
            if(str[1] == 'x') flag = ans[N]==ans[2];
            else flag = ans[N]!=ans[2];
        }
        if(ans[N] =='S')
        {
            if(str[N] == 'o') flag = flag&&ans[1]==ans[N-1];
            else flag = flag&&ans[1]!=ans[N-1];
        }
        else
        {
            if(str[N] == 'x') flag = flag&&ans[1]==ans[N-1];
            else flag = flag&&ans[1]!=ans[N-1];
        }
        return flag;
    }
    if(index<=2)
    {
        ans[index] = 'S';
        if( dfs(index+1)) return true;
        ans[index] = 'W';
        if( dfs(index+1)) return true;
        else return false;
    }
    else
    {
        if(ans[index-1] == 'S')
        {
            if(str[index-1] == 'o')
            {
                ans[index] = ans[index-2];
                return dfs(index+1);
            }
            else
            {
                ans[index] = dif(ans[index-2]);
                return dfs(index+1);
            }
        }
        else
        {
            if(str[index-1] == 'x')
            {
                ans[index] = ans[index-2];
                return dfs(index+1);
            }
            else
            {
                ans[index] = dif(ans[index-2]);
                return dfs(index+1);
            }
        }
    }
}

void solve()
{
    if(dfs(1)) printf("%s\n", ans+1);
    else puts("-1");
}
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &N);
    scanf("%s", str+1);
    solve();
    system("pause");
}

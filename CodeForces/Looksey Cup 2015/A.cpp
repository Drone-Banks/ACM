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
int n,m;
char str[55][55];
int turn[300];
int main()
{
    //std::ios::sync_with_stdio(false);
    MST(turn,INF);
    turn['f'] = 1, turn['a'] = 3, turn['c'] = 4, turn['e'] = 10;
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;i++)scanf("%s", str[i]);
    int ans = 0;
    for(int i=0;i<n-1;i++)
    for(int j=0;j<m-1;j++)
    {
        if(str[i][j]=='f'||str[i][j]=='a'||str[i][j]=='c'||str[i][j]=='e')
        {
            int cnt = turn[str[i][j]] + turn[str[i+1][j]] + turn[str[i][j+1]] + turn[str[i+1][j+1]];
            if(cnt==18) ans++;
        }
    }
    printf("%d\n",  ans);
    //system("pause");
}

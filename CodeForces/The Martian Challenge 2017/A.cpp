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

int n;
char str[MaxN];
int ans[11];
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &n);
    scanf("%s", &str);
    int now,cnt = 1,pre = 10,MAX=0,num=0;
    for(int i=0;i<n;i++)
    {
        now = str[i] -'0';
        if(now==pre) cnt++;
        else if(i!=0)
        {
            ans[pre] = max(ans[pre], cnt);
            if(ans[pre] == MAX) num++;
            else if(ans[pre] > MAX)
            {
                MAX = ans[pre];
                num = 1;
            }
            cnt = 1;
        }
        if(i==n-1)
        {
            ans[now] = max(ans[now], cnt);
            if(ans[now] == MAX) num++;
            else if(ans[now] > MAX)
            {
                MAX = ans[now];
                num = 1;
            }
            break;
        }
        pre = now;
    }
    printf("%d\n", num);
    for(int i=0;i<=9;i++)
    {
        if(ans[i] == MAX)
        {
            for(int k=0;k<MAX;k++) printf("%d", i);
            puts("");
        }
    }
    system("pause");
}

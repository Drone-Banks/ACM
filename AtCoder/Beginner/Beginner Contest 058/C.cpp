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
int num[66][30];
char str[66];
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {   
        scanf("%s", str);
        for(int j=0;j<strlen(str);j++)
        {
            num[i][str[j]-'a']++;
        }
    }

    for(int i=0;i<26;i++)
    {
        int cnt = 66;
        for(int j=0;j<n;j++)
        {
            cnt = min(num[j][i],cnt);
        }
        while(cnt--)
        {
            putchar((char)('a'+i));
        }
    }
    puts("");
    //system("pause");
}

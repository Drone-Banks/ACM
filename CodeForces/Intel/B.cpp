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

#define MaxN 100000
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;

int n;
int P[110];
int ans[110];
int main()
{
    while(~scanf("%d", &n))
    {
        CLR(P);
        CLR(ans);
        for(int i=1;i<=n;i++) 
            scanf("%d", &P[i]);
        getchar();
        string str;
        for(int j=1;j<=n;j++)
        {
            getline(cin, str);
            //cout << " -" << str << endl;
            for(int i=0;i<str.length();i++)
            {
                if( str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i]=='o' || str[i] == 'u' || str[i] == 'y')
                    ans[j]++;
            }
        }
        int flag = 0;
        for(int i=1;i<=n;i++) 
            if( P[i]!=ans[i])
            {
                flag = 1;
                break;
            }
        if(flag) cout << "NO\n";
        else cout << "YES\n";
    }
    system("pause");
}
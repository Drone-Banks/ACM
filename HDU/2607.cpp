/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
#include <climits>
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
#define bug cout<<88888888<<endl;
char str[MaxN];
int X[MaxN],Y[MaxN],Z[MaxN];
int main()
{
    //std::ios::sync_with_stdio(false);
    char ch;
    stringstream stream;
    int stat = 0;
    int cnt = 0;
    while(gets(str))
    {
        if(*str == NULL)
        {
            if(cnt)
            {
                int ans = 0;
                if(stat==0) puts("None.");
                else
                {
                    for(int i=0;i<cnt;i++)
                    {
                        if (stat >= X[i] && stat <= Y[i] && (stat - X[i])%Z[i] == 0)
                            ans++;
                    }
                    printf("%d %d\n",stat,ans);
                }
                stat = 0;
                cnt = 0;
                continue;
            }
        }
        else 
        {
            sscanf(str, "%d%d%d", &X[cnt], &Y[cnt], &Z[cnt]);
            //printf("%d %d %d\n", X[cnt], Y[cnt], Z[cnt]);
            for(int i=X[cnt];i<=Y[cnt];i+=Z[cnt])
            {
                stat ^= i;
            }
            //cout << stat << endl;
            cnt++;
        }
    }
    if(cnt)
    {
        int ans = 0;
        if(stat==0) puts("None.");
        else
        {
            for(int i=0;i<cnt;i++)
            {
                if (stat >= X[i] && stat <= Y[i] && (stat - X[i])%Z[i] == 0)
                    ans++;
            }
            printf("%d %d\n",stat,ans);
        }
    }
    //system("pause");
}

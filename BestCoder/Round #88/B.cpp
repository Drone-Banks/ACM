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

int T;
int n;
int S[112345];
map<int ,int > M;
int Count[112345];
int main()
{
    cin >> T;
    while(T--)
    {
        scanf("%d", &n);
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d", &x);
            if(M[x] == 0)
            {
                M[x] = 1;
                Count[cnt++] = x;
            }
            else M[x]++;
        }
        int ans[100005];
        int num = 0;
        for(int i=1;i<n;i++)
        {
            int flag = 0;
            for(int j=0;j<cnt;j++)
            {
                if(M[Count[j]]%i)
                {
                    flag = 1;
                    break;
                }
            }
            if(!flag) ans[num++] = n/i;
        }

        for(int i=num-1;i>=1;i--)
        {
            cout << ans[i] << " ";
        }
        cout << ans[0] <<endl;
    }
    //system("pause");
}
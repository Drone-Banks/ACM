/*************************************************************************
	> File Name: B.cpp
	> Author: Akira
	> Mail: qaq.febr2.qaq@gmail.com
	> Created Time: 2017年03月18日 星期六 13时50分49秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<cmath>
#include<vector>
#include<set>
#include<list>
#include<ctime>
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
const int mod = 1e9+7;
const int eps = 1e-8;
#define bug cout << 88888888 << endl;

int T;
int N,C0,C1,N0,N1;
char str[100010];
struct Node
{
    int id;
    int l0,r0;
    int l1,r1;
}a[100010];
int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d%d%d", &N, &C0, &C1, &N0, &N1);
        scanf("%s", str+1);
        int cnt = 0;
        for(int i=1;i<=N;i++)
        {
            if(str[i]=='?')
            {
                a[cnt].id = i, a[cnt].l0 = 0, a[cnt].r0 = 0, a[cnt].l1 = 0, a[cnt].r1 = 0;
                cnt++;
            }
        }
        for(int i=0;i<cnt;i++)
        {
            int loc = a[i].id;
            if( str[loc+1] == '1' )
            {
                int j = loc+1;
                while(j<=N && str[j]=='1') 
                {
                    j++;
                    a[i].r1++;
                }
            }
            if(str[loc+1] == '0')
            {
                int j = loc+1;
                while(j<=N && str[j]=='0') 
                {
                    j++;
                    a[i].r0++;
                } 
            }
            if( str[loc-1] == '1' )
            {
                int j = loc-1;
                while(j>=1 && str[j]=='1') 
                {
                    j--;
                    a[i].l1++;
                }
            }
            if(str[loc-1] == '0')
            {
                int j = loc-1;
                while(j>=1 && str[j]=='0') 
                {
                    j--;
                    a[i].l0++;
                } 
            }            
        }
        int ans = 0;
        if(C0<C1)
        {
            for(int i=0;i<cnt;i++)
            {
                if(a[i].l0+a[i].r0+1 < N0)
                {
                    ans += C0;
                    if( a[i+1].id - a[i+1].l0 == a[i].id+1 && i+1<cnt ) a[i+1].l0+=a[i].l0+1;
                }
                else
                {
                    ans += C1;
                    if( a[i+1].id - a[i+1].l1 == a[i].id+1 && i+1<cnt ) a[i+1].l1+=a[i].l1+1;
                }
            }
        }
        else
        {
            for(int i=0;i<cnt;i++)
            {
                if(a[i].l1+a[i].r1+1 < N1)
                {
                    ans += C1;
                    if( a[i+1].id - a[i+1].l1 == a[i].id+1 && i+1<cnt ) a[i+1].l1+=a[i].l1+1;
                }
                else
                {
                    ans += C0;
                    if( a[i+1].id - a[i+1].l0 == a[i].id+1 && i+1<cnt ) a[i+1].l0+=a[i].l0+1;
                }
            }
        }
        printf("%d\n", ans);

    }
}


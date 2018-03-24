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

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

int T;
struct Line
{
    int l,r;
}line[MaxN];
bool cmp(Line a, Line b)
{
    return a.l<b.l;
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        int M;
        scanf("%d", &M);
        int a, b;
        int num = 0;
        while(~scanf("%d%d", &a, &b))
        {
            if(a==0 && b==0) break;
            line[num].l = a;
            line[num++].r = b;
        }
        sort(line, line+num, cmp); 
        vector<Line> V;
        int S = 0;
        int Max = 0;
        int loc = 0;
        int cnt = 0;
        while(S<M && cnt<num)
        {
            int flag = 1;
            while(cnt<num && line[cnt].l<=S)
            {
                if(line[cnt].r>=S)
                {
                    if(Max<=line[cnt].r) 
                    {
                        Max = line[cnt].r;
                        loc = cnt;
                    }
                    flag = 0;
                }
                cnt++;
            }
            if(flag) break;
            S = Max;
            V.push_back(line[loc]);
        }

        if(S<M) cout << 0 << endl;
        else
        {
            cout << V.size()<< endl;
            for(int i=0;i<V.size();i++)
            {
                cout << V[i].l << " "<<V[i].r << endl;
            }
        }
        if(T) cout << endl;
    }
    system("pause");
}
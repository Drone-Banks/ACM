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

#define MaxN 100000
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

template<typename _> inline void scan(_& t)
{
    int c;
    while((c = getchar()) < '0' || c > '9');
    t = c - '0';
    while((c = getchar()) >= '0' && c <= '9') t = t * 10 + c - '0';
}
template<typename _> inline void print(_ x)
{
    int len = 0, p[20];
    if(x < 0) putchar('-'), x = -x;
    while(x) p[++len] = x % 10, x /= 10;
    if(!len) p[++len] = 0;
    while(len) putchar(p[len--] + '0');
}
struct Node
{
    int num;
    char ch;
}node;
int T;
int N;
char Map[501][501];

void solve()
{
    stack<Node> S;
    int cnt = 0;
    int tmp,f1,f2;
    while(cnt<N*N)
    {
        for(int i=N;i>=1;i--)   //行
        {
            if(Map[i][0] == '.') continue;
            f1 = 1;
            for(int j=1;j<=N;j++) 
            {
                if(Map[i][j] == '.') continue;
                if(Map[i][j]!='X')
                {
                    f1 = 0;
                    break;
                }
            }
            if(f1) {tmp=i;break;}
        }
        if(f1)
        {
            for(int j=1;j<=N;j++)
            {
                if(Map[tmp][j]!='.')
                {
                    Map[tmp][j]='.';
                    cnt++;
                }
            }
            node.ch = 'R'; node.num = tmp;
            Map[tmp][0] = '.';
            S.push(node);
            continue;
        }
        for(int j=N;j>=1;j--) //列
        {              
            f2=1;
            if(Map[0][j]=='.') continue;
            for(int i=1;i<=N;i++)
            {
                if(Map[i][j]=='.') continue;
                if(Map[i][j]!='O')
                {
                    f2=0;break;
                }
            }
            if(f2){tmp=j;break;}
        }
        if(f2) 
        {
            for(int i=1;i<=N;i++)
            {
                if(Map[i][tmp]!='.') 
                {
                    Map[i][tmp]='.';
                    cnt++;
                }
            }
            node.ch='C';node.num=tmp;Map[0][tmp]='.';
            S.push(node);
            continue;
        }
        if(!f1&&!f2) break;
    
    }
    //cout << cnt << endl;
    if(cnt<N*N) printf("No solution\n");
    else
    {
        node=S.top();S.pop();
        printf("%c%d",node.ch, node.num);
        while(!S.empty())
        {
            node=S.top();
            S.pop();
            printf(" %c%d",node.ch, node.num);
        }
        printf("\n");
    }
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=N;j++)
            {
                Map[i][j] = 'X';
            }
        }
        for(int i=1;i<=N;i++) scanf("%s", Map[i]+1);
        solve();
    }
    //system("pause");
}

/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 6666
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
int sx,sy,tx,ty;

int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
 
    for(int i=ty-sy;i;--i)putchar('U');
    for(int i=tx-sx;i;--i)putchar('R');
 
    for(int i=ty-sy;i;--i)putchar('D');
    for(int i=tx-sx;i;--i)putchar('L');
 
    putchar('L');
    for(int i=ty-sy;i;--i)putchar('U');
    putchar('U');
    putchar('R');
    for(int i=tx-sx;i;--i)putchar('R');
    putchar('D');
 
    putchar('R');
    for(int i=ty-sy;i;--i)putchar('D');
    putchar('D');
    putchar('L');
    for(int i=tx-sx;i;--i)putchar('L');
    putchar('U');
    puts("");
    system("pause");
}

//UURD DLLU UURRDR DDDLLU
//LUURDDRUUULLDLDDDRRU

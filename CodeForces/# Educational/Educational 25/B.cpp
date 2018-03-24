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
#define ALL(a) a.begin(), a.end()
using namespace std;

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
inline int max2(int a, int b) {return ((a > b)? a : b);}
inline int min2(int a, int b) {return ((a < b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}
inline int min3(int a, int b, int c) {return min2(a, min2(b, c));}

int n;
char str[11][11];
//O
bool check(int x, int y)
{
    int cnt=0,num=0;
    for(int i=0;i<=4 && y+i<=10;i++)
    {
        if(str[x][y+i]=='X') cnt++;
        else if(str[x][y+i]=='O') 
        {
            cnt = 0;
            break;
        }
        else num++;
    }
    if(cnt>=4 && num==1) return true;

    cnt = 0,num=0;
    for(int i=0;i<=4 && x+i<=10 && y+i<=10;i++)
    {
        if(str[x+i][y+i]=='X') cnt++;
        else if(str[x+i][y+i]=='O') 
        {
            cnt = 0;
            break;
        }
        else num++;
    }
    if(cnt>=4 && num==1) return true;
    
    cnt = 0,num=0;
    for(int i=0;i<=4 && x+i<=10;i++)
    {
        if(str[x+i][y]=='X') cnt++;
        else if(str[x+i][y]=='O') 
        {
            cnt = 0;
            break;
        }
        else num++;
    }
    if(cnt>=4 && num==1) return true;

    cnt = 0,num=0;
    for(int i=0;i<=4 && x+i<=10 && y-i>=1; i++)
    {
        if(str[x+i][y-i]=='X') cnt++;
        else if(str[x+i][y-i]=='O') 
        {
            cnt = 0;
            break;
        }
        else num++;
    }
    if(cnt>=4 && num==1) return true;

    return false;
}

void solve()
{
    bool flag = true;
    for(int i=1;i<=10 && flag;i++)
    {
        for(int j=1;j<=10 && flag;j++)
        {
            if(  check(i,j)) 
            {
                //debug(i)debug(j)
                flag = false;
            }
        }
    }
    if(flag) puts("NO");
    else puts("YES");
}
int main()
{
    //std::ios::sync_with_stdio(false);
    
    for(int i=1;i<=10;i++)
    {
        scanf("%s", str[i]+1);
    }
    solve();
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

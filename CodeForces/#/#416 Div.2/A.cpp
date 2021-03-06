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
template<typename T> T abs(T val){return val>0?val:-val;}

int a,b;
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &a, &b))
    {
        bool flag = true;
        int cnt = 1;
        int ans;
        while( a>=0 && b>=0)
        {
            if(flag)
            {
                if(a>=cnt) a-=cnt;
                else
                {
                    ans = 1;
                    break;
                }
            }
            else
            {
                if(b>=cnt) b-=cnt;
                else
                {
                    ans = 2;
                    break;
                }
            }
            cnt++;
            flag^=1;
        }
        if(ans==1) puts("Vladik");
        else puts("Valera");
    }
    //system("pause");
}
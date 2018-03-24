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

#define MaxN 300001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
int n;
char op[10];
int S[MaxN],top;
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &n);
    n = 2*n;
    top = 0;
    int num;
    int need = 1;
    int ans = 0;
    bool flush = false;
    while(n--)
    {
        scanf("%s", &op);
        if(op[0]=='a')
        {
            scanf("%d", &num);
            if(flush) flush = false;
            S[top++] = num;
        }
        else
        {
            if(flush) need++;
            else
            {
                if(top>0)
                { 
                    if( S[top-1]==need)
                    {
                        top--;
                        need++;
                    }
                    else
                    {
                        top = 0;
                        flush = true;
                        need++;
                        ans++;
                    }
                }
                else need++;
            }
        }
        //cout << need << endl;
    }
    printf("%d\n", ans);
    system("pause");
}

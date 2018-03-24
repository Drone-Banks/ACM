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

int x_1,y_1,x_2,y_2,x,y;

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d%d%d%d%d", &x_1, &y_1, &x_2, &y_2, &x, &y))
    {
        int detx = abs(x_1-x_2), dety = abs(y_1-y_2);
        if( detx%x !=0 || dety%y !=0) puts("NO");
        else
        {
            int numx = detx/x,  numy = dety/y;
            //debug(numx) debug(numy)
            if( numx%2 == numy%2) puts("YES");
            else puts("NO");
        }

    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

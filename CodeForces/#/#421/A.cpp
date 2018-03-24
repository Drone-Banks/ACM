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
inline int max2(int a, int b) {
	return ((a > b)? a : b);
}
inline int max3(int a, int b, int c) {
	return max2(a, max2(b, c));
}

int c,v0,v1,a,l;
int main()
{
    //std::ios::sync_with_stdio(false);
        while(~scanf("%d%d%d%d%d", &c,&v0,&v1,&a,&l))
    {
        int ans = v0;
        int t =1;
        bool flag = true;
        while(ans<c)
        {
            if(flag && v0+t*a >=v1) flag = false;
            if(flag) ans += (v0+t*a)-l;
            else ans += v1-l;
            t++;
        }
        printf("%d\n", t);
        



    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

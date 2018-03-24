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

int num[12] ={9,19,199,1999,19999,199999,1999999,19999999,199999999,1999999999,19999999999};
int val[12][12];
int main()
{
    //std::ios::sync_with_stdio(false);
    bool flag = true;
    int max_loc = 100;
    int l = 0, int r =10;
    for(int i=1;i<=12;i++)
    {
        for(int j=)
    }
    while(flag)
    {
        while(l<=r)
        {
            int mid = (l+r)/2;
            printf("? %d\n", num[mid]);
            fflush(stdout);
            char ans;
            scanf(" %c", &ans);
            if(ans == 'Y') 
            {
                r = mid-1;
                max_loc = min(mid, max_loc);
            }
            else l = mid+1;
        }
        else
        {

        }
        printf("? %d\n", x);
        fflush(stdout);
        char ans;
        scanf(" %c", &ans);
        if(ans == '>') swap(s[j], s[j+1]);
    }
    printf("! %s\n", s.c_str());
    fflush(stdout);
    return 0;
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

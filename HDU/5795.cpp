/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <iomanip>
#include <sstream>
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

int T,N,S[MaxN];

void init()
{
    int SG[220],vis[220];
    CLR(SG);
    for(int i=1;i<=200;i++)
    {
        CLR(vis);
        for(int x=0;x<i;x++) vis[SG[x]] = 1;
        for(int a=1;a<i;a++)
        {
            for(int b=1;a+b<i;b++)
            {
                vis[SG[a]^SG[b]^SG[i-a-b]] = 1;
            }
        }
        int j;
        for(j=0;vis[j];j++);
        SG[i] = j;
    }
    for(int i=1;i<=200;i++)
    {
        printf("%d: %d\n", i, SG[i]);
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    //init();
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        int ans = 0;
        for(int i=1;i<=N;i++) 
        {
            scanf("%d", &S[i]);
            if(S[i]%8==0) ans^=(S[i]-1);
            else if(S[i]%8==7) ans^=(S[i]+1);
            else ans^=S[i];
        }
        if(ans) puts("First player wins.");
        else puts("Second player wins.");
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

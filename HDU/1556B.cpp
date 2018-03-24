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
using namespace std;

#define MaxN 100002
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}

int N,A[MaxN];
int main()
{
    //std::ios::sync_with_stdio(false);
    while(scanf("%d",&N) && N)
    {
        CLR(A);
        int a,b;
        for(int i=1;i<=N;i++)
        {
            scanf("%d%d",&a,&b); 
            A[a]++; A[b+1]--;
        }
        int ans=0;
        for(int i=1;i<=N;i++)
        {
            ans+=A[i];
            //debug(ans);
            printf("%d%c",ans,i==N?'\n':' ');   
        }
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

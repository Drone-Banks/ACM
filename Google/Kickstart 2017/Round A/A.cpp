/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
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
#include <fstream>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 1001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
#define bug cout<<88888888<<endl;
int T;
LL R,C;
int main()
{
    //std::ios::sync_with_stdio(false);
    //freopen("A-small-attempt0.in","r",stdin);
	//freopen("A.out","w",stdout);
	/********************************************/
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
    {
        LL ans = 0;
        scanf("%lld%lld", &R, &C);
        R-=1;C-=1;
        LL A = min(R,C);
        LL B = max(R,C);
        ans += (A*(A+1)/2)%mod;
        ans = Sqr(ans)
        printf("Case #%d: %lld\n", t, ans);
    }
    /********************************************/
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

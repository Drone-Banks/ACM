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

#define MaxN 1025
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}

int arr[MaxN][MaxN],n,m;
int lowbit(int x )  
{  
    return x & (-x);  
}  
void update(int x ,int y ,int num)  
{  
    for (int i = x ;i <= n ;i += lowbit(i))  
        for (int j = y ; j <= m ;j += lowbit(j) )  
            arr[i][j] += num ;  
}  
int sum(int x ,int y )  
{  
    int ans = 0 ;  
    for (int i = x ;i > 0 ;i -= lowbit(i))  
        for (int j = y ;j > 0 ; j -= lowbit(j))  
            ans += arr[i][j] ;  
    return ans ;  
}  

int main()
{
    //std::ios::sync_with_stdio(false);
    int op;
    while(~scanf("%d", &op))
    {
        int a,b,c,d;
        if(op==0)
        {   
            scanf("%d", &n);
            m = n;
            CLR(arr);
        }
        scanf("%d", &op);
        while(op!=3)
        {            
            if(op==1)
            {
                scanf("%d%d%d", &a, &b, &c);
                a++,b++;
                update(a,b,c);
            }
            else if(op==2)
            {
                scanf("%d%d%d%d", &a,&b,&c,&d);
                a++,b++,c++,d++;
                int ans = sum(c,d) - sum(a-1,d) - sum(c,b-1) + sum(a-1,b-1);
                printf("%d\n" , ans);
            }
            scanf("%d", &op);
        }
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

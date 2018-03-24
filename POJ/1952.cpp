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

#define MaxN 5005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}

int Len[MaxN],Time[MaxN];
int LIS(int arr[],int n)//arr为数列，n为数列长度，数列从0开始。
{
    for(int i=1;i<=n;i++) Len[i]=Time[i]=1; // 初始化len[i](第i天时的最长递减子序列长度) // 初始化tim[i](第i天时的最长递减子序列个数)   
    for(int i=1;i<=n;i++)
    {
        for(int j=i-1;j>0;j--)
        {
            if(arr[i]<arr[j])
            {
                if(Len[i]<Len[j]+1)
                {
                    Len[i] = Len[j]+1;
                    Time[i] = Time[j];
                }
                else if(Len[i] == Len[j]+1)
                {
                    Time[i]+=Time[j];
                }
            }
            else if(arr[i]==arr[j])
            {
                if( Len[i] == 1) Time[i] = 0; // 关键点，若价格相等，则不计算前面的天数了，预防重叠。
                break;
            }
        }
    }
    int len = 0, num = 0; //len为最长长度，num为它的数量
    for(int i=1;i<=n;i++) len = max(len,Len[i]);
    for(int i=1;i<=n;i++) if(Len[i]==len) num+=Time[i];
    printf("%d %d\n",len,num);
}
int n,a[MaxN];
int main()
{
    //std::ios::sync_with_stdio(false);
    int n;
        while(~scanf("%d", &n))
    {
        for(int i=1;i<=n;i++) scanf("%d", a+i);
        LIS(a,n);
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

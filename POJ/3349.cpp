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

#define MaxN 100003
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
int n;
struct Node
{
    int A[10];
}one;
vector<Node> Hash[MaxN+5];
bool flag;
bool check(Node a, Node b)
{
    bool ans = true;
    for(int i=0;i<6&&ans;i++)
    {
        if(a.A[i] != b.A[i]) ans = false;
    }
    return ans;
}
void cal()
{
    sort(one.A,one.A+6);
    int sum = 0;
    for(int i=0;i<6;i++) sum += one.A[i];
    sum = sum%MaxN;
    //debug(sum);
    if(Hash[sum].size()==0) Hash[sum].push_back(one);
    else
    {
        for(int i=0;i<Hash[sum].size() && flag ;i++)
        {
            if(check(one,Hash[sum][i])) 
            {
                flag = false;
            }
        }
        if(flag) Hash[sum].push_back(one);
    }
}
void init()
{
    for(int i=0;i<MaxN;i++) Hash[i].clear();
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &n))
    {
        init();
        flag = true;
        for(int i=0;i<n;i++)
        {
            for(int i=0;i<6;i++) scanf("%d",&one.A[i]);
            if(flag) cal();
        }
        if(flag) puts("No two snowflakes are alike.");
        else puts("Twin snowflakes found.");
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

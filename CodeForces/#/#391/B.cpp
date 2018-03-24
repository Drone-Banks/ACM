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

#define MaxN 100010
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}

int prime[MaxN];

vector<int> prime_factor(int n)
{
    vector<int>  res;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) res.push_back(i);
        while(n%i==0)
        {
            //debug(i)
            n/=i;
        }
    }
    if(n!=1) res.push_back(n);
    return res;
}

int N;
int A[MaxN];

void solve()
{
    int ans = 0;
    CLR(prime);
    prime[1] = 1;
    for(int i=0;i<N;i++)
    {
        vector<int> v = prime_factor(A[i]);
        for(int j=0;j<v.size();j++)
        {
            prime[v[j]]++;
        }
    }
    for(int i=1;i<=100000;i++) ans = max(ans, prime[i]);
    printf("%d\n", ans);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &N))
    {
        for(int i=0;i<N;i++) scanf("%d", A+i);
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

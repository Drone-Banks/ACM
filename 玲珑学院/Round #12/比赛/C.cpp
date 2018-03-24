/*************************************************************************
	> File Name: C.cpp
	> Author: Akira
	> Mail: qaq.febr2.qaq@gmail.com
	> Created Time: 2017年03月18日 星期六 16时35分51秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<cmath>
#include<vector>
#include<set>
#include<list>
#include<ctime>
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
const int mod = 1234321237;
const int eps = 1e-8;
#define bug cout << 88888888 << endl;

int N,G;
int A[MaxN];
int W[MaxN];

int gcd(int a, int b)
{
    return b==0? a : gcd( b, a%b );
}

LL DP[MaxN*100];
vector<int>::iterator it;
void solve()
{
    DP[0] = 1; 
    for(int i=1;i<=N;i++)
    {
        vector<int> GCD;
        for(int k=1;k*k<=A[i];k++)
        {
            if(A[i]%k==0)
            {
                GCD.push_back(k);
                if(k*k<A[i]) GCD.push_back(A[i]/k);
            }
        }
        sort(GCD.begin(),GCD.end());
        vector<int> Times (GCD.size(), 0);
        for(int k=GCD.size()-1;k>=0;k--)
        {
            Times[k] = W[i]/GCD[k];
            for(int l=k+1;l<GCD.size();l++)
            {
                if(GCD[l] % GCD[k] == 0) Times[k] -= Times[l];
            }
        }
        for(int j=G;j>=0;j--)
        {
            DP[j] = 0;
            for( int k=0;k<GCD.size() && GCD[k]<=j;k++)
            {
                DP[j] += DP[j-GCD[k]]*Times[k];
                if(DP[j]>mod) DP[j]%=mod;
            }
        }
    }
    printf("%lld\n", DP[G]);
}

int main()
{
    scanf("%d%d", &N, &G);
    for(int i=1;i<=N;i++) scanf("%d", &A[i]);
    for(int i=1;i<=N;i++) scanf("%d", &W[i]);
    solve();
}


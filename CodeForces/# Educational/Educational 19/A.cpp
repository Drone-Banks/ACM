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
using namespace std;

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;

int n,k;
vector<int> prime_factor(int n)
{
    vector<int>  res;
    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            res.push_back(i);
            n/=i;
        }
    }
    if(n!=1) res.push_back(n);
    return res;
}
void solve()
{
    vector<int> ans = prime_factor(n);
    //debug(ans.size());
    if(ans.size()>=k)
    {
        for(int i=0;i<k-1;i++)
        {
            if(i!=0) printf(" ");
            printf("%d", ans[i]);
        }
        int tmp = 1;
        for(int i=k-1;i<ans.size();i++)
        {
            tmp*=ans[i];
        }
        if(tmp!=1) 
        {
            if(k!=1) printf(" ");
            printf("%d\n", tmp);
        }
    }
    else puts("-1");
}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &k))
    {
        solve();
    }
    //system("pause");
}

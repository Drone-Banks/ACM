/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 212345
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
//从每个点出发直到某个点出发时能走到重点，那么跳出从重点出发计算环内边的个数，然后组合环内边的个数与环外边的个数即可
const int mod  = 1000000007;
int n; 
int A[MaxN];
map<int, int> M; 

int huan[MaxN];

void init()
{
    CLR(huan);
    M.clear();
}


LL multi(LL a, LL b)
{
    LL ret = 1;   
    while(b>0)  
    {      
        if(b&1)
            ret=(ret*a)%mod;     
        a=(a*a)%mod;      
        b>>=1;   
    }   
    return ret;

}

int vis[MaxN];

void Find(int x,int num)
{
    vis[x]  = num;
    int y = A[x];
    if(M[y] && M[y]!=M[x]) return;
    if(M[y] == M[x])
    {
        huan[++huan[0]] = num+1 - vis[y];
        return;
    }
    else
    {
        M[y] = M[x];
        Find(y, num+1);
    }
}


int main()
{
    while(~scanf("%d", &n))
    {
        init();
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &A[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if(M[i]) continue;
            M[i] = i;
            Find(i,0);   
        }
        LL ans = 0;
        LL cnt = 0;
        LL b = 1;
        for(int i=1;i<=huan[0];i++)
        {
            cnt += huan[i]; 
            b *= (( multi(2, huan[i]) - 2) % mod);
            b%=mod;

        }
        
        LL a  = multi(2, n - cnt);
        ans = a * b % mod;
        cout << ans << endl;

    }

    //system("pause");
}
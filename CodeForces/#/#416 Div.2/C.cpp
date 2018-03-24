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

#define MaxN 5005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}

int N;
int A[MaxN];
struct Node
{
    int L,R;
    int sum;
}node[MaxN];
int M[MaxN];
int vis[MaxN];
int DP[MaxN];
void solve()
{
    MST(vis,-1);
    MST(M,-1);
    int cnt = 0;
    for(int i=1;i<=N;i++) 
    {
        if(M[A[i]]==-1) 
        {
            M[A[i]] = cnt;
            node[cnt].L = i;
            node[cnt].sum = 0;
            cnt++;
        }
        int loc = M[A[i]];
        node[loc].R = i;
    }
    for(int i=0;i<cnt;i++)
    {
        for(int j=node[i].L;j<=node[i].R;j++)
        {
            if(vis[A[j]] != i)
            {
                //cout << j << endl;
                node[i].sum^=A[j];
                vis[A[j]] = i;
            }
        }
        //cout << node[i].L << " - " << node[i].R << ": " << node[i].sum << endl;
    }
    CLR(DP);
    for(int i=1;i<=N;i++)
    {
        int loc = M[A[i]];
        if( node[loc].R<=i ) 
        {
            DP[i] = max(DP[i-1], DP[node[loc].L-1]+node[loc].sum);
        }
        else DP[i] = DP[i-1];
    }
    printf("%d\n", DP[N]);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &N))
    {
        for(int i=1;i<=N;i++) scanf("%d", &A[i]);
        solve();
    }
}
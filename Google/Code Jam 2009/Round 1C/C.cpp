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

#define MaxN 110
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x;
int P,Q,A[MaxN];
int DP[MaxN][MaxN];
int DFS(int s, int t)
{
    if(DP[s][t]!=-1) return DP[s][t];
    else
    {
        if(t-s==1) return DP[s][t]=0;
        int cnt  = INF;
        int cost = (A[t]-A[s])-2;
        for(int i=s+1;i<t;i++)
        {
            int tmp = cost+DFS(s,i)+DFS(i,t);
            cnt = min(cnt, tmp);
        }
        //cout << s << " " << t << " "<< cnt << endl;
        return DP[s][t] = cnt;
    }
}
void solve(int t)
{
    MST(DP,-1);
    A[0] = 0;
    A[Q+1] = P+1;
    sort(A,A+Q+1);
    int ans = DFS(0,Q+1);
    printf("Case #%d: %d\n", t, ans);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    freopen("C-large-practice.in","r",stdin);
	freopen("C.out","w",stdout);
	/********************************************/
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d", &P, &Q);
        {
            for(int i=1;i<=Q;i++) scanf("%d", A+i);
            if(Q==1)
            {
                printf("Case #%d: %d\n", t, P-1);
            }
            else solve(t);
        }   
    }
    /********************************************/
    fclose(stdin);
    fclose(stdout);
    system("pause");
}

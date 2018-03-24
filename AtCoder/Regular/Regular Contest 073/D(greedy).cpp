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

int N;
LL W;
LL w[MaxN], v[MaxN];
vector<LL> V[4];

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%lld", &N, &W))
    {
        for(int i=1;i<=N;i++) scanf("%lld%lld", &w[i], &v[i]);
        LL w1 = w[1];
        for(int i=1;i<=N;i++)
        {
            V[w[i]-w1].push_back(v[i]);
        }
        LL s1 = 0, s2 = 0, s3 = 0, s4 = 0, ans = 0;
        for(int i=0;i<4;i++) sort(V[i].begin(), V[i].end(), greater<LL>());

        for(int i=0;i<=V[0].size();i++){
        for(int j=0;j<=V[1].size();j++){
        for(int k=0;k<=V[2].size();k++){
        for(int l=0;l<=V[3].size();l++){
            debug(s1);
            debug(s2);
            debug(s3);
            debug(s4);
            if( i*(w1) + j*(w1+1) + k*(w1+2) + l*(w1+3) <= W ) ans = max(ans, s1+s2+s3+s4);
            if(l<V[3].size()) s4+=V[3][l];
        }
        if(k<V[2].size()) s3+=V[2][k];
        }
        if(j<V[1].size()) s2+=V[1][j];
        }
        if(i<V[0].size()) s1+=V[0][i];
        }
        printf("%lld\n", ans);
    }
    //system("pause");
}

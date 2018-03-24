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
#define debug(x) cout << #x" = " << x;

int N;
LL C,K,T[MaxN];

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%lld%lld", &N, &C, &K))
    {
        for(int i=0;i<N;i++) scanf("%lld", &T[i]);
        sort(T,T+N);
        LL ans = 0;
        for(int i=0;i<N;)
        {
            LL Time = T[i]+K;
            LL cnt = 0;
            ans++;
            //cout << "Time:" <<Time << " : "<< endl;;
            while(T[i]<=Time&&i<N)
            {
                //cout << "#" <<T[i] << endl;
                cnt++;
                if(cnt==C)
                {
                    i++;
                    break;
                }
                i++;
            }
            //cout <<"ans: "<< ans << endl;
        }
        printf("%lld\n", ans);
    }
    //system("pause");
}

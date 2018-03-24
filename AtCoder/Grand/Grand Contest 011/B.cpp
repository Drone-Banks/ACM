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
LL A[MaxN];
LL B[MaxN];
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d", &N))
    {
        for(int i=0;i<N;i++) scanf("%lld", &A[i]);
        sort(A,A+N);
        B[0] = A[0];
        for(int i=1;i<N;i++) B[i] = B[i-1] + A[i];
        int ans = 0;
        for(int i=N-2;i>=0;i--)
        {
            //cout << B[i]*2 << " " << A[i+1] << endl;
            if(B[i]*2>=A[i+1]) ans++;
            else break;
        }
        printf("%d\n", ans+1);
    }
    //system("pause");
}

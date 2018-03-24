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
#define ALL(a) a.begin(), a.end()
using namespace std;

#define MaxN 50005
#define MaxM 1<<17
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
inline int max2(int a, int b) {
	return ((a > b)? a : b);
}
inline int max3(int a, int b, int c) {
	return max2(a, max2(b, c));
}
int n,N,A[MaxN],sum[MaxM],mmax[MaxM],lmax[MaxM],rmax[MaxM];

void build(int n) {  
    N = 1; while(N < n+2) N <<= 1;
    for(int i=1;i<=n;++i) sum[N+i]=mmax[N+i]=lmax[N+i]=rmax[N+i]=A[i];
    for(int i=N-1;i;i--){  
         sum[i]=sum[i<<1]+sum[i<<1|1]; 
        mmax[i]=max3(mmax[i<<1],mmax[i<<1|1],rmax[i<<1]+lmax[i<<1|1]);
        rmax[i]=max2(rmax[i<<1|1], rmax[i<<1]+sum[i<<1|1]);
        lmax[i]=max2(lmax[i<<1], lmax[i<<1|1]+sum[i<<1]);
    }  
}   

int query(int L,int R){  
    int Mmax_left = -INF, Lmax_left = -INF, Rmax_left = -INF, Sum_left = 0;
    int Mmax_right = -INF, Lmax_right = -INF, Rmax_right = -INF, Sum_right = 0;
    for(int s=N+L-1,t=N+R+1; s^t^1; s>>=1,t>>=1){  
        if(~s&1){
            Sum_left+=sum[s^1];  
            Mmax_left=max3(Mmax_left,mmax[s^1],Rmax_left+lmax[s^1]);
            Rmax_left=max2(rmax[s^1],sum[s^1]+Rmax_left);
            Lmax_left=max2(Lmax_left,Sum_left+lmax[s^1]);
        }
        if( t&1){
            Sum_right+=sum[t^1];
            Mmax_right=max3(Mmax_right,mmax[t^1],rmax[t^1]+Lmax_right);
            Rmax_right=max2(Rmax_right,rmax[t^1]+Sum_right);
            Lmax_right=max2(lmax[t^1],sum[t^1]+Lmax_right);
        }  
    }  
    int ans = max3(Mmax_left, Mmax_right, Rmax_left+Lmax_right);
    return ans;  
} 


int main()
{
    int m,l,r;
    while(~scanf("%d", &n))
    {
        for(int i=1; i<=n; i++) scanf("%d", &A[i]);
        build(n);
        scanf("%d", &m);
        while(m--) 
        {
            scanf("%d%d", &l, &r);
            int ans = query(l,r);
            printf("%d\n", ans);
        }
    }
}

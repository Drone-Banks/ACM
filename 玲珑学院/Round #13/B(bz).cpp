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

#define MaxN 300001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
int Q;
LL M;
LL A[MaxN],V[MaxN];
LL COPY[MaxN];
int ans[MaxN];
int L,R;
int COUNT,loc;
LL Power(LL a, LL b) 
{
    if(b<0) return 0;
	LL ans = 1;
	a = a;
	while(b>0)
	{
		if(b % 2 == 1) ans = (ans * a);
		b = b/2;
		a = (a * a);
	}
	return ans;
}
int check(int mid)
{
    for(int i=0;i<(mid-L);i++)
    {
        COPY[i] = A[L+i];
    }
    sort(COPY,COPY+(mid-L));
    LL cnt = 0;
    for(int i=1;i<=(mid-L);i++) cnt += COPY[i-1]*V[i];
    if(cnt>M) return 1;
    else
    {
        COPY[mid-L] = A[mid];
        sort(COPY,COPY+(mid-L+1));
        cnt = 0;
        for(int i=1;i<=(mid-L+1);i++) cnt += COPY[i-1]*V[i];
        if(cnt<=M) return -1;
        else return 0;
    }

}

bool find()
{
    int p = 0;
    while( (L+Power(2,p))<=R && check(L+Power(2,p))<0 ) p++;
    int l = min((LL)R, L+Power(2,p-1)) , r = min((LL)R, L + Power(2,p));
    //cout << l << " - " << r << " :" << p << endl;
    int cnt = -1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        int zz = check(mid);
        if( zz == -1) l = mid+1;
        else if( zz == 1) r = mid-1; 
        else 
        {
            cnt = mid;
            break;
        }
    }
    //cout << l << " - " << r << " :" << cnt << endl; 
    if(cnt==-1) return false;
    else
    {
        //cout << L <<" ->" << cnt << endl;
        ans[cnt] = ++COUNT;
        loc = cnt;
        return true;
    }
}
void solve()
{
    COUNT = 0,loc=1;
    MST(ans,-1);
    L=1,R=Q;
    while( L<=R && find() ) L = loc+1;
    int tmp = 0;
    for(int i=1;i<=Q;i++)
    {
        if(i!=1) printf(" ");
        if(ans[i]!=-1) tmp = ans[i];
        printf("%d", tmp);
    }
    printf("\n");
}
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d%lld", &Q, &M);
    for(int i=1;i<=Q;i++) scanf("%lld", A+i);
    for(int i=1;i<=Q;i++) scanf("%lld", V+i);
    solve();
    //system("pause");
}
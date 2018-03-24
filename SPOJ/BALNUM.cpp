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
int T;
LL L,R;
int digits[20];
LL DP[20][59100];
int three[11] = { 1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049 };

bool check(int status) {  
    for(int i=0;i<=9;++i,status/=3) {  
        if((i&1)==1&&status%3==1) {  
            return false;  
        }  
        if((i&1)==0&&status%3==2) {  
            return false;  
        }  
    }  
    return true;  
} 
LL dfs(int pos,  int stat, bool not_first, bool limit)
{
    if(pos==0) return check(stat);
    if(!limit && DP[pos][stat] != -1) return DP[pos][stat];
    int Max = limit ? digits[pos] : 9;
    LL ans = 0;
    for(int i=0;i<=Max;i++) 
    {
        int tmp = stat / three[i] %3;
		if(!tmp) 
			tmp++;
		else
			tmp = 3 - tmp;
        ans += dfs(pos-1, not_first || i ? stat/three[i+1]*three[i+1] + stat%three[i] + tmp*three[i] : 0, not_first || i,  limit&&(i==digits[pos]) );
    }
    if(!limit) DP[pos][stat] = ans;
    return ans;
}
LL find(LL x)
{
    int pos = 0;
    while(x)
    {
        digits[++pos] = x%10;
        x/=10;
    }
    return dfs(pos, 0, false,true);
}
void solve()
{
    printf("%lld\n", find(R)-find(L-1));
}

int main()
{
    //std::ios::sync_with_stdio(false);
    MST(DP,-1);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld%lld", &L, &R);
        solve();
    }
    //system("pause");
}

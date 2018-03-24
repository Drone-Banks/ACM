#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int T,A,B,C;
int times;
int ans;
const int mod = 1E9+7;
bool Power(LL a, LL b)
{
    bool is_mod = false;
    LL cnt = 1;
    a = a%mod;
    while(b>0 && !is_mod)
    {
        if(b%2==1)
        {
            cnt = (cnt*a);
            if(cnt>mod)
            {
                cnt%=mod;
                is_mod = true;
            }
        }
        b = b/2;
        a = (a*a);
        if(a>mod)
        {
            a%=mod;
            if(b>0) is_mod = true;
        }
    }
    if(is_mod || cnt>=A-1) return true;
    else return false;
}
bool check(int x)
{
    if(Power(times,x))
    {
        ans = min(ans, x);
        return true;
    }
    else return false;
}
void solve()
{
    ans = A;
    int l=1,r=A;
    while(l<=r)
    {
        int mid = (l+r)>>1;
        if( check(mid) ) r = mid-1;
        else l = mid+1;
    }
    printf("%d\n", ans);
}
int main()
{

    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &A, &B, &C);
        if(B==0 || C/B==0)
        {
            puts("-1");
            continue;
        }
        times = C/B+1;
        if(A==0) puts("0");
        else solve();
    }
}
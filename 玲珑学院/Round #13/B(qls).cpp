#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=500005;
ll a[MAXN],v[MAXN],b[MAXN],id[MAXN];
int res[MAXN];
ll check1(int l,int r)
{
    for(int i=l,j=1;i<=r;i++,j++)
        b[j]=a[i];
    sort(b+1,b+(r-l+1)+1);
    ll res=0;
    for(int i=1;i<=r-l+1;i++)
        res+=b[i]*v[i];
    return res;
}
ll check2(int l,int r,int n)
{
    ll res=0;
    for(int i=1,j=1;i<=n;i++)
        if(id[i]>=l && id[i]<=r)
            res+=b[i]*v[j++];
    return res;
}
int main()
{
    int n;
    ll m;
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&v[i]);
    for(int l=1;l<=n;)
    {
        int k=0;
        while(l+(1<<k)-1<=n && check1(l,l+(1<<k)-1)<=m)k++;
        if(check1(l,min(n,l+(1<<k)-1))>m)
        {
            int tl=l,tr=min(n,l+(1<<k)-1),tt=tr-tl+1;
            for(int i=tl,j=1;i<=tr;i++,j++)
                b[j]=a[i],id[j]=i;
            sort(id+1,id+tt+1,[](int x,int y){return a[x]<a[y];});
            sort(b+1,b+tt+1);
            while(tl<tr)
            {
                int tm=(tl+tr)/2;
                if(check2(l,tm,tt)>m)tr=tm;
                else tl=tm+1;
            }
            res[tl]++;
            l=tl+1;
        }
        else break;
    }
    for(int i=1;i<=n;i++)
        res[i]+=res[i-1];
    for(int i=1;i<=n;i++)
        printf("%d%c",res[i]," \n"[i==n]);
    return 0;
}
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int mm=1111;
int f[mm],f1[mm],f2[mm],t[mm],e[mm],p[mm],s[mm],id[mm],q[mm],qw[mm];
int i,j,k,n,d,g;
bool get(int g)
{
    int a,b;
    while((b=getchar())<'0'||b>'9');
    for(a=0;b>='0'&&b<='9';b=getchar())a=a*10+b-'0';
    t[a-1]=g;
    return (b!='\n');
}
bool cmp(int a,int b)
{
    return t[a]<t[b];
}
void CompletePack(int e,int p)
{
    for(int i=0;i<=d;++i)f2[i]=f1[i];
    for(int i=p;i<=d;++i)
    {
        f2[i]=max(f2[i],f2[i-p]+e);
        f[i]=max(f[i],f2[i]);
    }
}
void MultiPack(int s,int e,int p)
{
    int i,j,k,l,r,now,m;
    for(i=0;i<p;++i)
        for(m=(d-i)/p,j=l=0,r=-1;j<=m;++j)
        {
            now=f1[k=j*p+i]-j*e;
            while(l<=r&&qw[r]<=now)--r;
            q[++r]=j,qw[r]=now;
            if(j-q[l]>s)++l;
            f[k]=max(f[k],qw[l]+j*e);
        }
}
int main()
{
    while(~scanf("%d%d",&n,&d))
    {
        for(i=0;i<n;++i)
            t[i]=0,id[i]=i,scanf("%d%d%d",&s[i],&e[i],&p[i]);
        scanf("%d",&g);
        for(i=1;i<=g;++i)while(get(i));
        sort(id,id+n,cmp);
        for(i=0;i<=d;++i)f1[i]=f[i]=-1e8;
        f1[0]=f[0]=0;
        for(i=0;i<n;++i)
        {
            k=id[i];
            if(!s[k]||s[k]*p[k]>=d)CompletePack(e[k],p[k]);
            else MultiPack(s[k],e[k],p[k]);
            if(!t[k]||t[k]!=t[id[i+1]])
                for(j=0;j<=d;++j)f1[j]=f[j];
        }
        if(f[d]>=0)printf("%d\n",f[d]);
        else puts("i'm sorry...");
    }
    return 0;
}

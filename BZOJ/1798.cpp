/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
#include <climits>
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
int N;
LL P;
#define lson l , m , rt<<1
#define rson m+1 , r , rt<<1|1
LL sum[MaxN<<2];
LL add[MaxN<<2];
LL mul[MaxN<<2];
void PushUp(int rt)
{
    sum[rt] = (sum[rt<<1] + sum[rt<<1|1])%P;
}
void PushDown(int rt, int len)
{
    add[rt<<1] = (add[rt<<1]*mul[rt]+add[rt])%P;
    add[rt<<1|1] = (add[rt<<1|1]*mul[rt]+add[rt])%P;

    sum[rt<<1] = ( sum[rt<<1]*mul[rt]+add[rt]*(len-(len>>1)) )%P;
    sum[rt<<1|1] = ( sum[rt<<1|1]*mul[rt]+add[rt]*(len>>1)%P )%P;

    mul[rt<<1] = ( mul[rt<<1]*mul[rt] )%P;
    mul[rt<<1|1] = ( mul[rt<<1|1]*mul[rt] )%P;
    mul[rt] = 1;
    add[rt] = 0;
}
void build(int l, int r, int rt)
{
    mul[rt]=1;
    add[rt]=0;
    if(l==r)
    {
        scanf("%lld", &sum[rt]);
       // if(sum[rt]>P) sum[rt]%=P;
        return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}

LL query(int L, int R, int l, int r, int rt)
{
    if(L<=l && R>=r)
    {
        return sum[rt]%P;
    }
    PushDown(rt,r-l+1);
    int m = (l+r)>>1;
    LL res=0;
    if(L<=m) res=(res+query(L,R,lson))%P;
    if(R>m)  res=(res+query(L,R,rson))%P;
    PushUp(rt);
    return res%P;
}

void Add(int L, int R, LL val, int l, int r, int rt)
{
    if(L<=l && R>=r)
    {
        add[rt]=(add[rt]+val)%P;
        sum[rt]=(sum[rt]+(r-l+1)*(LL)val)%P;
        return ;
    }
    PushDown(rt, r-l+1);
    int m = (l+r)>>1;
    if(L<=m) Add(L,R,val,lson);
    if(R>m)  Add(L,R,val,rson);
    PushUp(rt);
}

void Multiple(int L, int R, LL val, int l, int r, int rt)
{
    if(L<=l && R>=r)
    {
        add[rt]=(add[rt]*val)%P;
        sum[rt]=(sum[rt]*val)%P;
        mul[rt]=(mul[rt]*val)%P;
        return ;
    }
    PushDown(rt, r-l+1);
    int m = (l+r)>>1;
    if(L<=m) Multiple(L,R,val,lson);
    if(R>m)  Multiple(L,R,val,rson);
    PushUp(rt);
}


int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%lld", &N, &P ))
    {
        CLR(add);
        CLR(sum);
        MST(mul,1);
        build(1,N,1);
        int Q;
        scanf("%d", &Q);
        while(Q--)
        {
            int op;
            scanf("%d", &op);
            if(op==2)
            {
                int s,e;
                LL c;
                scanf("%d%d%lld", &s, &e, &c);
                Add(s,e,c,1,N,1);
            }
            else if(op==1)
            {
                int s,e;
                LL c;
                scanf("%d%d%lld", &s, &e, &c);
                Multiple(s,e,c,1,N,1);
            }
            else
            {
                int s,e;
                scanf("%d%d", &s, &e);
                printf("%lld\n", query(s,e,1,N,1));
            }
        }
    }
    //system("pause");
}

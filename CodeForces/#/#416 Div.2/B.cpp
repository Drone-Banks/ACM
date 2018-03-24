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
template<typename T> T abs(T val){return val>0?val:-val;}
int N,Q, A[MaxN],a[20][MaxN];
struct Node
{
    int L,R;
    int mid(){return (L+R)/2;}
    int size(){return (R-L)+1;}
}mer_seg[MaxN*4];

void build(int root, int L, int R, int dep) //建立归并树
{
    mer_seg[root].L = L;
    mer_seg[root].R = R;
    if(L!=R)
    {
        int mid = (L+R)>>1;
        build(2*root,L,mid, dep+1);
        build(2*root+1,mid+1,R, dep+1);
        int i = L, j = mid+1, k=L; 
        while(i<=mid && j<=R)
        {
            if(a[dep+1][i]<a[dep+1][j])
                a[dep][k++] = a[dep+1][i++];
            else 
                a[dep][k++] = a[dep+1][j++];
        }
        while(i<=mid) a[dep][k++] = a[dep+1][i++];
        while(j<=R) a[dep][k++] = a[dep+1][j++]; 
    }
    else
    {
        a[dep][L] = A[L];
    }
}
int ans,x;

void query(int root, int s, int e,int dep) //在[s, e]区间内查询比x小的元素个数，ans负责统计
{
    if(mer_seg[root].L==s && mer_seg[root].R == e) 
    {
        //cout << s << " " << e << endl;
        int cnt = (lower_bound(a[dep]+s, a[dep]+e+1, A[x]) - (a[dep]+s));
        //debug(cnt);
        ans += cnt;
        return ;
    }
    if(e<=mer_seg[root].mid())  query(root*2,s,e,dep+1);
    else if(s>mer_seg[root].mid()) query(root*2+1,s,e,dep+1);
    else
    {
        query(root*2,s,mer_seg[root].mid(),dep+1);
        query(root*2+1,mer_seg[root].mid()+1,e,dep+1);
    }
}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &N, &Q))
    {
        for(int i=1;i<=N;i++) scanf("%d", &A[i]);
        build(1,1,N,1);
        int s,e;
        while(Q--)
        {
            ans = 0;
            scanf("%d%d%d", &s, &e, &x);
            if(x<s || x>e) 
            {
                puts("Yes");
                continue;
            }
            query(1,s,e,1);  
            if(ans == x-s) puts("Yes");
            else puts("No");
        }
    }
    //system("pause");
}
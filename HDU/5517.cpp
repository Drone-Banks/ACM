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
#define mp make_pair
#define pb push_back
using namespace std;

#define MaxN 100005
#define MaxM 1010
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
inline int max2(int a, int b) {return ((a > b)? a : b);}
inline int min2(int a, int b) {return ((a < b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}
inline int min3(int a, int b, int c) {return min2(a, min2(b, c));}
inline void out(LL x) {if(x>9) out(x/10);putchar(x%10+'0');}
template <class T>
inline void read(T &ret) {
	char c; ret=0;
	while((c=getchar())<'0'||c>'9');
	while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
}
typedef pair<int, pair< int, int > >  piii;
int T,n,m,a[MaxN],b[MaxN],c[MaxN],d[MaxN],e[MaxN];
int A[MaxN];
LL num[MaxN];
struct Node
{
    int x, y,id;
    LL num;
    int val;
    Node(){}
    Node(int x, int y, LL num, int val,int id):x(x),y(y),num(num),val(val),id(id){}
    bool operator<(const Node &n) const
    {
        if(val==n.val) 
        {
            if(x==n.x) return y>n.y;
            else return x>n.x;
        }
        else return val>n.val;
    }
};
vector<Node> V;
struct BIT
{
    LL arr[MaxM][MaxM],n,m;
    void init(int n, int m)
    {
        this->n = n;
        this->m = m;
        CLR(arr);
    }
    int lowbit(int x )  
    {  
        return x & (-x);  
    }  
    void update(int x ,int y ,LL num)  
    {  
        for (int i = x ;i <= n ;i += lowbit(i))  
            for (int j = y ; j <= m ;j += lowbit(j) )  
                arr[i][j] += num ;  
    }  
    LL sum(int x ,int y )  
    {  
        LL ans = 0 ;  
        for (int i = x ;i > 0 ;i -= lowbit(i))  
            for (int j = y ;j > 0 ; j -= lowbit(j))  
                ans += arr[i][j] ;  
        return ans ;  
    }  
}bit;

void solve(int t)
{
    bit.init(1005,1005);
    sort(V.begin(), V.end());
    int loc = 0;
    for(int i=0;i<V.size();i++)
    {
        if(i==0) continue;
        if(V[i].val == V[loc].val && V[i].x == V[loc].x && V[i].y == V[loc].y )
        {
            V[loc].num+=V[i].num;
        }
        else loc = i;
    }

    LL ans = 0;
    for(int i=0;i<V.size();i++)
    {
        int x = V[i].x, y = V[i].y;
        LL sum = bit.sum( x, y );
        bit.update(x , y, 1);
        if(sum==0) 
        {
            ans += V[i].num;
        }
    }
    printf("Case #%d: %lld\n", t, ans);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    read(T);
    for(int t=1;t<=T;t++)
    {
        read(n); read(m);
        CLR(A);CLR(num);V.clear();
        for(int i=1;i<=n;i++) 
        {
            read(a[i]); read(b[i]);
            if(A[b[i]] < a[i])
            {
                A[b[i]] = a[i];
                num[b[i]] = 1; 
            }
            else if(A[b[i]] == a[i]) num[b[i]]++;
        }
        for(int i=1;i<=m;i++) 
        {
            read(c[i]); read(d[i]); read(e[i]);
            if(A[e[i]]==0) continue;
            int x = 1005-c[i]+1, y = 1005-d[i]+1;
            V.pb(Node(x,y,num[e[i]],A[e[i]],e[i]));
        }
        solve(t); 
    }
    //system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}


//AC
#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#define lson d*2,l,mid
#define rson d*2+1,mid+1,r
#define ll long long
using namespace std;

struct node2{
	int a,c,d;
	ll num;
}pos[100011];

bool cmp(node2 x,node2 y)
{
    if(x.a==y.a)
    {
        if(x.c==y.c) return x.d>y.d;
        else if(x.d==y.d) return x.c>y.c;
        else return x.c>y.c;
    }
    else return x.a>y.a;
}
int visit[100011];
ll a[1014][1014];
int lb(int k)
{
	return k&(-k);
}
void add(int x,int y,int v)
{
	for(int i=x;i<=1010;i+=lb(i))
	{
		for(int j=y;j<=1010;j+=lb(j))
		{
			a[i][j]+=v;
		}
	}
 } 
ll sum(int x,int y)
 {
 	ll re=0;
 	for(int i=x;i>0;i-=lb(i))
 	{
 		for(int j=y;j>0;j-=lb(j))
 		{
 			re+=a[i][j];
		 }
	 }
	 return re;
 }
 
 int num[100011],aa[100011],b[100011];
 int main()
 {
 	int t,n,m,cas=1,c,d,e;
 	scanf("%d",&t);
 	while(t--)
 	{
 		scanf("%d%d",&n,&m);
 		
 		memset(visit,-1,sizeof(visit));
 		for(int i=1;i<=n;i++)
 		{
 			scanf("%d%d",&aa[i],&b[i]);
 			aa[i]++;b[i]++;
 			if(visit[b[i]]<aa[i]) visit[b[i]]=aa[i];
		 }
		 memset(num,0,sizeof(num));
		 for(int i=1;i<=n;i++)
		 {
		 	if(visit[b[i]]==aa[i]) num[b[i]]++;
		 }
		 int cnt=0;
		 for(int i=1;i<=m;i++)
		 {
		 	scanf("%d%d%d",&c,&d,&e);
		 	c++,d++,e++;
		 	if(visit[e]!=-1)
		 	{
		 		pos[cnt].a=visit[e];
		 		pos[cnt].c=c;
		 		pos[cnt].d=d;
		 		pos[cnt].num=num[e];
		 		cnt++;
			 }
		 }
		 sort(pos,pos+cnt,cmp);
		 memset(a,0,sizeof(a));
		 ll ans=0,po=0;
		 for(int i=1;i<cnt;i++)
		 {
		 	if(pos[i].a==pos[po].a&&pos[i].c==pos[po].c&&pos[i].d==pos[po].d)
		 	{
		 		pos[po].num+=pos[i].num;
			 }
			 else po=i;
		 }
		 for(int i=0;i<cnt;i++)
		 {
		 	if(sum(1003-pos[i].c,1003-pos[i].d)==0) 
			 {
			 	ans+=pos[i].num;
			 	//cout<<pos[i].a<<" "<<pos[i].c<<" "<<pos[i].d<<endl;
			 }
		 	add(1003-pos[i].c,1003-pos[i].d,1);
		 }
		 printf("Case #%d: %I64d\n",cas++,ans);
	 }
 }
 

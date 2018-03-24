/*************************************************************************
> File Name: test.cpp
> Author: Akira 
> Mail: qaq.febr2.qaq@gmail.com 
************************************************************************/

#pragma comment(linker, "/STACK:102400000,102400000")
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

#define MaxN 200005
#define MaxM MaxN*10
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
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}

int n,m,a[100001],b[200001];

struct Chairmantree
{
    struct Node{
        int l,r,lc,rc,cnt;
        Node(){}
        Node(int l, int r):l(l),r(r){this->lc = this->rc = this->cnt = 0;}
    }ch[3522000];
    int n, tot, root[MaxN];

    void pushDown(int rt){
        const int l = ch[rt].l, r = ch[rt].r;
        if(ch[rt].lc && ch[rt].rc) return;
        const int mid = l + ((r-l)>>1);
        if(!ch[rt].lc)
        {
            ch[rt].lc = ++tot;
            ch[ch[rt].lc] = Node(l, mid);
        }
        if(!ch[rt].rc)
        {
            ch[rt].rc = ++tot;
            ch[ch[rt].rc] = Node(mid+1, r);
        }
    }

    void insert(int &now, const int pre, const int num)
    {
        const int l = ch[pre].l, r = ch[pre].r;
        if(num < l || num > r) return ;
        else if(num == l && l == r)
        {
            ch[now=++tot] = ch[pre], ch[now].cnt++;
        }
        else
        {
            const int mid = l + ((r-l)>>1);
            pushDown(pre);
            if(num <= mid)
            {
                ch[now=++tot] = ch[pre], ch[now].cnt++;
                insert(ch[now].lc, ch[pre].lc, num);
            }
            else
            {
                ch[now=++tot] = ch[pre], ch[now].cnt++;
                insert(ch[now].rc, ch[pre].rc, num);
            }
        }
    }

    int rank(int node) const{
        int lc = ch[node].lc;
        return lc ? ch[lc].cnt : 0;
    }

    void build(const int a[], const int n)
    {
        this-> n = n, this->tot = 0;
        CLR(root);
        ch[0] = Node(0, n-1);
        for(int i=1;i<=n;i++) 
            insert(root[i], root[i-1], a[i]);
    }

    int query(const int l, const int r, const int x)
    {
        int L = root[l-1], R = root[r];
        int min = 0, max = n-1, tmp = 0;
        while(min!=max)
        {
            pushDown(L), pushDown(R);
            int mid = min + ((max-min)>>1), t = rank(R) - rank(L);
            if( mid <= x) tmp += t, L = ch[L].rc, R = ch[R].rc, min = mid+1;
            else L = ch[L].lc, R = ch[R].lc, max = mid;
        }
        return tmp;
    }
}tree;
struct Query
{
    int l,r,h;
}q[100001];

int main()
{
    //std::ios::sync_with_stdio(false);
    int T,l,r,h;
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d", &n, &m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d", &q[i]. l, &q[i].r, &q[i].h);
            b[n+i] = q[i].h;
        }
        int nn = n+m;
        static int set[200001];
        copy(b,b+nn,set);
        sort(set,set+nn);
        int *end = unique(set,set+nn);
        for(int i=1;i<=n;i++) a[i] = lower_bound(set,end,a[i]) - set;
        tree.build(a,nn);
        for(int i=1;i<=m;i++)
        {
            l = q[i].l, r = q[i].r, h = q[i].h;
            int loc = lower_bound(set,end,h)-set;
            // debug(loc)
            int ans = tree.query(l+1,r+1,loc);
            printf("%d\n", ans);
        }
    }
}

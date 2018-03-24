/*************************************************************************
> File Name: test.cpp
> Author: Akira 
> Mail: qaq.febr2.qaq@gmail.com 
************************************************************************/
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

#define MaxN 400005
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

struct ChairmanTree {
    struct Node {
        int l, r, lc, rc, cnt;
        Node(){}
        Node(int l, int r):l(l),r(r){this->lc = this->rc = this->cnt = 0;}
    }ch[MaxN*20];
    int n, tot, root[MaxN];

    void pushDown(int rt) {
        int l = ch[rt].l, r = ch[rt].r;
        if (ch[rt].lc && ch[rt].rc) return;
        int mid = l + ((r - l) >> 1);
        if (!ch[rt].lc) 
        {
            ch[rt].lc = ++tot;
            ch[ch[rt].lc] = Node(l, mid);
        }
        if (!ch[rt].rc) 
        {
            ch[rt].rc = ++tot;
            ch[ch[rt].rc] = Node(mid + 1, r);
        }
    }

    void insert(int &now, const int pre, const int num) {
        int l = ch[pre].l, r = ch[pre].r;
        if (num < l || num > r ) return;
        else if (num == l && num == r) 
        {
            ch[now=++tot] = ch[pre], ch[now].cnt++;
        }
        else 
        {
            const int mid = l + ((r - l) >> 1);
            pushDown(pre);
            if (num <= mid) 
            {
                ch[now=++tot] = ch[pre],ch[now].cnt++;
                insert(ch[now].lc, ch[pre].lc, num);
            }
            else 
            {
                ch[now=++tot] = ch[pre],ch[now].cnt++;
                insert(ch[now].rc, ch[pre].rc, num);
            }
        }
    }

    int rank(int node) const {
        int lc = ch[node].lc;
        return lc ? ch[lc].cnt : 0;
    }

    void build(const int a[], const int n) {
        this->n = n;
        this->tot = 0;
        CLR(root);
        ch[0] = Node(0, n-1);
        for (int i = 1; i <= n; i++) {
            insert(root[i], root[i-1], a[i-1]);
        }
    }

    int query(const int l, const int r, int k) {
        int L = root[l - 1], R = root[r];
        int min = 0, max = n - 1;
        while (min != max) {
             pushDown(L), pushDown(R);
            int mid = min + ((max - min) >> 1), t = rank(R) - rank(L);
            if (k <= t) 
                L = ch[L].lc, R = ch[R].lc, max = mid;
            else 
                k -= t, L = ch[L].rc, R = ch[R].rc, min = mid + 1;
        }
        return min;
    }

    int ask(const int l, const int r, const int x)
    {
        int L = root[l-1], R = root[r];
        int min = 0, max = n - 1;
        int tmp = 0;
        while(min != max)
        {
            pushDown(L), pushDown(R);
            int mid = min + ((max-min)>>1), t = rank(R) - rank(L);
            if( mid <= x) tmp += t, L = ch[L].rc, R = ch[R].rc, min = mid+1;
            else L = ch[L].lc, R = ch[R].lc, max = mid;
        }
        return tmp;
    }
} t;



int n, m, a[MaxN];
struct Q
{
    int l,r,x,k1,k2;
}q[MaxN];

int main() 
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d%d%d",&q[i].l,&q[i].r,&q[i].x,&q[i].k1,&q[i].k2);
        //a[n+i] = q[i].x;
    }
    // n = n+m;
    static int set[MaxN];
    std::copy(a, a + n, set);
    std::sort(set, set + n);
    int *end = std::unique(set, set + n);
    for (int i = 0; i < n; i++) a[i] = std::lower_bound(set, end, a[i]) - set;
 
    t.build(a, n);

    for (int i = 0; i < m; i++) {
        int l=q[i].l, r=q[i].r, x=q[i].x, k1=q[i].k1, k2=q[i].k2;
        int ans1 = -1, ans2 = -1, tmp, loc = std::lower_bound(set, end, x) - set;
        tmp = t.ask(l, r, loc);
        // debug(tmp);
        if(tmp>=k1)
        {
            int pos = t.query(l, r, k1);
            ans1 = set[pos];
        }
        
        if( tmp+k2 <= (r-l+1) )
        {
            int pos = t.query(l, r, tmp+k2);
            ans2 = set[pos];
        }
        printf("%d %d\n", ans1, ans2);
    }
    // system("pause");
    return 0;
}

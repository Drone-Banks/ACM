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

int N,M;
struct Node
{
    static Node Treap[MaxN], *ptr;
    Node *l, *r;
    int key, prio, size;
    LL Msum, Lsum, Rsum, sum, val;
    Node(){}
    Node(int _key, LL _val):
        l(0), r(0), prio(rand()), size(1), key(_key), val(_val), sum(_val), Msum(_val), Lsum(_val), Rsum(_val) {}
}Node::Treap[MaxN], *Node::ptr = Node::Treap, *root;

inline int size(Node *n){return n?n->size:0;}
inline LL sum(Node*n){return n?n->sum:0;}
inline LL Msum(Node*n){return n?n->Msum:INT_MIN;}
inline LL Lsum(Node*n){return n?n->Lsum:0;}
inline LL Rsum(Node*n){return n?n->Rsum:0;}
inline Node* make(int key, LL val) {return new (Node::ptr++) Node(key, val);}
void update(Node *n) 
{
    if(n) 
    {
        n->size = 1+size(n->l)+size(n->r);
        n->sum = sum(n->l)+sum(n->r)+ n->val;
        n->Msum = max3( max2(Rsum(n->l),0) + max2(Lsum(n->r),0) + n->val,
                        max2(Msum(n->l), Msum(n->r)),
                        n->val );
        n->Lsum = max2(Lsum(n->l), sum(n->l)+n->val+max2(Lsum(n->r),0) );
        n->Rsum = max2(Rsum(n->r), sum(n->r)+n->val+max2(Rsum(n->l),0) );
    }
}

void merge(Node *&n, Node *a, Node *b) 
{
    if(!a||!b) n=a?a:b;
    else if(a->prio < b->prio)
    {
        //push(a);
        merge(a->r, a->r, b); 
        update(a);
        n = a;
    }
    else 
    {
        //push(b); 
        merge(b->l,a,b->l);
        update(b);
        n = b;
    }
}

void split(Node *n, Node *&a, Node *&b, int key)
{
    if(!n) return void(a=b=0);
    int cnt = size(n->l);
    if(cnt < key)
    {
        a=n;
        //push(a);
        split(n->r, a->r, b, key-cnt-1);
        update(a);
    }
    else 
    {
        b=n;
        //push(b);
        split(n->l, a, b->l, key);
        update(b);
    }
}

void insert(int key, LL val)
{
    Node *x = make(key, val);
    Node *a, *b; 
    split(root, a, b, key-1);
    merge(a, a, x);
    merge(root,a,b);
}
void remove(int key)
{
    Node *a,*b,*t; 
    split(root,a,b,key-1);
    split(b,t,b,1);
    merge(root,a,b);
}
void replace(int key, LL val)
{
    Node *x = make(key, val);
    Node *a, *b, *t;
    split(root, a, b,key-1);
    split(b,t,b,1);
    merge(a,a,x);
    merge(root,a,b);
}
LL find(int l, int r, Node *n=root)
{
    if(!n) return -1;
    Node *a, *b, *t;
    split(root, a, b, l-1);
    split(b, b, t, r-l+1);
    LL ans = Msum(b);
    merge(b,b,t);
    merge(root,a,b);
    return ans;     
}

int main()
{
    //std::ios::sync_with_stdio(false);
    cin >> N;
    LL x;
    for(int i=1;i<=N;i++)
    {
        cin >> x;
        merge(root, root, make(i,x));
    }
    cin >> M;
    char op;
    int key;
    while(M--)
    {
        cin >> op;
        //debug(op);
        if(op=='I'){
            cin >> key >> x;
            insert(key,x);
        }
        else if( op=='D'){
            cin >> key;
            remove(key);
        }
        else if( op=='R'){
            cin >> key >> x;
            replace(key,x);
        }
        else{
            int a,b;
            cin >> a >> b;
            LL ans = find(a,b);
            cout << ans << endl;
        }
    }
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

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

#define MaxN 2<<22
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
const int MaxQ = 50005;
struct Node;
Node *null;
struct Node 
{
    Node *l, *r;
    int key, prio, size;
    LL val ;
    Node(){}
    Node(int _val):
        l(null), r(null), prio(rand()), size(1), val(_val) {}
}*root[MaxQ], Treap[MaxN];
int ptr = 0, d=0;
inline int size(Node *n) {return n?n->size:0;}
Node* create(Node *t)
{
    if ( t == null ) return t;
    else {
        Node *node;
        node = &Treap[ptr++];
        *node = *t;
        return node;
    }
}
void update(Node * n)
{
    if(n) n->size = size(n->l)+size(n->r)+1;
}
void merge(Node *&n, Node*a, Node*b)
{
    if ( a == null ) {n = create(b);return;}
    if ( b == null ) {n = create(a);return;}
    if( a->prio < b-> prio)
    {
        merge(a->r, a->r, b);
        update(a); 
        n = create(a);
    }
    else
    {
        merge(b->l, a, b->l);
        update(b); 
        n = create(b); 
    }
}
void split(Node *n, Node *&a, Node *&b, int key)
{
    if ( n == null ) { a = b = null; return; }
    int cnt = size(n->l);
    if(cnt < key)
    {
        a=create(n);
        split(n->r, a->r, b, key-cnt-1);
        update(a);
    }
    else 
    {
        b=create(n);
        split(n->l, a, b->l, key);
        update(b);
    }
}
void build(Node *&n, char s[], int l, int r) {
    if ( l > r ) return;
    int mid = (l+r) / 2;
    Node u = Node(s[mid]), *k = &u;
    n = create(k);
    build(n->l, s, l, mid - 1);
    build(n->r, s, mid + 1, r);
    update(n);
}
void travel(Node *n)
{
    if(n==null) return;
    travel(n->l);
    char ch = (char)n->val;
    if(ch=='c') d++; 
    putchar(ch);
    travel(n->r);
}
void print(Node *n, int p, int c)
{
    Node *x, *y;
    split(n, x, n, p-1);
    split(n, n, y, c);
    travel(n);
    puts("");
}

void Insert( Node *&now, Node *pre, int p, char s[])
{
    int len = strlen(s);
    build(now, s, 0, len - 1);
    Node *x, *y;
    split(pre, x, y, p);
    merge(now, x, now);
    merge(now, now, y);
}

void Remove(Node *&now, Node *pre, int p, int c)
{
    Node *x, *y, *z;
    split(pre, x, y, p-1);
    split(y, z, y, c); 
    merge(now, x, y);
}

char str[110];
int N,op,v,p,c,s,vnow=0; 

void init() {
    null = &Treap[ptr++];
    null->size = 0;
    for ( int i = 0 ; i <= N ; i++ )
        root[i] = null;
}
int main()
{
    scanf("%d", &N);
    init();
    while(N--) 
    {
        scanf("%d", &op);
        if(op==1)
        {
            scanf("%d %s", &p, &str); //在当前版本p位置插入一段字符串
            p-=d; 
            Insert(root[vnow+1], root[vnow], p, str);
            vnow++;
        }
        else if(op==2)
        {
            scanf("%d%d",&p, &c);//在当前版本p位置往后删除c个字符
            p-=d, c-=d; 
            Remove(root[vnow+1], root[vnow], p, c);
            vnow++;
        }
        else
        {
            scanf("%d%d%d", &v, &p, &c);//在v版本p位置往后输出c个字符
            v-=d,p-=d,c-=d;
            print(root[v], p, c);
            //debug(d);
        }
    }
    //system("pause");
}

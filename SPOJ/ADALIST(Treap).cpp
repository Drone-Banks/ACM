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

#define MaxN 600001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
struct Node
{
    static Node Treap[MaxN], *ptr;
    Node *l, *r;
    int key, prio, size;
    LL val, sum, add;
    Node(){}
    Node(int _key, int _val):
        l(0), r(0), prio(rand()), size(1), key(_key), val(_val), sum(_val), add(0) {}
}Node::Treap[MaxN], *Node::ptr = Node::Treap, *root;

inline int size(Node *n){return n?n->size:0;}
inline LL sum(Node*n){return n?n->sum:0;}
inline Node* make(int key, LL val) {return new (Node::ptr++) Node(key, val);}
void update(Node *n) 
{
    if(n) 
    {
        n->size = 1+size(n->l)+size(n->r);
        //n->sum  = sum(n->l)+sum(n->r)+ n->val + n->add;
    }
}
void push(Node *n)
{
    if(n)
    {
        if(n->l) 
            n->l->add += n->add, 
            n->l->sum += size(n->l)*n->add,
            n->l->val += n->add;
        if(n->r)
            n->r->add += n->add,
            n->r->sum += size(n->r)*n->add,
            n->r->val += n->add;
        n->add=0;
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

int find(int key, Node *n=root, int add=0)
{
    if(!n) return -1;
    int cnt = add + size(n->l) + 1;
    if(cnt==key)
        return n->val;
    else if( cnt < key) 
        return find(key, n->r, cnt);
    else 
        return find(key, n->l, add);
}

int main()
{
    //std::ios::sync_with_stdio(false);
    int n,q,a,b,c;
    scanf("%d%d", &n, &q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &a);
        merge(root,root, make(i, a));
    }
    while(q--)
    {
        scanf("%d%d", &a, &b);
        if(a==1)
        {
            scanf("%d", &c);
            insert(b,c);
        }
        else if(a==2) remove(b);
        else printf("%d\n", find(b));
    }
    //system("pause");
}

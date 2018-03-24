/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define pb push_back
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 50005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;

int T,n,m; 
int C[MaxN];

struct Trie
{
    int num = 0;
    struct Node
    {
        int sum;
        int son[2];
    }node[31*MaxN];

    void clear(int n)
    {
        for(int i=0;i<=n*31;i++) node[i].sum = node[i].son[0] = node[i].son[1] = 0;
        num = 0;
    }

    void insert(int v)
    {
        bitset<31> b(v);
        node[0].sum++;
        int u = 0;
        for(int i=30;i>=0;i--)
        {
            int t = b[i];
            if(node[u].son[t]==0) node[u].son[t] = ++num;
            u = node[u].son[t];
            node[u].sum++;
        }
    }

    int find(int p, int q)
    {
        bitset<31> P(p); 
        bitset<31> Q(q);
        int u = 0;
        int ans = 0;
        for(int i=30;i>=0;i--)
        {
            if(Q[i]==0)
            {  
                int loc = node[u].son[P[i]^1];
                if(loc>0) ans+=node[loc].sum;
                u = node[u].son[P[i]];
                if(u==0) break;
            }
            else
            {
                u = node[u].son[P[i]^1];
                if(u==0) break;
            }
            if(i==0) ans += node[u].sum;
        }
        return ans;
    }
}trie;

struct CAL
{
    int a,b,id;
};
vector<CAL> Cal[MaxN];
vector<pair<int,int>> Que;
int ANS[MaxN*2];

void solve()
{
    for(int i=0;i<=n;i++)
    {
        if(i>0) trie.insert(C[i]);
        for(CAL c : Cal[i])
        {
            ANS[c.id] = trie.find(c.a,c.b);
        }
    }
    for(int i=0;i<m;i++)
    {
        printf("%d\n", ANS[Que[i].second] - ANS[Que[i].first]);
    }
}
void init()
{
    Que.clear();
    trie.clear(n);
    for(int i=0;i<=n;i++) Cal[i].clear();
}
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &T);
    while(T--)
    {
        init();
        scanf("%d%d", &n, &m);
        for(int i=1;i<=n;i++) scanf("%d", &C[i]);
        int cnt = 0;
        for(int i=1;i<=m;i++)
        {
            int l,r,a,b; 
            scanf("%d%d%d%d", &l, &r, &a, &b);
            cnt++;
            Cal[l-1].pb({a,b,cnt});
            cnt++;
            Cal[r].pb({a,b,cnt});
            Que.pb({cnt-1,cnt});
        }
        solve();
    }
    //system("pause");
}

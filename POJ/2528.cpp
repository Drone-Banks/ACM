/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <iomanip>
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

#define MaxN 20002
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
map<int,int> M;
int N;
struct Line
{
    int s,e;
}line[MaxN];
struct Node
{
    int L,R;
    int mid(){return (L+R)/2;}
    int col;
}node[MaxN<<2];
void PushDown(int root)
{
    if(node[root].col!=-1)
    {
        node[root<<1].col = node[root<<1|1].col = node[root].col;
        node[root].col = -1;
    }
}
void build(int root, int L, int R)
{
    node[root].L = L, node[root].R = R, node[root].col = -1;
    if(L!=R)
    {
        build(root<<1,   L, node[root].mid() );
        build(root<<1|1, node[root].mid()+1, R);
    }
}
void update(int root, int L, int R, int val)
{
    //debug(root);
    if( L<=node[root].L && node[root].R <= R)
    {
        node[root].col = val;
        return;
    }
    PushDown(root);
    if( L <= node[root].mid() ) update(root<<1,   L, R, val);
    if( R >  node[root].mid() ) update(root<<1|1, L, R, val);
}
bool has[MaxN];
int ans;
void query(int root, int L, int R)
{
    if( node[root].col !=-1 )
    {
        if(!has[node[root].col])  ans++;
        has[node[root].col] = true;
        return;
    }
    if(node[root].L == node[root].R) return;
    if( L <= node[root].mid() ) query(root<<1,   L, R);
    if( R >  node[root].mid() ) query(root<<1|1, L, R);
}
vector<int> V;
void solve()
{
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(),V.end()),V.end());
    for(int i=0;i<V.size();i++) 
    {
        //debug(V[i])
        M[V[i]] = i+1;
    }

    build(1,1,V.size());
    for(int i=0;i<N;i++)
    {
        //debug(i);
        update(1,M[line[i].s], M[line[i].e], i+1);
    }
    ans = 0;
    query(1,1,V.size());
    printf("%d\n", ans);

}
void init()
{
    M.clear();V.clear();CLR(has);
}
int main()
{
    //std::ios::sync_with_stdio(false);
    int T,a,b;
    scanf("%d", &T);
    while(T--)
    {
        init();
        scanf("%d", &N);
        for(int i=0;i<N;i++) scanf("%d%d", &line[i].s, &line[i].e), V.push_back(line[i].s), V.push_back(line[i].e);
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

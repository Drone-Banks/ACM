/* 3398 */
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <deque>
#include <bitset>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>
#include <functional>
#include <iterator>
#include <iomanip>
using namespace std;
//#pragma comment(linker,"/STACK:102400000,1024000")

#define sti                set<int>
#define stpii            set<pair<int, int> >
#define mpii            map<int,int>
#define vi                vector<int>
#define pii                pair<int,int>
#define vpii            vector<pair<int,int> >
#define rep(i, a, n)     for (int i=a;i<n;++i)
#define per(i, a, n)     for (int i=n-1;i>=a;--i)
#define clr                clear
#define pb                 push_back
#define mp                 make_pair
#define fir                first
#define sec                second
#define all(x)             (x).begin(),(x).end()
#define SZ(x)             ((int)(x).size())
#define lson            l, mid, rt<<1
#define rson            mid+1, r, rt<<1|1
#define INF                0x3f3f3f3f
#define mset(a, val)    memset(a, (val), sizeof(a))

typedef struct {
    int v, nxt;
} edge_t;


const int maxv = 10005;
const int inf = 1e5;
const int maxe = maxv * 2;
int head[maxv], l;
edge_t E[maxe];
int dp[maxv][3];
int n;

void init() {
    memset(head, -1, sizeof(head));
    l = 0;
}

inline void addEdge(int u, int v) {
    E[l].v = v;
    E[l].nxt = head[u];
    head[u] = l++;
    
    E[l].v = u;
    E[l].nxt = head[v];
    head[v] = l++;
}

/*
 dp[u][0]表示u作为服务器，那么它的儿子结点可以是服务器或者普通机；
 dp[u][1]表示u是普通计算机，但是fa[u]作为服务器，那么它的儿子结点一定是普通机；
 dp[u][2]表示u和fa[u]都是普通计算机，那么它的其中一个儿子结点是服务器。
*/

void dfs(int u, int fa) {
    int k;
    
    dp[u][0] = 1;
    dp[u][1] = 0;
    dp[u][2] = inf;
    for (k=head[u]; k!=-1; k=E[k].nxt) {
        int& v = E[k].v;
        if (v == fa)
            continue;
        dfs(v, u);
        dp[u][0] += min(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][2];
        dp[u][2] = min(dp[u][2], dp[v][0]-dp[v][2]);
    }
    dp[u][2] += dp[u][1];
}

void solve() {
    dfs(1, 0);
    int ans = min(dp[1][0], dp[1][2]);
    printf("%d\n", ans);
}

int main() {
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
    #endif
    
    int u, v;
    
    while (scanf("%d",&n)!=EOF && n) {
        init();
        rep(i, 1, n) {
            scanf("%d%d",&u,&v);
            addEdge(u, v);
        }
        solve();
        scanf("%d", &n);
        if (n == -1)
            break;
    }
    
    #ifndef ONLINE_JUDGE
        printf("time = %ldms.\n", clock());
    #endif
    
    return 0;
}
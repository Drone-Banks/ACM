#include <bits/stdc++.h>
#define mset(a,b) memset(a,(b),sizeof(a))
#define scan(a) scanf("%d",&a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const int maxn = 90005;
struct suffix_automation {
    int last, tot, pre[maxn << 1], go[maxn << 1][26], step[maxn << 1], size[maxn << 1];
    int new_node(int s) {
        step[++tot] = s;
        pre[tot] = 0;
        mset(go[tot], 0);
        return tot;
    }
    void init() {
        tot = 0, last = new_node(0);
        mset(size,0);
    }
    int idx(char c) {
        return c - 'a';
    }
    void insert(char ch) {
        int c = idx(ch), p = last, cur = new_node(step[p] + 1);
        while (p && !go[p][c])
            go[p][c] = cur, p = pre[p];
        if (!p) pre[cur] = 1;
        else {
            int q = go[p][c];
            if (step[q] == step[p] + 1) pre[cur] = q;
            else {
                int nq = new_node(step[p]+1);
                memcpy(go[nq],go[q],sizeof go[q]);
                pre[nq] = pre[q];
                pre[cur] = pre[q] = nq;
                while(p&&go[p][c]==q)
                    go[p][c] = nq,p = pre[p];
            }
        }
        last = cur;
    }
    int cnt[maxn<<1],ch[maxn<<1][26],edge[maxn<<1][26];
    int get_size(int u){
        if(size[u])return size[u];
        size[u] = 1,cnt[u] = 0;
        for(int i = 0;i<26;++i)
            if(go[u][i]){
                size[u]+=get_size(go[u][i]);
                edge[u][++cnt[u]] = go[u][i];
                ch[u][cnt[u]] = 'a'+i;
            }
        return size[u];
    }
    void solve(char s[],int k){
        int len = 0,u = 1;
        while(k){
            for(int i = 1;i<=cnt[u];++i){
                if(k>size[edge[u][i]])k-=size[edge[u][i]];
                else{
                    s[len++] = ch[u][i];
                    k--;
                    u = edge[u][i];
                    break;
                }
            }
        }
        s[len] = '\0';
        puts(s);
    }
} sam;
char s[maxn],ans[maxn];
int main(){
    int q;
    scanf("%s%d",s,&q);
    sam.init();
    for(int i = 0,len = strlen(s);i<len;++i)
        sam.insert(s[i]);
    sam.get_size(1);
    int k;
    while(q--){
        scan(k);
        sam.solve(ans,k);
    }
    return 0;
}
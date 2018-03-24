#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;
const int maxn = 40000;
const int M = 40000;
const int POW = 16;
int fa[maxn];
char in[maxn][65];
char xx[maxn][65];
char root[65];
struct Edge{
       int to;
       string name;
       bool operator < (const Edge &cmp) const {
          return name < cmp.name;
       }
};
set<Edge> link[maxn];
map<string,int> mp;
string rec[maxn];
string init[maxn];
int tot;
void add(string a,string b) {
    Edge k;
    k.to=mp[b];    k.name=b;
    link[mp[a]].insert(k);
    rec[mp[a]] = a;
}
void print(int u) {
    printf("%s\n",init[u].c_str());
    for(set<Edge>::iterator it=link[u].begin();it!=link[u].end();it++){
        int v=it->to;
        print(v);
    }
}
int d[maxn];
int p[maxn][POW];
void dfs(int u,int fa){  
    d[u]=d[fa]+1;  
    p[u][0]=fa;  
    for(int i=1;i<POW;i++) p[u][i]=p[p[u][i-1]][i-1];  
    for(set<Edge>::iterator it=link[u].begin();it!=link[u].end();it++){  
        int v=it->to;  
        if(v==fa) continue;  
        dfs(v,u);  
    }  
}  
int LCA( int a, int b ){  
    if( d[a] > d[b] ) a ^= b, b ^= a, a ^= b;  
    if( d[a] < d[b] ){  
        int del = d[b] - d[a];  
        for( int i = 0; i < POW; i++ ) if(del&(1<<i)) b=p[b][i];  
    }  
    if( a != b ){  
        for( int i = POW-1; i >= 0; i-- )   
            if( p[a][i] != p[b][i] )       a = p[a][i] , b = p[b][i];  
        a = p[a][0], b = p[b][0];  
    }  
    return a;  
}  

int f[maxn];
int main()
{
    int n,i,j,k,Q;
    char op[10];
    char name[65],name1[65],name2[65];
    while(scanf("%d",&n),n)    
    {
        tot=0;
        mp.clear();
        scanf("%s",in[0]);      strcpy(xx[0],in[0]);    
        mp[xx[0]]=++tot; 
        init[1]=in[0];
        for(i=0;i<=n;i++) link[i].clear();
        f[0] = 0;
        for(i=1;i<n;i++) 
        {
            scanf("%s",in[i]);
            int len=strlen(in[i]);
            int cnt=0;
            for(j=0;j<len;j++) 
            {
                if(in[i][j]=='.') cnt++;
                else break;
            }
            strcpy(xx[i],in[i]+cnt);
            mp[xx[i]]=++tot;
            init[tot]=in[i];
            int pre=f[cnt-1];
            add(xx[pre],xx[i]);
            fa[tot] = mp[xx[pre]];
            f[cnt]=i;
        }
        dfs(1,0);
        scanf("%d",&Q);
        int id1,id2,id,pa;
        while(Q--) 
        {
            scanf("%s",op);
            if(op[0]=='L') 
            {
                print(1);
            } 
            else if(op[0]=='b') 
            {
                scanf("%s",name);
                id=mp[name];
                pa=fa[id];
                if(id==1) printf("1\n");
                else  printf("%d\n",link[pa].size());
            } 
            else 
            {
                scanf("%s%s",name1,name2);
                id1=mp[name1],id2=mp[name2];
                int lca=LCA(id1,id2);
                if(lca==id1 || lca==id2)      printf("%s\n",rec[fa[lca]].c_str());
                else printf("%s\n",rec[lca].c_str());
                
            }
        }
    }
    return 0;
}
    
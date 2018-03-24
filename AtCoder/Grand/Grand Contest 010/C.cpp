#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+6;
int n,a[maxn];
vector<int> E[maxn];
void dfs(int x,int p){
    if(E[x].size() == 1)return;
    long long sum = 0;
    long long mx = 0;
    for(int i=0;i<E[x].size();i++){
        int v = E[x][i];
        if(v==p)continue;
        dfs(v, x);
        sum += a[v];
        mx = max(1ll*a[v], mx);
    }
    if(a[x]>sum||sum>2*a[x]){
        cout<<"NO"<<endl;
        exit(0);
    }
    int k=sum-a[x];
    if(k>sum-mx){
        cout<<"NO"<<endl;
        exit(0);
    }
    a[x]-=k;
}
int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d", &x, &y);
        x--,y--;
        E[x].push_back(y);
        E[y].push_back(x);
    }
    if(n==2){
        if(a[0]==a[1])puts("YES");
        else puts("NO");
        return 0;
    }
    int v=0;
    while(E[v].size() == 1) v++;
    dfs(v, -1);
    if(a[v]==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
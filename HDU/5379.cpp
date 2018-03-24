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

#define MaxN 100001
#define MaxM MaxN*5
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
int T,N; 
const int maxn=1e6+200;
vector<int>G[maxn];
LL fact(int x){
    if(x==0)
        return 1;
    LL ret=1;
    for(int i=2;i<=x;i++){
        ret=((ret%mod)*(i%mod))%mod;
    }
    return ret;
}
LL DFS(int u, int fa)
{
    int lef=0,ulef=0;   //子节点是叶子的个数，子节点不是叶子的个数
    int v;
    LL tmp=0 , ret=1;  //ret保存方案数
    for(int i=0;i<G[u].size();i++){
        v=G[u][i];
        if(v==fa)
            continue;
        if(G[v].size()==1){
            lef++;
        }else{
            ulef++;
            tmp=DFS(v,u);
            //cout << i << " " << tmp << " asf" << endl;
            if(tmp==-1)
                return -1;
            ret=((ret%mod)*(tmp%mod))%mod;
        }
    }
    //cout << lef << "  " << ulef << " " << ret <<endl;
    if(ulef<2){     //如果非叶子子节点个数小于2，叶子节点全排列，树根可以为最大值或最小值（之所以乘2）
        return ((2*ret%mod)*(fact(lef)%mod))%mod;
    }else if(ulef==2){  //如果非叶子子节点等于2，只能让叶子节点全排列
        return ((ret%mod)*(fact(lef)%mod))%mod;
    }else return -1;  //不合法
}
void solve(int t)
{
    LL ans = DFS(1,0);
    if(ans==-1) ans = 0;
    printf("Case #%d: %lld\n",t,ans);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> T;
    for(int t=1;t<=T;t++)
    {
        cin >> N;
        if(N==1){
            printf("Case #%d: 1\n",t);
            continue;
        }
        for(int i=1;i<N;i++)
        {
            int u,v;
            cin >> u>> v;
            G[v].push_back(u);
            G[u].push_back(v);
        }
        solve(t);
        for(int i=0;i<=N;i++)
            G[i].clear();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

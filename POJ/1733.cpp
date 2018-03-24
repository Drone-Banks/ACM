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
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
int Len,N;
map<int,int> M;

int fa[MaxN],dis[MaxN];

int find(int x)
{
    if(x == fa[x]) return x;
    else
    {
        int f = fa[x];
        fa[x] = find(fa[x]);
        dis[x] ^= dis[f];
        return fa[x];
    }
}

bool Union(int x, int y, int val)
{
    int fx = find(x), fy = find(y);
    if(fx == fy)
    {
        //cout << dis[x] << " " << dis[y] << " " << val << endl;
        return (dis[x]^dis[y])==val;
    }
    else
    {
        fa[fx] = fy;
        dis[fx] = dis[y]^dis[x]^val;
        return true;
    }
}

void init()
{
    for(int i=0;i<=N;i++) fa[i] = i, dis[i] = 0;
    M.clear();
}

int main()
{
    std::ios::sync_with_stdio(false);
    int len;
    cin >> len >> N;
    init();        
    int a, b;
    string str;
    bool flag = true;
    int cnt = 1;
    int ans=-1;
    for(int i=1;i<=N;i++)
    {
        cin >> a >> b >> str;
        a-=1;
        if(flag)
        {
            if(M.find(a)==M.end()) M[a] = cnt++;
            if(M.find(b)==M.end()) M[b] = cnt++;
            if(!Union(M[a],M[b],str=="odd"?1:0)) 
            {
                flag = false;
                ans = i-1;
                //cout << "asdfaf"<<a << " " << b << str << endl;
            }
            
        }
    }
    if(ans==-1) ans = N;
    cout << ans << endl;
    system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

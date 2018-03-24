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

int n,t;
struct Node{
    double x,y;
    Node(){}
    Node(double x, double y):x(x),y(y){}
}node[202];
bool vis[202];
double cal(Node a, Node b)
{
    return sqrt(Sqr(a.x-b.x)+Sqr(a.y-b.y));
}
bool check(double dis)
{
    CLR(vis);
    queue<Node> Q;
    vis[1] = 1;
    Q.push(node[1]);
    bool flag = false;
    while(!Q.empty()&&!flag)
    {
        Node tmp = Q.front();
        Q.pop();
        for(int i=1;i<=n&&!flag;i++)
        {
            if( vis[i] || cal(node[i],tmp)>dis) continue;
            else 
            {
                if(i==2) flag = true;
                vis[i] = 1;
                Q.push(node[i]);
            }
        }
    }
    return flag;
}
void solve()
{
    double L = 0.0, R = 1000.0*sqrt(2.0);
    while( (R-L) >= eps)
    {
        double mid = (L+R)/2.0;
        if(check(mid)) R = mid;
        else L = mid;
        //debug(mid)
    }
    cout <<"Scenario #"<<++t<<endl;
    cout<<"Frog Distance = ";
    cout <<setiosflags(ios::fixed) <<setprecision(3)<< R << endl<<endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    t = 0;
    while(cin>>n && n)
    {
        for(int i=1;i<=n;i++) cin >> node[i].x >> node[i].y;
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

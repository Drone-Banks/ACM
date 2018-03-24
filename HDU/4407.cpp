/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
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

#define MaxN 400010
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;

struct Node 
{
    int id,v; 
    Node(){}
    Node(int x , int y) : id(x), v(y){}
};
bool is[MaxN];
vector<int> pr;
vector<Node> change;
void prime()
{
    MST(is,1);
    pr.clear();
    pr.push_back(2);
    is[4] = 0;
    for(int i=3;i<MaxN;i+=2)
        if(is[i])
        {
            pr.push_back(i); 
            for(int j=i+i;j<MaxN;j+=i) is[j] = 0;
        }
}
int gcd(int a, int b)
{
    return b==0 ? a : gcd(b, a%b);
}
int n,m;
LL cal(int x,int y, int p, vector<int> &g )
{
    LL ret = (LL)y*(y+1)/2 - (LL)x*(x-1)/2;

    for (int s=1; s<(1<<g.size()); s++) {
        int cnt = 0;
        LL v = 1;
        for (int i=0; i<g.size(); i++)
            if (s & (1<<i)) {
                cnt++;
                v *= g[i];
            }
        LL k = v*( (1 + y/v)*(y/v)/2 - (1 + (x-1)/v)*((x-1)/v)/2 );

        if (cnt % 2 == 1) ret -= k;
        else ret += k;
    }
    for (int i=0; i<change.size(); i++)
        if (change[i].id >= x && change[i].id<=y) {
            if (gcd(change[i].id, p) == 1)ret -= change[i].id;
            if (gcd(change[i].v, p) == 1) ret += change[i].v;
        }
    return ret;
}
void solve(int x, int y, int p)
{
    vector<int> g;
    int k = p;
    for (int i=0; i<pr.size() && pr[i]<=k; i++)
        if (k % pr[i] == 0) {
            g.push_back(pr[i]);
            while (k % pr[i] == 0) k /= pr[i];
        }
    if(k>1) g.push_back(k);
    printf("%lld\n",cal(x, y, p, g));
}

int main()
{
    //std::ios::sync_with_stdio(false);
    prime();
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        change.clear();
        int op,x,y,p;
        while(m--) 
        {
            scanf("%d", &op);
            if(op==1)
            {
                scanf("%d%d%d", &x, &y, &p);
                solve(x,y,p);
            }
            else 
            {
                scanf("%d%d", &x, &y);
                bool flag = true;
                for(int i=0;i<change.size();i++)
                    if(change[i].id == x)
                    {
                        change[i].v = y;
                        flag = false;
                        break;
                    }
                if(flag) change.push_back(Node(x,y));
            }
        }
    }
    //system("pause");
}


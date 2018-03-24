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

#define MaxN 1010
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
struct Node
{
    int s,e,val;
    Node (){}
    Node (int s, int e, int val):s(s),e(e),val(val){}
    bool operator < (const Node& i) const
	{
		return s < i.s;
	}
}node[MaxN];
int dp[MaxN];
int main()
{
    std::ios::sync_with_stdio(false);
    int N,M,R;
    while(cin >> N >> M >> R)
    {
        int a,b,c;
        for(int i=1;i<=M;i++)
        {
            cin >> a >> b >> c;
            node[i] = Node(a,b+R,c);
        }
        sort(node+1, node+1+M);
        int ans = 0;
        for(int i=1;i<=M;i++)
        {
            dp[i] = node[i].val;
            for(int j=1;j<i;j++)
            {
                if(node[j].e<=node[i].s)
                {
                    dp[i] = max(dp[i], dp[j]+node[i].val);
                }
            }
            //debug(dp[i]);
            ans = max(dp[i],ans);
        }
        cout << ans << endl;
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

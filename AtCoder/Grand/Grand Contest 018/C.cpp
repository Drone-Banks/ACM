/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
#define ALL(a) a.begin(), a.end()
#define mp(a,b) make_pair(a,b)
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
inline int max2(int a, int b) {return ((a > b)? a : b);}
inline int min2(int a, int b) {return ((a < b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}
inline int min3(int a, int b, int c) {return min2(a, min2(b, c));}

int X,Y,Z,N;
struct Node
{
    int A, B, C;
}node[MaxN];

vector< pair<LL,int> > V;
priority_queue< LL > Q;
LL Left[MaxN], Right[MaxN];

void solve()
{
    V.clear();
    for(int i=0;i<N;i++) V.push_back(mp(node[i].A-node[i].B, i));
    sort(ALL(V));   
    
    LL sum = 0;
    while(!Q.empty()) Q.pop();
    for(int i=0;i<Y;i++)
    {
        int id = V[i].second;
        Q.push(node[id].C - node[id].B);
        sum += node[id].B;
    }
    for(int i=Y;i<Y+Z;i++)
    {
        int id = V[i].second;
        Left[i] = sum;
        sum += node[id].B;
        if(Q.top() > (node[id].C - node[id].B))
        {
            sum += Q.top();
            Q.pop();
            Q.push(node[id].C - node[id].B);
        }
        else sum += node[id].C - node[id].B;
    }
    Left[Y+Z] = sum;

    sum = 0;
    while(!Q.empty()) Q.pop();
    for(int i=N-1;i>=Y+Z;i--)
    {
        int id = V[i].second;
        Q.push(node[id].C - node[id].A);
        sum += node[id].A;
    }
    for(int i=Y+Z-1;i>=Y;i--)
    {
        int id = V[i].second;
        Right[i+1] = sum;
        sum += node[id].A;
        if(Q.top() > (node[id].C - node[id].A))
        {
            sum += Q.top();
            Q.pop();
            Q.push(node[id].C - node[id].A);
        }
        else sum += node[id].C - node[id].A;
    }
    Right[Y] = sum;

    LL ans = 0;
    for(int i=Y;i<=Y+Z;i++)
    {
        ans = max(ans, Left[i]+Right[i]);
    }
    printf("%lld\n", ans);


}

int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d%d", &X, &Y, &Z))
    {
        N = X + Y + Z;
        for(int i=0;i<N;i++)
        {
            scanf("%d%d%d", &node[i].A, &node[i].B, &node[i].C);
        }
        solve();
    }
    //system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
}

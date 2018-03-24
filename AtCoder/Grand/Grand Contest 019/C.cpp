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
#define mp make_pair
#define pb push_back
using namespace std;                                                                                              

#define MaxN 400005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
inline int max_2(int a, int b) {return ((a > b)? a : b);}
inline int min2(int a, int b) {return ((a < b)? a : b);}
inline int max3(int a, int b, int c) {return max_2(a, max_2(b, c));}
inline int min3(int a, int b, int c) {return min2(a, min2(b, c));}
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}
struct BIT{
	int n;
	int tree[MaxN];
	void init( int n ){
		this->n = n ;
		CLR(tree);
	}
	
	int lowbit( int x ){
		return x & ( -x );
	}
	
	int sum( int n ){
		int ans = 0;
		for( int i = n; i ; i -= lowbit(i) ){
			ans = ( ans + tree[i] ) % mod ;
		}
		return ans;
	}
	
	void update( int x, int val ){
		for( int i = x; i <= n; i += lowbit( i ) ){
			tree[i] = ( tree[i] + val ) % mod ;
		}
	}
}bit;
int x_1, y_1, x_2, y_2, N;
struct Node
{
    int x, y;
    bool operator<(const Node &a) const
    {
        if(x == a.x) return x<a.x;
        return y<a.y;
    }
}node[MaxN];

vector<Node> V;
vector<int> X;
map<int, int> M;
void solve()
{
    V.clear();X.clear();M.clear();

    int mxx = max(x_1,x_2), mnx = min(x_1,x_2), mxy = max(y_1, y_2), mny = min(y_1,y_2);

    bool flag = true;
    if( (x_1<=x_2 && y_1<=y_2) || ( x_1>=x_2 && y_1>=y_2) ) flag = true;
    else flag = false;
    for(int i=1;i<=N;i++)
    {
        if( mnx <= node[i].x && node[i].x <= mxx && mny <= node[i].y && node[i].y <=mxy)
        {
            Node tmp = node[i];
            if(!flag) tmp.y*=-1;
            V.pb(tmp);
            X.pb(tmp.x);
        }
    }
    sort(V.begin(), V.end());
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()),X.end());
    for(int i=0;i<X.size();i++) M[X[i]] = (i+1);
    
    bit.init(X.size());
    int mx = -1;
    for(int i=0;i<V.size();i++)
    {
        // debug(V[i].x) debug(M[V[i].x])
        int now = M[V[i].x];
        int tmp = bit.sum(now);
        // debug(tmp);
        mx = max(mx, tmp);
        bit.update(now, 1);
    }
    debug(mx)
    // debug(x_1)  debug(y_1)  debug(x_2) debug(y_2)
    LL sum = 1LL*(abs(x_1-x_2)+abs(y_1-y_2))*100;
    double que = 1.0*(mx+1)*(20.0-5.0*acos(-1));
    if(x_1 == x_2 || y_1 == y_2) que = -1.0*(mx+1)*(10.0*acos(-1)-20.0);
    double ans = sum*1.0 - que;
    printf("%.15f\n", ans);
}

int main()
{
    //std::ios::sync_with_stdio(false);
    read(x_1);read(y_1);read(x_2);read(y_2);read(N);
    for(int i=1;i<=N;i++)
    {
        read(node[i].x);read(node[i].y);
    }
    solve();
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

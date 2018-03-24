/*************************************************************************
> File Name: test.cpp
> Author: Akira 
> Mail: qaq.febr2.qaq@gmail.com 
************************************************************************/

//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define pb emplace_back
using namespace std;                                                                                              

#define MaxN 100005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}

int n,m;

struct Node{
    int a, b, id;
    Node(){}
    Node(int a, int b):a(a),b(b){}
    bool operator==(const Node &x) const{
        return (a==x.a && b==x.b && id==x.id);
    }
    bool operator<(const Node &x) const{
        if(a==x.a){
            return b>x.b;
        }
        return a<x.a;
    }
}node[MaxN];

multiset<Node> A;
multiset<Node>::iterator it;
bool over[MaxN];
int cnt[MaxN];
bool cmp(Node x, Node y)
{
    if( x.a>y.a || (x.a==y.a && x.b<y.b)) return true;
    else return false;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &m))
    {
        for(int i=1;i<=n;i++) node[i].id = i, node[i].a = node[i].b = 0;
        A.clear();
        CLR(over);CLR(cnt);
        int x, y,fuck = 0;
        while(m--)
        {
            scanf("%d%d", &x, &y);
            // cout << over[a] << endl;
            if(x==1){
                node[1].a++, node[1].b+=y;
                for( it=A.begin();it!=A.end();)
                {
                    if(!cmp((*it), node[1]) ) {
                        // cout << "daf:" << (*it).id <<endl;
                        if( (*it) == node[(*it).id] ) over[(*it).id] = false;
                        if( cnt[(*it).id] ){
                            cnt[(*it).id]--;
                            fuck--;
                        }
                        it = A.erase(it);
                    }
                    else break;
                }
            }
            else if(over[x]){
                node[x].a++, node[x].b+=y;
                A.insert(node[x]);
                cnt[x]++;fuck++;
            }
            else{
                node[x].a++, node[x].b+=y;
                if(cmp(node[x], node[1])){
                    over[x] = true;
                    A.insert(node[x]);
                }
            }
            // puts("ok");
            // cout << fuck << endl;
            // for(int i=1;i<=n;i++) cout <<i << " " << over[i] << " " << node[i].a <<endl;
            // puts("--");
            // for( Node B : A) cout << B.id << " " << B.a <<endl;
            // puts("end");
            printf("%d\n", A.size()+1-fuck);
        }
    }
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

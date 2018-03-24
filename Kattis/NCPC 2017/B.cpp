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

int n;
struct Node{
    char str[25];
    double a,b;
}node[505];


int main()
{
    // std::ios::sync_with_stdio(false);
    while(~scanf("%d", &n))    
    {
        for(int i=1;i<=n;i++){
            scanf("%s%lf%lf", &node[i].str, &node[i].a, &node[i].b);
        }
        sort(node+1,node+1+n,[](Node x, Node y){
            return x.a<y.a;
        });
        double ans = INF;
        int a,b,c,d;

        for(int j=1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                for(int l=k+1;l<=n;l++)
                {
                    int loc = 1;
                    for(int i=1;i<=n;i++){
                        if(i!=j && i!=k && i!=l) {
                            loc = i;
                            break;
                        }
                    }
                    double val = (node[loc].a + node[j].b + node[k].b + node[l].b); 
                    if( val < ans ){
                        // cout << val <<endl;
                        ans = val;
                        a = loc,b=j,c=k,d=l;
                    }
                }
            }
        }
        
        printf("%.6f\n", ans);
        printf("%s\n%s\n%s\n%s\n", node[a].str, node[b].str, node[c].str, node[d].str);
    }
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}
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
#define pb push_back
using namespace std;                                                                                              

#define MaxN 1000005
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
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}

const int MAXN = 2*1e6 + 8;
const int CH_NUM = 26;
struct SAM{
    int ch[MAXN][CH_NUM], pre[MAXN], MaxLen[MAXN], endpos[MAXN]; 
    int last, tot;
    // root = 1;
    void init(){
        tot = 0;
        last =  newNode();
    }
    int newNode()
    {
        ++tot;
        MST(ch[tot], 0);
        pre[tot] = MaxLen[tot] = 0;
        return tot;
    }
    int extend(int c, int ind){
        int p = last, np = newNode();
        MaxLen[np] = MaxLen[p] + 1; endpos[np] = ind;
        while(p && !ch[p][c]) ch[p][c] = np, p = pre[p];
        if(!p) pre[np] = 1;
        else{
            int q = ch[p][c];
            if(MaxLen[q] != MaxLen[p] + 1){
                int nq = ++tot;
                memcpy(ch[nq], ch[q], sizeof(int)*CH_NUM);
                MaxLen[nq] = MaxLen[p] + 1;
                pre[nq] = pre[q];
                pre[q] = pre[np] = nq;
                while(p && ch[p][c] == q) ch[p][c] = nq, p = pre[p];
            }
            else pre[np] = q;
        }
        last = np;
        return MaxLen[np] - MaxLen[pre[np]];
    }
    /*
    vector<int> sons[2*MAXN];
    void build_the_tree(){
        for(int i = 1; i <= tot; i++){
            sons[pre[i]].push_back(i);
        }
    }
    */
} sam;

int main()
{
    //std::ios::sync_with_stdio(false);
    ios::sync_with_stdio(false); cin.tie(0);  
    string s;
    int n, i;  
    LL sum =0;  
    cin >> s;  
    n = s.size();  
    sam.init();  
    for(i = 0; i < n; i++) sum += sam.extend(s[i] - 'a',i+1);  
    cout << sum << endl;;  
    return 0;  
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

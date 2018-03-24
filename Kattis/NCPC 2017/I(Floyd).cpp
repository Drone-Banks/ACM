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

#define MaxN 505
#define MaxM 1000005
#define INF 9999999
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}
int n;
map<string,int> M;
string name[MaxN];
vector<int> ans;
int Map[MaxN][MaxN],dist[MaxN][MaxN];
int road[MaxN][MaxN];

/**记录最小环的路径*/
void Record(int s,int t)
{
    // cout << s << " " << t<<endl;
    if(road[s][t])
    {
        Record(s,road[s][t]);
        Record(road[s][t],t);
    }
    else ans.pb(t);
}

void Floyd()
{
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    Map[i][j]=dist[i][j];
    
    int i,j,k,val=INF;
    for(k=1;k<=n;k++)
    {
        /**正常floyd部分*/
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    road[i][j]=k;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(val>dist[i][i]) {
            val = dist[i][i];
            ans.clear();
            Record(i,i);
        }
    }
    // debug(val);
    if(val==INF) cout << "SHIP IT" << endl;
    else
    {
        for(int i=0;i<ans.size();i++)
        {
            cout << name[ans[i]] << " \n"[i==ans.size()-1] ;
        }
    }
}

void Init()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dist[i][j]=INF;
            road[i][j]=0;
        }
    }
    M.clear();
}

int main()
{
    std::ios::sync_with_stdio(false);
    while(cin >> n)
    {
        Init();
        int m;
        string str;
        for(int i=1;i<=n;i++) 
        {
            cin >> str;
            M[str] = i;
            name[i] = str;
        }
        int loc = 0;
        for(int i=1;i<=n;i++)
        {
            cin >> str >> m;
            int u = M[str];
            getline(cin,str);
            for(int j=1;j<=m;j++)
            {
                bool flag = false;
                getline(cin, str);
                string name;
                for(int s=0;s<str.length();s++)
                {
                    if(str[s]==' ') 
                    {
                        flag = true;
                        continue; 
                    }
                    if(str[s]==',') 
                    {
                        flag = false; 
                        int v = M[name];
                        if(u!=v) dist[u][v] = 1;
                        else loc = u;
                        name = "";
                        continue;
                    }
                    if(flag)
                    {
                        name+=str[s];
                    }
                }
                int v = M[name];
                if(u!=v) dist[u][v] = 1;
                else loc = u;
            }
        }
        if(loc) cout << name[loc] << endl;
        else Floyd();
    }
    // system("pause");
    //printf("%lld\n", ((x)%mod+mod)%mod );
    //printf("\n%.2lf sec \n", (double)clock() / CLOCKS_PER_SEC);
}

/*
4
a b c d
a 1
i b
b 1
i a, c
c 1
i d
d 1
i a, b

6
a b c d e f
a 1
i b
b 1
i e, c
c 1
i f
d 1
i a
e 1
i d, b
f 1
i e

8
a b c d e f g h
a 1
i b
b 1
i g, c, h
c 1
i f
d 1
i a
e 1
i d, b
f 1
i e
g 1
i e h
h 1
i g
*/
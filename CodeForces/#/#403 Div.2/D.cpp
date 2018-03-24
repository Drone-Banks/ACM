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
using namespace std;

#define MaxN 1005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}

struct Name
{
    string fst, sec;
}name[MaxN];
int n;
map<string,int> M;
int match[MaxN];
bool check[MaxN];
bool DFS(int u)
{
    int a = M[name[u].fst], b = M[name[u].sec];
   // debug(a) debug(b) debug(u) debug(match[u])
    if( match[u] == 0 && ( (a==0) || a!=u && DFS(a) ) )
    {
       //cout << u << " --1" << endl;
        M[name[u].fst] = u;
        match[u] = 1;
        return true;
    } 
    else if( match[u] < 2 && ( (b==0) || b!=u && DFS(b) ) )
    {
       //cout << u << " --2" << endl;
        M[name[u].sec] = u;
        match[u] = 2;
        return true;
    }
    else return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n)
    {
        M.clear();
        CLR(match);
        string str1,str2;
        for(int i=1;i<=n;i++)
        {
            cin >> str1 >> str2;
            name[i].fst = str1[0], name[i].fst += str1[1], name[i].fst += str1[2];
            name[i].sec = str1[0], name[i].sec += str1[1], name[i].sec += str2[0]; 
            //debug(name[i].fst);
        }
        bool flag = true;
        for(int i=1;i<=n && flag;i++)
        {
            for(int j=i+1;j<=n && flag;j++)
            {
                if(name[i].fst == name[j].fst)
                {
                    if( M.find(name[i].fst) == M.end())
                    {
                        int a = M[name[i].sec];

                        if( a==0 ) M[name[i].sec] = i, match[i] = 2;
                        else if(a!=i) flag = false;

                        int b = M[name[j].sec];
                        if( b==0 ) M[name[j].sec] = j, match[j] = 2;
                        else if(b!=j) flag = false;
                    }
                }
            }
        }
        for(int i=1;i<=n && flag;i++)
        {
            if(!match[i])
            {
                //debug(name[i].sec);
                CLR(check);
                if(!DFS(i)) flag = false;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
        if(flag) 
        {
            for(int i=1;i<=n;i++)
            {
                if(match[i]==1) cout << name[i].fst << endl;
                else cout << name[i].sec << endl;
            }
        }
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

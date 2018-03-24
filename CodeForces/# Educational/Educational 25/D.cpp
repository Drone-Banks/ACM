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
using namespace std;

#define MaxN 1000010
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

char s[MaxN], t[MaxN];
int tar[30],num[30],ans[30];
void solve()
{
    int lens = strlen(s), lent = strlen(t);
    if(lens < lent) 
    {
        for(int i=0;i<lens;i++) if(s[i]=='?') s[i] = 'a';
        printf("%s\n", s);
        return;
    }
    CLR(tar);CLR(num);CLR(ans);
    int use = 0;
    for(int i=0;i<lent;i++) tar[t[i]-'a']++;
    for(int i=0;i<lens;i++) 
    {
        if(s[i]=='?') use++;
        else num[s[i]-'a']++;
    }
    bool flag = false;
    while(use)
    {
        for(int i=0;i<26 && use;i++)
        {
            if(num[i]>=tar[i]) 
            {
                num[i]-=tar[i];
            }
            else
            {
                int dis = tar[i]-num[i];
                if(use>=dis)
                {
                    num[i] = 0;
                    ans[i]+=dis;
                    use-=dis;
                }
                else 
                {
                    use = 0;
                    break;
                }
            }
        }
    }
    int loc = 0;
    for(int i=0;i<lens;i++)
    {
        if(s[i]=='?')
        {
            while( ans[loc]==0 && loc<=25) loc++;
           // debug(loc);
            if(loc>25)
            {
                s[i] = 'a'; 
            }
            else
            {
                ans[loc]--;
                s[i] = 'a'+loc;
            }
            
        }
    }
    printf("%s\n", s); 
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%s%s", s, t))
    {
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

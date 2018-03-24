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

#define MaxN 8010
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

string str;
int DP[MaxN];
int Next[MaxN];
int cal(int x){
    int cnt = 0;
    while (x != 0)
        cnt++, x /= 10;
    return cnt;
}
void solve()
{
    MST(DP,INF);
    DP[0] = 0;
    DP[1] = 2; 
    int N = str.length();
    str = ' ' + str;
    for(int i=1; i<=N; i++)
    {
        string s = str.substr(1,i);
        reverse(ALL(s));
        CLR(Next);
        DP[i] = min(DP[i-1]+2, DP[i]);
        for(int j=1;j<i;j++)
        {
            int loc = Next[j-1];
            while(loc>0 && s[j]!=s[loc]) 
                loc = Next[loc-1];
            if(s[j]==s[loc]) loc++;
            Next[j] = loc;

            int len = j+1, length;
            if( len %(len-Next[len-1]) == 0 )
                length = len - Next[len-1];
            else 
                length = len;
            int num = len/length;
            
            DP[i] = min(DP[i], DP[i-j-1]+cal(num) + length);
        }
    }
    cout << DP[N] << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    while(cin >> str)
    {
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

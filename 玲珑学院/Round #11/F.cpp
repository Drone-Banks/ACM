/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
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

#define MaxN 1005
#define MaxM MaxN
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
int N,K;
string S;
const char *Char = "abcdefghijklmnopqrstuvwxyz";
int NEXT[MaxM][26];
int DP[MaxN][MaxM];  
int Next[MaxN*2]; //ex数组即为extend数组
void GETNext(string str)
{
    CLR(Next);
    int i=0,j,po,len=str.length();
    Next[0]=len;//初始化Next[0]
    while(str[i]==str[i+1]&&i+1<len)//计算Next[1]
        i++;
    Next[1]=i;
    po=1;//初始化po的位置
    for(i=2;i<len;i++)
    {
        if(Next[i-po]+i<Next[po]+po)//第一种情况，可以直接得到Next[i]的值
            Next[i]=Next[i-po];
        else//第二种情况，要继续匹配才能得到Next[i]的值
        {
            j=Next[po]+po-i;
            if(j<0)   j=0;//如果i>po+Next[po],则要从头开始匹配
            while(i+j<len&&str[j]==str[j+i])//计算Next[i]
                j++;
            Next[i]=j;
            po=i;//更新po的位置
        }
    }
} 
void solve()
{
    for(int i=0;i<K;i++)
    {
        for(int j=0;j<26;j++)
        {
            string s = S.substr(0,i)+Char[j];
            string str = S+s;
            GETNext(str);
            int l1 = str.length();
            int L = S.length();
            int ans = 0;
            for(int k = L;k<l1;k++)
            {
                int now = Next[k];
                if(k+Next[k] == l1)
                {
                    ans = max(ans , now ) ;
                }
            }
            //cout << ans << endl;
            ans = ans >= L ? L : ans ;
            NEXT[i][j] = ans;
        }
    }
    DP[0][0] = 1;
    for(int i=1;i<K;i++) DP[0][i] = 0;
    //DP
    for(int t=0;t<N;t++)
    {
        for(int i=0;i<K;i++) DP[t+1][i] = 0;
        for(int i=0;i<K;i++)
        {
            for(int j=0;j<26;j++)
            {
                int ti = NEXT[i][j];
                if(ti==K) continue;
                DP[t+1][ti] = (DP[t+1][ti] + DP[t][i])%mod;
            }
        }
    }
    int ans = 0;
    for(int i=0;i<K;i++) ans = (ans + DP[N][i])%mod;
    printf("%d\n", ans);
}

int main()
{
    std::ios::sync_with_stdio(false);
    while(cin >> N >> K)
    {
        cin >> S;
        solve();
    }
    //system("pause");
}

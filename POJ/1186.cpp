/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <iomanip>
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

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
int n,M;
int k[10],p[10];
int x[10][200];
int ans;
const int MAX = 4000000;  
bool used[MAX] = {0};  
struct Hash{  
    int val;  
    int count;  
};  
Hash HashTable[MAX];
int searchHash(int s) {  
    int tmp;  
    tmp = s;  
    while (tmp < 0) tmp += MAX;  
    while (tmp >= MAX) tmp -= MAX;  
    while (used[tmp] && HashTable[tmp].val != s) {  
        tmp++;  
        if (tmp >= MAX)  
            tmp -= MAX;  
    }  
    return tmp;  
}  
  
void insert(int s) {  
    int pos = searchHash(s);  
    HashTable[pos].val = s;  
    used[pos] = 1;  
    HashTable[pos].count++;  
}  
int Pow(int a, int b)
{
    int ans =1;
    for(int i=1;i<=b;i++) ans*=a;
    return ans; 
}
void cal(int num, int base, int op)
{
    switch(num)
    {
    case 1:
        for(int x1=1;x1<=M;x1++)
        {
            int cnt = x[base+1][x1];
            //debug(cnt);
            if(!op) insert(cnt);
            else ans+=HashTable[searchHash(-cnt)].count;
        }
        break;
    case 2:
        for(int x1=1;x1<=M;x1++)
        {
            int cnt = x[base+1][x1];
            for(int x2=1;x2<=M;x2++)
            {
                int cnt2 = cnt+ x[base+2][x2];
                //debug(cnt2);
                if(!op) insert(cnt2); 
                else ans+=HashTable[searchHash(-cnt2)].count;
            }
        }
        break;
    case 3:
        for(int x1=1;x1<=M;x1++)
        {
            int cnt = x[base+1][x1];
            for(int x2=1;x2<=M;x2++)
            {
                int cnt2 = cnt + x[base+2][x2];
                for(int x3=1;x3<=M;x3++)
                {
                    int cnt3 = cnt2 + x[base+3][x3];
                    if(!op) insert(cnt3); 
                    else ans+=HashTable[searchHash(-cnt3)].count;
                }
            }
        }
    }
}
void prepare()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=M;j++)
        {
            int cnt = k[i]*Pow(j, p[i]);
            x[i][j] = cnt;
        }
    }
}
void solve()
{
    ans = 0;
    int a = n/2;
    int b = n - a;
    prepare();
    CLR(HashTable);
    cal(a,0,0);
    cal(b,a,1);
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n)
    {
        cin >> M;
        for(int i=1;i<=n;i++) cin >> k[i] >> p[i];
        solve();
    }
    //system("pause");
    //printf("%lld\n", (x%mod+mod)%mod );
}

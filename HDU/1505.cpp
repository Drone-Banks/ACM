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

#define MaxN 1010
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
int n,m,t[MaxN][MaxN]; //原矩阵
int a[MaxN][MaxN]; 
int l[MaxN],r[MaxN];
void MaxMatrix()
{
    for(int j=1;j<=m;j++)
    for(int i=1;i<=n;i++)
        if(t[i][j]) a[i][j] = a[i-1][j]+1;
        else a[i][j] = 0;   
    
    int mx = 0;
    for(int i=1;i<=n;i++)
    {
        l[1] = 1, r[m] = m;
        for(int j=2;j<=m;j++)
        {
            if(a[i][j]==0) continue;
            int t = j;
            while( t>1 && a[i][t-1]>=a[i][j])
                t=l[t-1];
            l[j] = t;   
        }
        for(int j=m-1;j>=1;j--)
        {
            if(a[i][j]==0) continue;
            int t = j;
            while( t<m && a[i][t+1]>=a[i][j])
                t = r[t+1];
            r[j] = t;
        }
        for(int j=1;j<=m;j++)
            mx = max(mx, a[i][j]*(r[j]-l[j]+1));
    }
    printf("%d\n", mx*3);
}
int main()
{
    int T;
    std::ios::sync_with_stdio(false);
    cin >> T;
    while(T--)
    {
        char ch;
        cin >> n >> m;    
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
            {
                 cin >> ch;
                 t[i][j] = (ch=='F' ? 1 : 0);
                 
            }
        MaxMatrix();
    }
    return 0;
}
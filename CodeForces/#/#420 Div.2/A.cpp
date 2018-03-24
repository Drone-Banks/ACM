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

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}

int n;
int A[55][55];
int vis[MaxN];
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        scanf("%d", &A[i][j]);

    int cnt = 0;
    bool flag = true;
    for(int i=1;i<=n&&flag;i++)
    for(int j=1;j<=n&&flag;j++)
    {
        int x = A[i][j];
        if(x==1) continue;
        cnt++;
        for(int k=1;k<=n;k++) vis[A[i][k]] = cnt;
        
        bool notf = true;
        for(int k=1;k<=n&&notf;k++) 
        {
            int tmp = x - A[k][j];
            if(vis[tmp]==cnt) notf = false;
        }
        flag = !notf;
    }
    if(flag) puts("Yes");
    else puts("No");
    //system("pause");
}

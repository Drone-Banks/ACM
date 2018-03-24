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

#define MaxN 15
#define MaxM MaxN*MaxN
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;

struct Matrix  
{  
    LL a[MaxN][MaxN];   
    LL* operator[](int x)  
    {  
        return a[x];  
    }  
    LL det(int n)  
    {    
        LL ret = 1;  
        for(int i = 1; i < n; i++)  
        {  
            for(int j = i + 1; j < n; j++)  
                while(a[j][i])  
                {  
                    LL tmp = a[i][i] / a[j][i];  
                    for(int k = i; k < n; k++) a[i][k] = (a[i][k] - a[j][k]*tmp) ;  
                    for(int k = i; k < n; k++) swap(a[i][k], a[j][k]);  
                    ret = -ret;  
                }  
            if(a[i][i] == 0) return 0;  
            ret = ret*a[i][i] ;  
        }  
        return ret;  
    }  
}; 

int n,m;
int main()
{
    //std::ios::sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        Matrix G,ans;
        CLR(ans.a);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                G.a[i][j] = (i==j);
        int u,v;
        while(m--) 
        {
            scanf("%d%d", &u, &v);
            u--,v--;
            G.a[u][v] = G.a[v][u] = 1;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(i!=j && G.a[i][j])
                {
                    ans.a[i][i]++;
                    ans.a[i][j] = -1;
                }
            }
        printf("%lld\n", abs(ans.det(n)) );
    }
    //system("pause");
}

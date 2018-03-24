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
int N,M; 
int T[110];
int P[110],X[110];
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &N);
    int sum = 0;
    for(int i=1;i<=N;i++) {scanf("%d", &T[i]);sum+=T[i];}
    scanf("%d", &M);
    for(int i=1;i<=M;i++) 
    {
        scanf("%d%d", &P[i], &X[i]);
        printf("%d\n", sum + (X[i] - T[P[i]]));
    }

    //system("pause");
}

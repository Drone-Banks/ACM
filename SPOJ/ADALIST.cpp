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

#define MaxN 600001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
int N,Q;
vector<int> V;

int main()
{
    //std::ios::sync_with_stdio(false);
    V.reserve(MaxN*sizeof(int));
    scanf("%d%d", &N, &Q);
    int x,y,z;
    while(N--){scanf("%d", &x);V.push_back(x);}
    while(Q--)
    {
        scanf("%d", &x);
        if(x==1)
        {
            scanf("%d%d", &y, &z);
            V.insert(V.begin()+y-1, z);
        }
        else if(x==2)
        {
            scanf("%d", &y);
            V.erase(V.begin()+y-1);
        }
        else 
        {
            scanf("%d", &y);
            printf("%d\n", V[y-1]);
        }
    }
    //system("pause");
}

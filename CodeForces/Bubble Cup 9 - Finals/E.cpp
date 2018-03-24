/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 200005
#define MaxM MaxN*2
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;

int n;
vector <int> vec[MaxN];

int color[MaxN];

void DFS(int x=0, int p=-1)
{
    
    printf("%d ", x+1);
    color[x] *= -1;
    for(int i=0;i<vec[x].size();i++)
    {

        cout << "\np: " << p+1 << " " << vec[x][i]+1<< endl;
        if( vec[x][i] == p) continue;

        DFS(vec[x][i], x);

        if(x==0 && i == vec[x].size()-1 && color[vec[x][i]] == 1 && color[x] == 1) 
            return;

        printf("%d ", x+1);
        color[x] *= -1;

        if(color[vec[x][i]] == -1)
        {
            printf("%d ", vec[x][i]+1 );
            color[vec[x][i]] *= -1;

            if(x == 0 && i == vec[x].size()-1 && color[vec[x][i]] == 1 && color[x] == 1)
                return;
            
            printf("%d ", x+1);
            color[x] *= -1;
        }
    }
}

int main()
{
    while(~scanf("%d", &n))
    {   
        for(int i=0;i<n;i++)
        {
            cin >> color[i];
        }
        color[0]*=-1;
        for(int i=1;i<n;i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u--,v--;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        DFS();
    }
    //system("pause");
}
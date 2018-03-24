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

#define MaxN 100000
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;

int N;

LL Map[666][666];
int x,y;

int main()
{
    while(~scanf("%d", &N))
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                scanf("%d", &Map[i][j]);
                if(Map[i][j] == 0)
                    x = i, y = j;
            }
        }
        
        map<int,int> M;
        if(N == 1){ cout << 1 << endl; continue;}

        LL a = 0,b = 0;
        for(int i=1;i<=N;i++)
        {
            b+=Map[x][i];   
        }
        int index = x>1 ? x-1 : x+1;
        for(int i=1;i<=N;i++)
        {
            a+=Map[index][i];
        }

        if(a == b) {cout << -1 << endl; continue;}
        M[a] = 0; M[b] = 0;
        int flag = 0;
        for(int i=1;i<=N;i++)
        {
            LL r = 0, c = 0;
            for(int j=1;j<=N;j++)
            {
                r += Map[i][j];
                c += Map[j][i];
            }

            if(r == a) M[a]++;
            else if( r == b) M[b]++;
            else
            {
                flag = 1;
                break;
            }

            if(c == a) M[a]++;
            else if( c == b) M[b]++;
            else
            {
                flag = 1;
                break;
            }
        }
        
        if(!flag)
        {
            LL k1 = 0, k2 = 0;
            for(int i=1;i<=N;i++)
            {
                k1 += Map[i][i];
                k2 += Map[i][N+1-i];
            }
            
            if(k1 == a) M[a]++;
            else if( k1 == b) M[b]++;
            else
            {
                flag = 1;
                
            }

            if(k2 == a) M[a]++;
            else if( k2 == b) M[b]++;
            else
            {
                flag = 1;
                
            }
        }
        //cout << a<<": "<<M[a] << " " <<b<<": "<< M[b] << endl;
        if(M[b]>M[a]) swap(a,b);

        LL tmp = a - b;
        //cout << tmp << endl;

        int cnt = 2;
        if( x == y) cnt++;
        if( x+y == N+1) cnt++;

        if(flag || tmp<=0 || M[b] > cnt) cout << -1 << endl;
        else cout << tmp <<  endl;

    }
    //system("pause");
}
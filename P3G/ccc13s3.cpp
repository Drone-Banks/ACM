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

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;

int T,G;
int a[10],b[10],sa[10],sb[10];
int sum[5];
int newsum[5];
int pt[3] = {0,1,3};
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%d%d", &T, &G))
    {
        int one=1,two=1,three=1,four=1,five=1,six=1,Final=0;
        CLR(sum);
        int teamcomp[5][5] = {{0,0,0,0,0},{0,0,1,1,1},{0,0,0,1,1},{0,0,0,0,1},{0,0,0,0,0}};
        CLR(newsum);
        int A,B,SA,SB;
        for(int i=1;i<=4;i++)
        {
            teamcomp[i][i] = 0;
        }
        for(int i=0;i<G;i++)
        {
            scanf("%d%d%d%d", &A, &B, &SA, &SB);
            teamcomp[A][B] = teamcomp[B][A] = 0;
            if(SA>SB) sum[A]+=3;
            else if(SA==SB) sum[A]+=1,sum[B]+=1;
            else sum[B]+=3;
        }
        int l=0;
        while ( l < 3)
        {
            if (teamcomp[1][2] == 0)
            {
                one = 0;
                l = 2;
            }
            int m = 0;
            while (m < 3)
            {
                if (teamcomp[1][3] == 0)
                {
                    two = 0;
                    m = 3;
                }
                int p = 0;
                while (p < 3)
                {
                    if (teamcomp[1][4]==0)
                    {
                        three = 0;
                        p = 3;
                    }
                    int q = 0;
                    while (q < 3)
                    {
                        if(teamcomp[2][3] == 0)
                        {
                            four = 0;
                            q = 3;
                        }
                        int r = 0;
                        while (r < 3)
                        {
                            if(teamcomp[2][4] == 0)
                            {
                                five = 0;
                                r = 3;
                            }
                            int s = 0;
                            while (s < 3)
                            {
                                if(teamcomp[3][4] == 0)
                                {
                                    six = 0;
                                    s = 3;
                                }
                                newsum[1] = sum[1] + pt[l*one] + pt[m*two] + pt[p*three];
                                newsum[2] = sum[2] + pt[(2-l)*one] + pt[q*four] + pt[r*five];
                                newsum[3] = sum[3] + pt[(2-m)*two] + pt[(2-q)*four] + pt[s*six];          
                                newsum[4] = sum[4] + pt[(2-p)*three] + pt[(2-r)*five] + pt[(2-s)*six];
                                bool win = true;
                                for(int i=1;i<=4;i++)
                                    if (newsum[T] <= newsum[i] && T != i)
                                        win = false;
                                if (win)
                                    Final = Final + 1;
                                s = s + 1;
                            }
                            r = r + 1;
                        }
                        q = q + 1;
                    }
                    p = p + 1;
                }
                m = m + 1;
            }
            l = l + 1;
        }
        printf("%d\n", Final);
    }
    //system("pause");
}

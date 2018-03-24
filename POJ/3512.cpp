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

#define MaxN 1001
#define MaxM MaxN*MaxN
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1E-6;
#define bug cout<<88888888<<endl;
struct Point{
    double x,y;
    Point(){}
    Point(double a,double b){x=a;y=b;}
}point[MaxN];
double line[MaxM];
char s[1001];
bool sig(double x)
{
    if( abs(x)<eps) return true;
    else return false;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    int cas = 1;
    while(1)
    {
        int num = 0;
        while(gets(s))
        {
            if(s[0]=='-'&&s[1]=='-') break;
            sscanf(s, "%lf%lf", &point[num].x, &point[num].y);
            num++;
        }
        if(num==0) break;
        int ans = 0;
        for(int i=0;i<num;i++)
        {
            int cnt = 0;
            for(int j=i+1;j<num;j++)
            {
                if(point[i].x!=point[j].x) line[cnt++]=(point[j].y-point[i].y)/(point[j].x-point[i].x);
            }
            sort(line,line+cnt);
            int sum = 0;
            for(int j=1;j<cnt;j++)
            {
                if(sig(line[j]-line[j-1]))
                {
                    sum++;
                    ans = max(sum, ans);
                }
                else
                {
                    sum = 0;
                }
            }
        }
        printf("%d. %d\n",cas++,ans+2);
    }
    //system("pause");
}

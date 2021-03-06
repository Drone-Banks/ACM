/*************************************************************************
    > File Name: 1007.cpp
    > Author: Akira
    > Mail: qaq.febr2.qaq@gmail.com
    > Created Time: 2017年01月17日 星期二 10时44分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<cmath>
#include<vector>
#include<set>
#include<list>
#include<ctime>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))

using namespace std;

#define MaxN 200001
#define MaxM MaxN*10
#define INF 2000000000
#define EPS 1e-8
#define bug cout << 88888888 << endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

int N;
struct Point{double x,y;int flag;}point[MaxN];
bool cmp (Point a, Point b)
{
    if(a.x == b.x) return a.y<b.y;
    return a.x<b.x;
}

bool cmpQ(Point a, Point b)
{
    if(a.y==b.y) return a.x<b.x;
    return a.y>b.y;
}

double dis(Point a, Point b)
{
    if(a.flag==b.flag) return INF*1.0;
    else return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

double check(double d, int mid,int l, int r)
{
    vector<Point> V;
    double midx = point[mid].x;
    
    for(int i=l;i<=r;i++)
    {
        if( fabs(point[i].x-midx) < d ) V.push_back(point[i]);
    }
    /*
    mid = V.size()/2;
    vector<Point> CV;
    for(int i=0;i<V.size();i++)
    {
        if(fabs(V[i].y - V[mid].y) <d) CV.push_back(V[i]);
    }*/
    sort(V.begin(), V.end(), cmpQ);
    double ans = d;
    for(int i=0;i<V.size();i++)
    {
        for(int j=i+1;j<V.size()&&j<=i+3;j++)
        {
            ans = min(ans, dis(V[i], V[j]));
        }
    }
    return ans;
}

double solve(int l, int r)
{
    if(r-l>2)
    {
        int mid = (r+l)/2;
        double ans = min(solve(l,mid), solve(mid+1,r));
        ans = check(ans, mid,l,r);
        return ans;
    }
    else
    {
        double ans = INF*1.0;
        for(int i=l;i<=r;i++)
        {
            for(int j=i+1;j<=r;j++)
            {
                ans = min(ans, dis(point[i],point[j]));
            }
        }
        return ans;

    }
}


int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        N = 2*n;
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf", &point[i].x, &point[i].y);
            point[i].flag = 0;
        }
        for(int i=n+1;i<=N;i++)
        {
            scanf("%lf%lf", &point[i].x, &point[i].y);
            point[i].flag = 1;
        }
        sort(point+1, point+1+N, cmp);
        double ans = solve(1,N);
        printf("%.3lf\n", ans);
    }
}
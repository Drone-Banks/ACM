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
#define debug(x) cout << #x" = " << x << endl;

int T;
int n, m;

int pro[15];
string times, sta;

int main()
{
    cin >> T;
    while(T--)
    {
        CLR(pro);
        int ans = 0, total = 0;
        cin >> n >> m;
        int xuhao;
        while(m--)
        {
            cin >> xuhao >> times >> sta;
            xuhao -= 1000;
            if(pro[xuhao]==-1) continue;

            if(sta=="AC")
            {
                int cnt = (times[1]-'0')*60 + (times[3]-'0')*10+(times[4]-'0');
                pro[xuhao] += cnt;
                total += pro[xuhao];
                ans++;
                pro[xuhao] = -1;
            }
            else
            {
                pro[xuhao] += 20;
            }
        }
        cout << ans << " " << total << endl;

    }

}
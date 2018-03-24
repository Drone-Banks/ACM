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

string n;
int k;
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin >> n >> k)
    {
        if(k>n.length()-1)
        {
            cout << n.length()-1 << endl;
        }
        else
        {
            int ans = 0;
            int cnt = 0;
            for(int i=n.length()-1;i>=0&&cnt<k;i--)
            {
                if(n[i]=='0') cnt++;
                else ans++;
            }
            if( ans+cnt == n.length() || cnt <k ) cout << n.length()-1 << endl;
            else cout << ans << endl;
        }
    }
    //system("pause");
}

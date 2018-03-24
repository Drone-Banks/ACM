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

int T;
int n;
map<string, pair<int,int> > M;
int main()
{
    std::ios::sync_with_stdio(false);
    cin >>T;
    while(T--)
    {
        M.clear();
        cin >>n;
        string name;
        int x;
        while(n--)
        {
            cin >> name >> x;
            if(M[name].first == 0)
            {
                M[name].first = x;
            }
            else
            {
                if( x >= M[name].first)
                {
                    M[name].second = M[name].first;
                    M[name].first = x;
                }
                else if( x>M[name].second)
                {
                    M[name].second = x;
                }
            }
        }
        int sum = 0;
        for (pair<string,pair<int,int> > P : M)
        {
            //cout << P.first <<" " <<  P.second.first << " " << P.second.second << endl;
            sum += P.second.first;
            sum += P.second.second;
        }
        cout << sum << endl;
    }
    //system("pause");
}

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
#define bug cout<<88888888<<endl;
int l,r;

void solve()
{
    LL a = min(l,r);
    cout << a*(a+1)/2<< endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    freopen("C-large-practice.in","r",stdin);
    freopen("ans.out","w",stdout);

    int test,  count = 1;
    cin>>test;
    for (int i = 1; i<=test; ++i) {
        cin>>l>>r;
        cout<<"Case #"<< i <<": ";
        if(l==0 || r==0) cout << 0 << endl;
        else solve();
    }
    fclose(stdin);
    fclose(stdout);
    //system("pause");
}

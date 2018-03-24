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
const int mod = 1E9 + 7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;

int num[110];
char str[66];
char ss[66][66];
int ch[300];
int main()
{
	//std::ios::sync_with_stdio(false);
	int n;
	scanf("%d", &n);
	bool flag = true;
	for (int i = 0; i<n; i++)
	{
		scanf("%s", ss[i]);
		for (int j = 0; j < strlen(ss[0]); j++) ch[ss[i][j]] ++;
	}
	for (int i = 97; i <= 122;i++)
	{
		if (ch[i] && ch[i] % n != 0)  flag = false;
	}
	if (!flag)
	{
		cout << -1 << endl;
		return 0;
	}
    int ans = INF;
	for(int k=0;k<n;k++)
    {
        CLR(num);
        strcat(str, ss[k]);
        strcat(str, ss[k]);
        //debug(str);
        int len = strlen(ss[k]);
        for (int i = 0; i<len; i++) num[i]++;
        for (int i = 1; i<n; i++)
        {
            int loc = strstr(str, ss[i])- str;
            //debug(loc);
            for (int j = 0; j<len; j++)
            {
                num[loc + j]++;
            }
        }
        int cnt = 0;
        for (int i = 0; i<2 * len; i++)
        {
            if (num[i] != n) cnt += num[i];
            else break;
        }
        ans = min(ans,cnt);
    }
    cout << ans << endl;
	system("pause");
}

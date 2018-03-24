/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include<bits/stdc++.h>
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
int N;
int diff[MaxN];
LL PowerMod(LL a, LL b, LL c) 
{
	LL ans = 1;
	a = a % c;
	while(b>0)
	{
		if(b % 2 == 1) ans = (ans * a) % c;
		b = b/2;
		a = (a * a) % c;
	}
	return ans;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &N);
    for(int i=1;i<=N;i++) scanf("%d", &diff[i]);
    sort(diff+1, diff+1+N, [](int x,int y){return x>y;});
    bool flag = true;
    int cnt = N-1, num = 0;
    for(int i=1;i<=N&&flag;i++)
    {
        if(diff[i] == cnt)
        {
            num++;
            if(num==2)
            {
                cnt -=2;
                num = 0;
            }
        }
        else flag = false;
    } 
    if(flag) printf("%lld\n", PowerMod(2,N/2,mod));
    else puts("0");
    //system("pause");
}

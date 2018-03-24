#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn = 1010;
int dp[maxn];
int a[maxn];
int b[maxn];
int main()
{
    int n;
    cin >> n;
    memset(a, 0, sizeof(a));
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);

    int k=1;
    b[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]>b[k]) b[++k]=a[i];
        else
        {
            int j=k;
            while(a[i]<=b[j]) j--;
            b[j+1]=a[i];
		}
    }
    cout << k << endl;
    return 0;
}

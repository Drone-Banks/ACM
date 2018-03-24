#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
const int maxn = 200000;
int s[maxn], a[maxn], p[maxn], m[maxn];
int i, j, n;

int fmax(int x)
{
    int ans = 0;
    while(x > 0)
    {
        if (ans < s[x]) ans = s[x];
        x = x - (x & (-x));
    }
    return ans;
}

void change(int x, int b)
{
    while(x <= n)
    {
        if (s[x] >= b) break;
        s[x] = b;
        x = x + (x & (-x));
    }
    return;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(scanf("%d", &n) == 1)
    {
        memset(s, 0, sizeof(s));
        memset(a, 0, sizeof(a));
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=6; j++)
            {
                scanf("%d", &p[j]);
                m[j] = fmax(p[j]-1)+1;
            }
            for(j=1; j<=6; j++)
            {
                if (m[j] > a[p[j]])
                {
                    a[p[j]] = m[j];
                    change(p[j], m[j]);
                }
            }
        }
        printf("%d\n", fmax(n));
    }
    //system("pause");
}
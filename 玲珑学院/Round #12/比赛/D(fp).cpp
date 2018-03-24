#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const long long nn = 1234321237;
long long tt, n, i, j, k;
long long a[4][4]={{6, 1, 0, 0},{-6, 1, 6, 0},{0, 0, 6, 1},{0, 0, -6, 1}};
long long ans[4][4], b[4][4];
long long f[4][4];
int main()
{
    scanf("%lld", &tt);
    while(tt--)
    {
        scanf("%lld", &n);
        n--;
        memset(ans, 0, sizeof(ans));
        for(i=0; i<4; i++) ans[i][i] = 1;
        memcpy(b, a, sizeof(b));

        while(n)
        {
            if (n%2)
            {
                memset(f, 0, sizeof(f));
                for(i=0; i<2; i++)
                    for(j=0; j<2; j++)
                        for(k=0; k<2; k++)
                            f[i][j] = (f[i][j]+ans[i][k]*a[k][j]%nn) %nn;
                for(i=2; i<4; i++)
                    for(j=2; j<4; j++)
                        for(k=2; k<4; k++)
                            f[i][j] = (f[i][j]+ans[i][k]*a[k][j]%nn) %nn;
                for(i=0; i<2; i++)
                    for(j=2; j<4; j++)
                       for(k=0; k<4; k++)
                           f[i][j] = (f[i][j]+ans[i][k]*a[k][j]%nn) %nn;
                memcpy(ans, f, sizeof(ans));
            }
            n /= 2;
            memset(f, 0, sizeof(f));
                for(i=0; i<2; i++)
                    for(j=0; j<2; j++)
                        for(k=0; k<2; k++)
                            f[i][j] = (f[i][j]+a[i][k]*a[k][j]%nn) %nn;
                for(i=2; i<4; i++)
                    for(j=2; j<4; j++)
                        for(k=2; k<4; k++)
                            f[i][j] = (f[i][j]+a[i][k]*a[k][j]%nn) %nn;
                for(i=0; i<2; i++)
                    for(j=2; j<4; j++)
                       for(k=0; k<4; k++)
                           f[i][j] = (f[i][j]+a[i][k]*a[k][j]%nn) %nn;
            memcpy(a, f, sizeof(a));
        }
        memcpy(a, b, sizeof(a));
        if (ans[0][0] < 0) ans[0][0] += nn;
        if (ans[0][2] < 0) ans[0][2] += nn;
        printf("%lld %lld\n", ans[0][0] %nn, ans[0][2] %nn);
    }
}
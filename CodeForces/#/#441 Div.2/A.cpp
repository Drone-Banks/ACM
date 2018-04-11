#include<bits/stdc++.h>

using namespace std;

int n,a,b,c;

int main()
{
    while(~scanf("%d%d%d%d", &n, &a, &b, &c))
    {
        int ans = 0;
        n--;
        if(n)
        {
            int mn = min(a,min(b,c));
            if(a==mn || b==mn) ans = n*mn;
            else ans = min(a,b)+(n-1)*mn;
        }
        printf("%d\n", ans);
    }
}
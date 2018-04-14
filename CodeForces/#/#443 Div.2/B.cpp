#include<bits/stdc++.h>
#define MaxN 300005
using namespace std;


int n, k;
int a[505];

int main()
{
    while(~scanf("%d%d", &n, &k))
    {
        for(int i=1;i<=n;i++) scanf("%d", &a[i]); 

        int now = 0, tmp = 0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==n) break;
            
            if(a[i] > now) {
                if(i!=1) tmp = 1;
                else tmp = 0;
                now = a[i];
            }
            else tmp++;
            
            if(tmp==k) break;
        }
        if(tmp==k) printf("%d\n", now);
        else printf("%d\n", n);
    }
}
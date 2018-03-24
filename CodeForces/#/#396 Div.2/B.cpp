#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

int a[100005];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);

        sort(a,a+n);

        int f=0;

        for(int i=0;i<=n-3;i++)
        {
            if(a[i]+a[i+1]>a[i+2])
                f=1;
        }

        if(f==1)
            printf("YES\n");
        else
            printf("NO");
    }

}
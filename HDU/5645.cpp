#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;


int ball [666];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(ball,0,sizeof(ball));
        int n;
        cin >>n;
        for(int i=1;i<=n;i++)
            cin >> ball[i];

        //sort(ball,ball+n);

        double ans = 0;

        for(int i=1;i<=n;i++)
        {
            int add = 0;

            for(int j=1;j<=n;j++)
                if(ball[i]>ball[j]) add++;

            ans=ans+add;
        }
        printf("%.6f\n",ans/(1.0*n*(n-1)) );
    }

    return 0;
}


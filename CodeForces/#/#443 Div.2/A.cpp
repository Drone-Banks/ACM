#include<bits/stdc++.h>
#define MaxN 300005
using namespace std;


int n, s, d;

int main()
{
    while(~scanf("%d", &n))
    {
        int tmp = 0;
        for(int i=1;i<=n;i++) {
            scanf("%d%d", &s, &d);
            int dis = tmp-s;
            if(i!=1 && dis>=0) {
                tmp = s + (dis/d + 1)*d;
            }
            else tmp = s;
            // cout << tmp << endl;
        }
        printf("%d\n", tmp);
    }
}
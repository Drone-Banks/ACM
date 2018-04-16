#include<bits/stdc++.h>
#define MaxN 300005
using namespace std;


int n, num[3][6];
bool in[1005], use[3];

int main()
{
    while(~scanf("%d", &n))
    {
        memset(in, 0, sizeof(in));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<6;j++)
            {
                scanf("%d", &num[i][j]);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            use[i] = 1;

            for(int x=0;x<6;x++) in[num[i][x]] = 1;

            for(int j=0;j<n;j++)
            {
                if(use[j]) continue;
                use[j] = 1;
                for(int x=0;x<6;x++) 
                for(int y=0;y<6;y++) in[num[i][x]*10+num[j][y]] = 1;

                for(int k=0;k<n;k++)
                {
                    if(use[k]) continue;
                    use[k] = 1;
                    // cout << i << j << k << endl;
                    for(int x=0;x<6;x++) 
                    for(int y=0;y<6;y++)
                    for(int z=0;z<6;z++) in[num[i][x]*100+num[j][y]*10+num[k][z]] = 1;
                    use[k] = 0;
                }
                use[j] = 0;
            }
            use[i] = 0;
        }

        for(int i=1;i<=1000;i++)
        {
            if(!in[i]) { printf("%d\n", i-1); break;}
        }
    }
}
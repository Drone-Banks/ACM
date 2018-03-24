#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 10005;
int f[105], sg[MAX];

void get_sg(int n)
{
    memset(sg, 0, sizeof(sg));
    bool vst[MAX];
    for(int i = 0; i < MAX; i++)
    {
        memset(vst, false, sizeof(vst));
        int h = 0, j;
        while(i >= f[h] && h < n)
            vst[sg[i - f[h++]]] = true;
        for(j = 0; j <= i; j++)
        {
            if(!vst[j])
            {
                sg[i] = j; 
                break;
            }
        }
    }
    return ;
}

int k;
int m,I;

int main()
{
    while(~scanf("%d", &k) && k )
    {
        for(int i=0;i<k;i++)
        {
            scanf("%d", &f[i]);
        }
        
        sort(f, f+k);
        get_sg(k);

        scanf("%d", &m);
        for(int i=0;i<m;i++)
        {
            int heaps,ans=0;
            scanf("%d", &I);
            for(int j=0;j<I;j++)
            {
                scanf("%d", &heaps);
                ans ^= sg[heaps];
            }
            if(!ans)
                printf("L");
            else
                printf("W");
        }
        printf("\n");
    }
    return 0;
}

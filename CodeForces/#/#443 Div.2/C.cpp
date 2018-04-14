#include<bits/stdc++.h>
#define MaxN 300005
using namespace std;

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        char ch;
        int val, mask = 0, Aor = 0, Xor = 0;
        for(int j=0;j<n;j++)
        {
            scanf(" %c %d", &ch, &val);
            switch(ch)
            {
            case '|':
                for(int i=0;i<10;i++) 
                    if(val&(1<<i)){
                        mask |= (1<<i);
                        Aor |= (1<<i);
                    }
                break;
            case '&':
                for(int i=0;i<10;i++) 
                    if( (val&(1<<i)) == 0){
                        mask |= (1<<i);
                        Aor &= ((1<<10)-1-(1<<i));
                    }
                break;
            case '^':
                for(int i=0;i<10;i++) 
                    if(val&(1<<i)){
                        if(mask&(1<<i)) Aor ^= (1<<i);
                        Xor ^= (1<<i);
                    }
                break;
            }
        }
        puts("3");
        int And = 1023, Or = 0, xo = 0;
        for(int i=0;i<10;i++) 
        if(mask&(1<<i)){
            if(Aor&(1<<i))
                Or += (1<<i);
            else
                And -= (1<<i);
        }
        else if( (Xor&(1<<i)) ) xo += (1<<i);
        printf("& %d\n", And);
        printf("| %d\n", Or);
        printf("^ %d\n", xo);

    }
}
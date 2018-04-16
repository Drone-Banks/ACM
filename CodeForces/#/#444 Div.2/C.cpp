#include<bits/stdc++.h>
#define MaxN 300005
using namespace std;


int n, cube[25], now[25];

bool check()
{
    bool flag = true;
    for(int i=0;i<6;i++)
    {
        if( !(now[i*4+1] == now[i*4+2] && now[i*4+2] == now[i*4+3] && now[i*4+3] == now[i*4+4]) )
        {
            flag = false; break;
        }
    }
     return flag;
}

int main()
{
    // while(~scanf("%d", &n))
    {
        for(int i=1;i<=24;i++) scanf("%d", &cube[i]);
        bool ans = false;

        //

        for(int i=1;i<=24;i++) now[i] = cube[i];
        int x = now[1], y = now[3];
        now[1] = now[5], now[3] = now[7], now[5] = now[9], now[7] = now[11], now[9] = now[24], now[11] = now[22], now[24] = x, now[22] = y;
        ans = check();
        if(ans) { puts("YES");  return 0; }        
        for(int i=1;i<=24;i++) now[i] = cube[i];
        x = now[24], y = now[22];
        now[24] = now[9], now[22] = now[11], now[9] = now[5], now[11] = now[7], now[5] = now[1], now[7] = now[3], now[1] = x, now[3] = y, 
        ans = check();
        if(ans) { puts("YES");  return 0; }

        for(int i=1;i<=24;i++) now[i] = cube[i];
        x = now[2], y = now[4];
        now[2] = now[6], now[4] = now[8], now[6] = now[10], now[8] = now[12], now[10] = now[23], now[12] = now[21], now[23] = x, now[21] = y;
        ans = check();
        if(ans) { puts("YES");  return 0; }        
        for(int i=1;i<=24;i++) now[i] = cube[i];
        x = now[23], y = now[21];
        now[23] = now[2], now[21] = now[4], now[10] = now[23], now[12] = now[21], now[6] = now[10], now[8] = now[12], now[2] = x, now[4] = y;
        ans = check();
        if(ans) { puts("YES");  return 0; }

        //

        for(int i=1;i<=24;i++) now[i] = cube[i];
        x = now[13], y = now[14];
        now[13] = now[5], now[14] = now[6], now[5] = now[17], now[6] = now[18], now[17] = now[21], now[18] = now[22], now[21] = x, now[22] = y;
        ans = check();
        if(ans) { puts("YES");  return 0; }
        for(int i=1;i<=24;i++) now[i] = cube[i];
        x = now[21], y = now[22];
        now[21] = now[13], now[22] = now[14], now[17] = now[21], now[18] = now[22], now[5] = now[17], now[6] = now[18], now[13] = x, now[14] = y;
        ans = check();
        if(ans) { puts("YES");  return 0; }


        for(int i=1;i<=24;i++) now[i] = cube[i];
        x = now[15], y = now[16];
        now[15] = now[7], now[16] = now[8], now[7] = now[19], now[8] = now[20], now[19] = now[23], now[20] = now[24], now[23] = x, now[24] = y;
        ans = check();
        if(ans) { puts("YES");  return 0; }
        for(int i=1;i<=24;i++) now[i] = cube[i];
        x = now[23], y = now[24];
        now[23] = now[15], now[24] = now[16], now[19] = now[23], now[20] = now[24], now[7] = now[19], now[8] = now[20], now[15] = x, now[16] = y;
        ans = check();
        if(ans) { puts("YES");  return 0; }

        //

        for(int i=1;i<=24;i++) now[i] = cube[i];
        x = now[3], y = now[4];
        now[3] = now[17], now[4] = now[19], now[17] = now[10], now[19] = now[9], now[10] = now[16], now[9] = now[14], now[16] = x, now[14] = y;
        ans = check();
        if(ans) { puts("YES");  return 0; }
        for(int i=1;i<=24;i++) now[i] = cube[i];
        x = now[16], y = now[14];
        now[16] = now[3], now[14] = now[4], now[10] = now[16], now[9] = now[14], now[17] = now[10], now[19] = now[9], now[3] = x, now[4] = y;
        ans = check();
        if(ans) { puts("YES");  return 0; }

        for(int i=1;i<=24;i++) now[i] = cube[i];
        x = now[1], y = now[2];
        now[1] = now[18], now[2] = now[20], now[18] = now[12], now[20] = now[11], now[12] = now[15], now[11] = now[13], now[15] = x, now[13] = y;
        ans = check();
        if(ans) { puts("YES");  return 0; }
        for(int i=1;i<=24;i++) now[i] = cube[i];
        x = now[16], y = now[14];
        now[15] = now[1], now[13] = now[2], now[12] = now[15], now[11] = now[13], now[18] = now[12], now[20] = now[11], now[1] = x, now[2] = y;
        ans = check();
        if(ans) { puts("YES");  return 0; }

        puts("NO");
    }
}
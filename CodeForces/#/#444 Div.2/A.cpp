#include<bits/stdc++.h>
#define MaxN 300005
using namespace std;


char input[105];


int main()
{
    while(~scanf("%s", &input))
    {
        int cnt = -1, len = strlen(input);
        for(int i=0; i<len; i++)
        {
            if( input[i] == '1' && cnt == -1 ) cnt = 0;
            if( input[i] == '0' && cnt != -1 ) cnt ++; 
        }
        if(cnt>=6) puts("yes");
        else puts("no");
    }
}
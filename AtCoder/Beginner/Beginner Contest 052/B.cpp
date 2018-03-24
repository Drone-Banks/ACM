#include<bits/stdc++.h>
 
int N;
char str[101];
int main()
{
    scanf("%d", &N);
    scanf("%s", &str);
    int x = 0, ans = 0;
    for(int i=0;i<N;i++)
    {
        if(str[i]=='I') x++;
        else x--;
        ans = ans>x?ans:x;
    }
    printf("%d\n", ans);
}
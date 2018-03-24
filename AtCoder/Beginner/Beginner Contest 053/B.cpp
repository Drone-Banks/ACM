#include<bits/stdc++.h>
using namespace std;
char str[200010];
int main()
{
    scanf("%s", str);
    int A = -1, Z=0;
    for(int i=0;i<strlen(str);i++)
    {
         if(A==-1&&str[i]=='A') A = i;
         if(str[i]=='Z') Z=i;
    }
    printf("%d\n", Z-A+1);
} 
#include<bits/stdc++.h>
using namespace std;
int N;
int A[100005];
int B[100005];
int main()
{
    scanf("%d", &N);
    int len = 0;
    for(int i=0;i<N;i++)
    {
         scanf("%d", &A[i]);
         B[A[i]]++;
         len = max(len, A[i]);
    }
    int flag = 0;
    int ans = 0;
    for(int i=1;i<=len;i++)
    {
         while(B[i]>2) B[i]-=2;
         if(B[i]==2) flag^=1;
         if(B[i]>0) ans++;
    }
    printf("%d\n", ans-flag);
}
/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 2000010
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
int Q[MaxN];
int T;
char op[11];
int x;
int main()
{
    //std::ios::sync_with_stdio(false);
    int head = 1000001, tail = 1000001;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", op);
        if(op[0]=='t')
        {
            scanf("%d", &x);
            if(head<=tail) Q[--head] = x;
            else Q[++head] = x;
        }
        else if(op[0]=='p')
        {
            scanf("%d", &x);
            if(head<=tail) Q[tail++] = x;
            else Q[tail--] = x;
        }
        else if(op[0] == 'r')
        {
            int cnt = tail;
            if(head<=tail)
            {
                tail = head-1;
                head = cnt-1;
            }
            else
            {
                tail = head+1;
                head = cnt+1;
            }
        }
        else if(op[0]=='f')
        {
            if(head==tail) printf("No job for Ada?\n");
            else 
            {
                if(head<=tail)
                {
                    x = Q[head++];
                }
                else
                {
                    x = Q[head--];
                }
                printf("%d\n", x);
            }
        }
        else if(op[0]=='b')
        {
            if(head==tail) printf("No job for Ada?\n");
            else 
            {
                if(head<=tail)
                {
                    x = Q[--tail];
                }
                else
                {
                    x = Q[++tail];
                }
                printf("%d\n", x);
            }
        }   
    }
    //system("pause");
}

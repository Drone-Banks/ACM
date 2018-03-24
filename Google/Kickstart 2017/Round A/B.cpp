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

#define MaxN 10001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x;
int T;
char A[MaxN],B[MaxN],str[MaxN];
int N,M;
void check(char *s,int flag)
{
    int i,j;
    for(i=0,j=0;i<strlen(s);i++)
    {
        if(s[i] == '*')
        {
            if(flag) 
            {
                A[++j] = '0';
                A[++j] = '0';
                A[++j] = '0';
                A[++j] = '0';
            }
            else
            {
                B[++j] = '0';
                B[++j] = '0';
                B[++j] = '0';
                B[++j] = '0';
            }
        }
        else
        {
            if(flag) A[++j] = s[i];
            else B[++j] = s[i];
        }
    }
    if(flag) N = j;
    else M = j;
}
int DP[MaxN][MaxN];
int main()
{
    //std::ios::sync_with_stdio(false);
    freopen("B-large-practice.in","r",stdin);
	freopen("B.out","w",stdout);
	/********************************************/
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
    {
        scanf("%s",str);
        check(str,1);
        scanf("%s",str);
        check(str,0);
        CLR(DP);
        DP[0][0] = 1;
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=M;j++)
            {
                if(DP[i][j])
                {
                    DP[i+1][j] |= A[i+1]=='0';
                    DP[i][j+1] |= B[j+1]=='0';
                    DP[i+1][j+1] |= A[i+1]=='0'|| B[j+1]=='0' || A[i+1]==B[j+1];
                }
            }
        }
        if(DP[N][M]) printf("Case #%d: TRUE\n", t);
        else printf("Case #%d: FALSE\n", t);
    }
    /********************************************/
    fclose(stdin);
    fclose(stdout);
    return 0;
}

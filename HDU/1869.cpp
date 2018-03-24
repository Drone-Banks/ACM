#include <cstdio>
#define MIN(a,b) a<b?a:b
using namespace std;
const int INF = 0x3f3f3f3f;
int n,m;
int A[101][101];
void init()
{
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            A[i][j] = A[j][i] = INF;
}
void Floyd()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            if(A[i][k] == INF) continue;
            else
                for(int j=1;j< =n;j++)
                    A[j][i] = A[i][j] = MIN(A[i][j], A[i][k]+A[k][j]);
}

void check()
{
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(A[i][j]>7)
            {
                printf("No\n");
                return;
            }
    printf("Yes\n");

}

int main()
{
    while( ~scanf("%d%d", &n, &m))
    {
        init();
        while(m--)
        {
            int a,b;
            scanf("%d%d", &a, &b);
            a++;
            b++;
            A[a][b] = A[b][a] = 1;
        }
        Floyd();
        check();
    }
}
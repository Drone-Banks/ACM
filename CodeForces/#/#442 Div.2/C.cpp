#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        cout << n + n / 2 << endl;
        printf("%d",2);
        for (int i = 4; i <= n; i+=2)
        {
            printf(" %d",i);
        }
        for (int i = 1; i <= n; i+=2)
        {
            printf(" %d",i);
        }
        for (int i = 2; i <= n; i+=2)
        {
            printf(" %d",i);
        }
        printf("\n");
    }
    return 0;
}
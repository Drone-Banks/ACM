#include <iostream>
#include <algorithm>
using namespace std;

int n, number[110], bright[110], loc[110];
int num;

bool check(int x, int y)
{
    int s[4],t[4];
    int pn = number[y];
    int pr = bright[y];
    int pl = loc[y];

    for(int i=3; i>=0; i--)
        s[i] = x%10, x /= 10, t[i] = pn%10, pn/=10;

    int cr=0,cl=0;
    for(int i=0;i<4;i++)
        if(s[i] == t[i]) cl++;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(t[j] == s[i])
            {
                cr++;
                t[j] = -1;
                break;
            }
    return cr==pr && cl == pl;
}

int main()
{
    while(cin >> n && n)
    {
        for(int i=0;i<n;i++)
            cin >> number[i] >> bright[i] >> loc[i];

        num = 0;
        int ans;
        for(int i=1000; i<10000 && num<2; i++)
        {
            int j=0;
            for(; j<n; j++)
            {
                if(!check(i, j)) break;
            }
            if(j == n) num++, ans = i;
        }
        if(num == 1) cout << ans << endl;
        else cout << "Not sure" << endl;
    }


    return 0;
}

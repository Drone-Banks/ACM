#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    int N,M;
    string word;
    cin >> N;
    int t = 0;
    while(N--)
    {
        t++;
        int cnt = 0;
        cin >> M;
        while(M--)
        {
            cin >> word;
            if(word == "sheep") cnt++;
        }
        if(N == 0) printf("Case %d: This list contains %d sheep.\n", t, cnt);
        else printf("Case %d: This list contains %d sheep.\n\n", t, cnt);
    }
}

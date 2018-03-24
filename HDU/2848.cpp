#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX_N = 22;

long long base[MAX_N];

void makeBase()
{
    base[0] = 1;
    for (int i = 1; i <= 18; ++i)
        base[i] = base[i-1] * 10;
}

bool dfs (long long n, int k);

bool test (long long n, int k, int nPart, long long curSum) //n表示的是前面没有被划分的部分，nPart表示的现在已经划分块数，curSum就是和
{
    if (nPart == k)
        return ! dfs (curSum+n, k);       //如果当前的解法已经将这个数字划分完毕，
                                        //那么就判断这个数字的和是否能让
                                        //B失败
    for (int i = 1; i < 20; ++i)
    {
        long long a = n % base[i];
        long long b = n / base[i];
        if (b == 0) break;
        if (test(b, k, nPart+1, curSum+a))
            return true;
    }
    return false;
}

bool dfs (long long n, int k)
{
    if (n < base[k-1]) return false;
    else return test(n, k, 1, 0);
}

int main ()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    makeBase();
    int k;
    long long n;
    while (cin >> n >> k)
        cout << dfs(n, k) << endl;
    return 0;
}
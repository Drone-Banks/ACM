#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
 
const int MAX_D = 365 * 105;
const int ds[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
 
bool is_leap_year(int year)
{
    return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
}
 
struct date
{
    int y, m, d;
    date() { }
    date(int y, int m, int d) : y(y), m(m), d(d) { }
    bool operator<(const date &other) const
    {
        return y != other.y ? y < other.y : m != other.m ? m < other.m : d < other.d;
    }
};
 
int D;
date days[MAX_D];
bool win[MAX_D];
 
void init_calendar()
{
    for (int y = 1900; y <= 2001; y++)
    {
        for (int m = 0; m < 12; m++)
        {
            for (int d = 0, ed = ds[m] + ((m == 1 && is_leap_year(y)) ? 1 : 0); d < ed; d++)
            {
                days[D++] = date(y, m, d);
            }
        }
    }
}
 
void solve()
{
    memset(win, true, sizeof(win));
    int start = lower_bound(days, days + D, date(2001, 10, 3)) - days;
    win[start] = false;
    for (int i = start - 1; i >= 0; --i)
    {
        win[i] = false;
        if (!win[i + 1])        // 如果两个next状态中有一个必败状态
        {
            win[i] = true;      // 则current状态为必胜状态
            continue;
        }
        else
        {
            date nxt = days[i];
            nxt.m++;
            if (nxt.m == 12)
            {
                nxt.y++;
                nxt.m = 0;
            }
            if (binary_search(days, days + D, nxt) &&
                    !win[lower_bound(days, days + D, nxt) - days])// 如果两个next状态中有一个必败状态
            {
                win[i] = true;  // 则current状态为必胜状态
            }
        }
    }
}
int main(int argc, char *argv[])
{
    init_calendar();
    solve();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int y, m, d;
        scanf("%d%d%d", &y, &m, &d);
        m--;
        d--;
        puts(win[lower_bound(days, days + D, date(y, m, d)) - days] ? "YES" : "NO");
    }
    return 0;
}
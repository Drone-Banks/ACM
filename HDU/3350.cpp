/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
#include <climits>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 100000
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;

template<typename _> inline void scan(_& t)
{
    int c;
    while((c = getchar()) < '0' || c > '9');
    t = c - '0';
    while((c = getchar()) >= '0' && c <= '9') t = t * 10 + c - '0';
}
template<typename _> inline void print(_ x)
{
    int len = 0, p[20];
    if(x < 0) putchar('-'), x = -x;
    while(x) p[++len] = x % 10, x /= 10;
    if(!len) p[++len] = 0;
    while(len) putchar(p[len--] + '0');
}
int T;
string str;
struct Node
{
    int val,add;
}tmp;
stack<Node> num;
stack<char> op;
void solve()
{
    while (!num.empty()) num.pop();
	while (!op.empty()) op.pop();
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='('||str[i]=='+') op.push(str[i]);
        else if( str[i] >='0'&& str[i]<='9')
        {
            tmp.val = tmp.add = 0;
            while(str[i]>='0' && str[i]<='9')
            {
                tmp.val = tmp.val*10+str[i]-'0';
                i++;
            }
            i--;
            num.push(tmp);
        }
        else if(str[i]==',')
        {
            while(!op.empty() && op.top()=='+')
            {
                tmp = num.top();
                num.pop();
                op.pop();
                tmp.val += num.top().val;
                tmp.add += num.top().add+1;
                num.pop();
                num.push(tmp);
            }
        }
        else if(str[i]==')')
        {
            while(!op.empty() && op.top() == '+' )
            {
                tmp = num.top();
                num.pop();
                op.pop();
                tmp.val += num.top().val;
                tmp.add += num.top().add+1;
                num.pop();
                num.push(tmp);
            }
            op.pop();
            tmp = num.top();
            num.pop();
            if(tmp.val < num.top().val)
            {
                tmp.val = num.top().val;
                tmp.add += (num.top().add*2);
            }
            else tmp.add = tmp.add*2 + num.top().add;
            num.pop();
            num.push(tmp);
        }
    }
    while (!op.empty() && op.top() == '+')
	{
		op.pop();
		tmp = num.top();
		num.pop();
		tmp.val += num.top().val;
		tmp.add += (num.top().add + 1);
		num.pop();
		num.push(tmp);
	}
	cout << num.top().val << " " << num.top().add << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> T;
    while(T--)
    {
        cin >> str;
        solve();
    }
    //system("pause");
}

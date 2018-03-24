/*************************************************************************
> File Name: test.cpp
> Author: Akira 
> Mail: qaq.febr2.qaq@gmail.com 
************************************************************************/

//#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <iomanip>
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
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define pb push_back
using namespace std;                                                                                              

#define MaxN 100005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
template<typename T> T abs(T val){return val>0?val:-val;}
inline int max2(int a, int b) {return ((a > b)? a : b);}
inline int min2(int a, int b) {return ((a < b)? a : b);}
inline int max3(int a, int b, int c) {return max2(a, max2(b, c));}
inline int min3(int a, int b, int c) {return min2(a, min2(b, c));}
template <class T> inline void read(T &ret) {char c; ret=0;while((c=getchar())<'0'||c>'9');while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();}
template <class T> inline void out(T x) {if(x>9) out(x/10);putchar(x%10+'0');}

map<string, int> M;
map<string, int>::iterator it;
int n;
string input;

inline void check(string str)
{
    string ans;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            ans += str[i];
        }
        else
        {
            switch(str[i])
            {
            case 'A':
            case 'B':
            case 'C': ans+="2"; break;
            case 'D':
            case 'E':
            case 'F': ans+="3"; break;
            case 'G': 
            case 'H':
            case 'I': ans+="4"; break;
            case 'J':
            case 'K':
            case 'L': ans+="5"; break;
            case 'M':
            case 'N':
            case 'O': ans+="6"; break;
            case 'P':
            case 'R':
            case 'S': ans+="7"; break;
            case 'T':
            case 'U':
            case 'V': ans+="8"; break;
            case 'W':
            case 'X':
            case 'Y': ans+="9"; break;
            default:  break;
            }
        }
        if(ans.length()==3) ans += "-";
    }
    if(ans.length()==8) M[ans]++;
}
struct Node
{
    string str;
    int num;
    bool operator<(const Node& a) const
    {
        return str<a.str;
    }
}node[MaxN];
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++) 
    {
        cin >> input;
        check(input);
    }
    int tot = 0;
    bool flag = true;
    for(it=M.begin();it!=M.end();it++)
    {
        if( (*it).second>1 ) 
        {
            flag = false;
            node[tot].str = (*it).first;
            node[tot].num = (*it).second;
            tot++;
        }
    }
    if(flag) 
    {
        cout << "No duplicates.\n";
        return 0;
    }
    sort(node,node+tot);
    for(int i=0;i<tot;i++)
    {
        cout << node[i].str << " " << node[i].num << endl;
    }
}

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

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
int n;
char a[500];
string str;
int main()
{
    std::ios::sync_with_stdio(false);
    a['a'] = 'P', a['b'] = 'g', a['c'] = 'E', a['d'] = 'f', a['e'] = 'T', a['f'] = 'Y', a['g'] = 'a';
    a['h'] = 'W', a['i'] = 'G', a['j'] = 'H', a['k'] = 'j', a['l'] = 'D', a['m'] = 'A', a['n'] = 'm';
    a['o'] = 'x', a['p'] = 'Q', a['q'] = 'q', a['r'] = 'F', a['s'] = 'L', a['t'] = 'R';
    a['u'] = 'p', a['v'] = 'C', a['w'] = 'J', a['x'] = 'B', a['y'] = 'o', a['z'] = 'w';
    a['A'] = 'n', a['B'] = 'y', a['C'] = 'U', a['D'] = 'K', a['E'] = 'Z', a['F'] = 'X', a['G'] = 'k';
    a['H'] = 'b', a['I'] = 'v', a['J'] = 'z', a['K'] = 'I', a['L'] = 'd', a['M'] = 's', a['N'] = 'h';
    a['O'] = 'u', a['P'] = 'r', a['Q'] = 'M', a['R'] = 'i', a['S'] = 'l', a['T'] = 'N';
    a['U'] = 'S', a['V'] = 'V', a['W'] = 'O', a['X'] = 't', a['Y'] = 'e', a['Z'] = 'c';
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> str;
        for(int k=0;k<str.length();k++) str[k] = a[str[k]];
        cout << str ;
        if(i!=n-1) cout << " ";
        else cout << endl;
    }
    system("pause");
}

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

#define MaxN 100001
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
const int mod = 1E9+7;
const double eps = 1e-6;
#define bug cout<<88888888<<endl;
#define debug(x) cout << #x" = " << x << endl;
int T;
int k;
char base[64];
void init()
{
    for(int i=0;i<26;i++)
    {
         base[i] = i+'A';
    }
    for(int i=26;i<52;i++)
    {
        base[i] = (i-26)+'a';
    }
    for(int i=52;i<62;i++)
    {
        base[i] = (i-52)+'0';
    }
    base[62] = '+',base[63] = '/';
}
string cal(string str)
{
    string ans = "";
    int len = str.length();
    for(int i=0;i<len;i+=3)
    {
        bitset<8> bb[3];
        int input = 0;
        for(int j=0;j<3;j++)
        {
            if(i+j<len) 
            {
                //cout << str[i+j] <<": " << (int)str[i+j]<<endl;
                bb[j] = bitset<8>(str[i+j]);
                //cout << bb[j] << endl;
                input++;
            }
            else bb[j] = bitset<8>(0); 
        }
        int limit;
        if(input==1) limit = 12;
        else if(input==2) limit = 18;
        else limit = 24;
        //cout << bb[0]<<bb[1]<<bb[2] << endl;
        int cnt = 0;
        for(int j=0;j<=limit;j++)
        {
            if(j && (j%6)==0)
            {
                //cout <<j<<"-"<< cnt << endl;
                //if(cnt==0 && j==limit) break;
                ans += base[cnt];
                cnt = 0;
                if(j==limit) break;
            }
            int loc = 8-j%8-1;
            int num = j/8;
            if(bb[num][loc]==1)
            {
                cnt += (1<<(6-j%6-1));
            }
        }
    }
    //cout << ans << endl;
    int l = ans.length();
    int rem = 4 - (l%4 ? l%4 : 4);
    //cout << rem << endl;
    while(rem) {ans+="=";rem--;}
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> T;
    string str;
    init();
    for(int t=1;t<=T;t++)
    {
        cin >> k >> str;
        while(k--)
        {
            str = cal(str);
        }
        cout << "Case #" << t << ": " << str << endl;
    }
    //system("pause");
}
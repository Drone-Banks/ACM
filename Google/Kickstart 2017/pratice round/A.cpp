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
#include <fstream>
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
#define bug cout<<88888888<<endl;
int T,N;

int main()
{
    std::ios::sync_with_stdio(false);
    //freopen("A-large.in","r",stdin);
	//freopen("A.out","w",stdout);
	/********************************************/
    cin >> T;
    for(int t=1;t<=T;t++)
    {
        string name;
        cin >> N;
        int Count = 0;
        string ans;
        cin.get();
        for(int i=0;i<N;i++)
        {
            int cnt = 0;
            getline(cin, name);
            //cout << name << endl;
            map<char,int> M;
            for(int j=0;j<name.length();j++)
            {
                if(name[j]>='A' && name[j]<='Z')
                {
                    if(M.find(name[j])==M.end())
                    {
                        cnt++;
                        M[name[j]] = 1;
                    }
                }
            }
            if(cnt == Count)
            {
                if(name < ans) ans = name;
            }
            if(cnt>Count)
            {
                ans = name;
                Count = cnt;
            }
        }
        cout << "Case #" << t << ": " << ans << endl; 
    }
    /********************************************/
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

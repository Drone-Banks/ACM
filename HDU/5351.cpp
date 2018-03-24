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
template <int n>  
struct DP  
{  
    enum { ret = DP<n-1>::ret + DP<n-2>::ret };  
}; 
template <>  
struct DP<4>  
{  
    enum { ret = 1 };  
};
template <>  
struct DP<5>  
{  
    enum { ret = 1 };  
};

//cout << factorial<n>::ret <<endl;   
int T;
int N,M;
/*
1 0b             
2 0a           
3 0ab          
4 1aba           
5 2abaab        
6 3abaababa     
7 5abaababaabaab   
*/
//这题是Java
int main()
{
    //std::ios::sync_with_stdio(false);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &N, &M);
        if(N<=3) puts("0");
        else printf("%d\n", DP)
    }
    //system("pause");
}

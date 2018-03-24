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
#define ALL(a) a.begin(), a.end()
#define mp make_pair
#define ps push_back
using namespace std;

#define MaxN 100001
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

int good[30];
char gg[30], tar[MaxN], str[MaxN];
int lent,lens,pos;

bool search()
{
    if(pos!=-1)
    {
        int left,right;
        int i=0,j=0;
        while(i<pos && j<lens)
        {
            if( (tar[i]=='?' && good[str[j]-'a']==1) || (tar[i]==str[j])  ) 
            {
                i++, j++;
            }
            else break;
        }
        if(i!=pos) return false;
        else
        {
            left = j;
        }
        i = lent-1,j=lens-1;
        while(i>pos&&j>=left)
        {
            if( (tar[i]=='?' && good[str[j]-'a']==1) || (tar[i]==str[j])  ) 
            {
                i--, j--;
            }
            else break;
        }
        if(i!=pos) return false;
        else
        {
            right = j;
        }
        for(i=left;i<=right;i++)
        {
            if(good[str[i]-'a']!=0) return false;
        }
        return true;
    }
    else
    {
        int i=0,j=0;
        while(i<lent&&j<lens)
        {
            if( (tar[i]=='?' && good[str[i]-'a']==1) || (tar[i]==str[i])  ) 
            {
                i++, j++;
            }
            else break;
        }
        if(i==lent && j==lens ) return true;
        else return false;
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    while(~scanf("%s", gg)  )
    {
        scanf("%s", tar);
        lent = strlen(tar);
        CLR(good);
        int len = strlen(gg);
        for(int i=0;i<len;i++) good[gg[i]-'a'] = 1;
        pos = -1;
        for(int i=0;i<lent;i++) if(tar[i]=='*') pos = i;
        int Q;
        scanf("%d", &Q);
        while(Q--)
        {
            scanf("%s", str);
            lens = strlen(str);
            if(search() ) puts("YES");
            else puts("NO");
        }
    }
}

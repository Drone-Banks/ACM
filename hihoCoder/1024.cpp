/*************************************************************************
    > File Name: test.cpp
    > Author: Akira 
    > Mail: qaq.febr2.qaq@gmail.com 
 ************************************************************************/

#include <iostream>
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
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

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
struct node
{
    int count;
    node *childs[26];
    node()
    {
        count=0;
        int i;
        for(i=0;i<26;i++)
        childs[i]=NULL;
    }
};
node *root=new node;
node *current,*newnode;
void insert(char *str)
{
    int i,m;
    current=root;
    for(i=0;i<strlen(str);i++)
    {
        m=str[i]-'a';
        if(current->childs[m]!=NULL)
        {
            current=current->childs[m];
            ++(current->count);
        }
        else
        {
            newnode=new node;
            ++(newnode->count);
            current->childs[m]=newnode;
            current=newnode;
        }
    }
}
int search(char *str)
{
    int i,m;
    current=root;
    for(i=0;i<strlen(str);i++)
    {
        m=str[i]-'a';
        if(current->childs[m]==NULL)
        return 0;
        current=current->childs[m];
    }
    return current->count;
}

int n,m;
int main()
{
    char str[20];
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%s", str);
        insert(str);
    }
    scanf("%d",&m);
    while(m--)      //查询
    {
        scanf("%s", str);
        if(str=="") printf("%d\n", n);
        else printf("%d\n",search(str));
    }
}

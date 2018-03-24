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

#define MaxN 100005
#define MaxM MaxN
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
struct Node
{
    int s;
    int f;
    int cost;
    int not_root;
};
vector<int> V[MaxN];
int S,F;
int a, b;
int people;
int notRoot[MaxN];
char name[1005];
map<string, int> M;
map<string, int>::iterator it;
Node DP[MaxN][3];
void initNode(int &loc)
{
    DP[loc][0].s =0;
    DP[loc][0].f = 0;
    DP[loc][0].cost = 0;
    DP[loc][1].s =0;
    DP[loc][1].f = 0;
    DP[loc][1].cost = 0;
    DP[loc][2].s=0;
    DP[loc][2].f=0;
    DP[loc][2].cost=0;
    DP[loc][0].not_root = 0;
    V[loc].clear();
}
int isNumber (string s)
{
    int i, ans;
    ans = 0;
    for (i=0; i<s.length(); i++)
    {
        if ( s[i] >= '0' && s[i] <= '9' )
                ans = ans*10 + (s[i]-'0');
        else
                return -1;
    }
    return ans;
}
void Initial ()
{
    people = 0;
    M.clear();
}
bool Input ()
{
    //如果上个testcase已经将这次输入的第一个变量读入到a，就无需再读入
    if ( a == -1 )  scanf("%d", &a);
    scanf("%d", &b);
    S = a;
    F = b;
    a = b = -1;
    if ( S == 0 && F == 0 )
            return false;
    char ch;
    int pid, sid;
    string parent, son;
    Initial();
    while (1)
    {
        //bug;
        //先将名字读入字符串数组，在将其置于string， 这样做是为了节省时间
        scanf("%s", &name);          
        parent = "";
        parent.append(name);
        a = isNumber(parent);
        if ( a != -1 )  break;     //读入了下个testcase的数据
            
        it = M.find(parent);     //查找有无对应映射
        if ( it ==  M.end() )
        {
            M[parent] = people;
            initNode(people);
            people++;
        }
        pid = M[parent];
        //读取当前节点的孩子
        ch = getchar();
        while ( ch != '\n' )
        {
            scanf("%s", &name);
            son = "";
            son.append(name);       //把字符数组的内容传给string
            it = M.find(son);
            if ( it == M.end() )
            {
                M[son] = people;
                initNode(people);
                people++;
            }
            sid = M[son];
            V[pid].push_back(sid);
            DP[sid][0].not_root = 1;
            ch = getchar();
        }
    }
   return true;
}

void cal(int &ans, int &s, int &f, Node a, Node b) //取最小花费和最小票数
{
    if(a.cost > b.cost)
    {
        ans += b.cost;
        s += b.s;
        f += b.f;
    }
    else if( a.cost < b.cost)
    {
        ans += a.cost;
        s += a.s;
        f += a.f;
    }
    else
    {
        int sa = a.s + a.f;
        int sb = b.s + b.f;
        ans += a.cost;
        if(sa >= sb)
        {
            s+=b.s; f+=b.f;
        }
        else 
        {
            s+=a.s; f+=a.f;
        }
    }
}
/*
ans0
DP[u][0] = MIN(DP[v][1], DP[v][2]);
DP[u][1] = cost + MIN(DP[v][1], DP[v][2]);
ans1
DP[u][2] = cost + MIN(DP[v][0], DP[v][2]);
*/
void DFS(int u)
{
    int ans0 = 0, ans1 = 0;
    int ns0 = 0, ns1 = 0, nf0 = 0, nf1 = 0;
    for(int i=0;i<V[u].size();i++)
    {
        int v = V[u][i];
        DFS(v);
        cal(ans0,ns0,nf0,DP[v][1],DP[v][2]);
        cal(ans1,ns1,nf1,DP[v][0],DP[v][2]);
    }
    //不买票
    DP[u][0].cost = ans0;
    DP[u][0].s = ns0; DP[u][0].f = nf0;
    //买个人票
    DP[u][1].cost = S+ans0;
    DP[u][1].s = ns0+1; DP[u][1].f = nf0;
    //买家庭票
    DP[u][2].cost = F+ans1;
    DP[u][2].s = ns1; DP[u][2].f = (nf1+1);
}
void solve()
{
    int ans = 0, sn = 0, fn = 0;
    for(int i=0;i<people;i++)
    {
        if(DP[i][0].not_root!=1)
        {
            DFS(i);
            //cout << i <<"is not root" << endl;
            cal(ans, sn, fn, DP[i][1], DP[i][2]);
        }
    }
    printf("%d %d %d\n", sn, fn, ans);
}

int main()
{
    int cas = 1;
    a = b = -1;
    while(Input())
    {
        printf("%d. ", cas++);
        solve();
    }
   // system("pause");
}
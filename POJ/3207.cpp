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
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <ctime>
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define MST(a,b) memset(a,b,sizeof(a))
#define CLR(a) MST(a,0)
#define Sqr(a) ((a)*(a))
using namespace std;

#define MaxN 1005
#define MaxM MaxN*10
#define INF 0x3f3f3f3f
#define bug cout<<88888888<<endl;
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)

int n,m;
int Map[MaxN][MaxN];                //邻接矩阵 存图

int low[MaxN];
int dfn[MaxN];

int Stack[MaxN], top;
int inStack[MaxN];
int belong[MaxN];                   //记录强连通分量
int Index, cnt;

void init()
{
    CLR(Map);
    MST(dfn,-1);
    CLR(low);
    CLR(inStack);
    Index = cnt = 1;
    top = 0;
}


void Tarjan(int x)
{
    int i, a;
    low[x] = dfn[x] = Index;                // 刚搜到一个节点时low = dfn
    Index++;
    Stack[++top] = x;                       // 将该节点入栈
    inStack[x] = 1;                         // 将入栈标记设置为1
    for(i = 1; i <= 2*m; i++)                 // 遍历入栈节点的边
    {
        if(!Map[x][i]) continue;            // 如果两点之间没有边,不用管它

        if(dfn[i] == -1)                    // 如果新搜索到的节点是从未被搜索过
        {
            Tarjan(i);                      // 那自然就得搜索这个节点
            low[x]=MIN(low[x], low[i]);     // 回溯的时候改变当前节点的low值
        }
        else if(inStack[i])                 // 如果新搜索到的节点已经被搜索过而且现在在栈中
        {
            low[x] = MIN(low[x], dfn[i]);   // 更新当前节点的low值，这里的意思是两个节点之间有一条可达边，
        }                                   // 而前面节点已经在栈中，那么后面的节点就可能和前面的节点在一个联通分量中
    }

    if(low[x] == dfn[x])                    // 最终退回来的时候 low == dfn ， 没有节点能将根节点更新，那
    {                                       // low == dfn 的节点必然就是根节点
        int temp;
        while(1)                            // 一直出栈到此节点， 这些元素是一个强联通分量
        {
            temp = Stack[top--];            // 弹出栈元素
            belong[temp] = cnt;             // 为了方便计算，将强联通分量进行标记
            inStack[temp] = 0;              // 将栈内标记置为0
            if(temp == x)                   // 一直弹到x出现为止
                break;
        }
        cnt++;
    }
}

int x[MaxN],y[MaxN];

int main()
{
    while(~scanf("%d%d", &n, &m)) 
    {
        init();     
        for(int i = 1; i <= m; i++)  
        {  
            scanf("%d%d", &x[i], &y[i]);  
            x[i]++; y[i]++;  
            if(x[i] > y[i]) swap(x[i], y[i]);  
        }  
        for(int i = 1; i <= m; i++)  
            for(int j = i + 1; j <= m; j++)  
                if((x[i] <= x[j] && y[i] >= x[j] && y[i] <= y[j]) || (x[i] >= x[j] && x[i] <= y[j] && y[i] >= y[j]))  
                {  
                    Map[i][j+m]=1;
                    Map[i+m][j]=1;
                    Map[j][i+m]=1;  
                    Map[j+m][i]=1;
                }  
                                      // 初始化
        for(int i = 1; i <= m*2; i++) 
            if(dfn[i] == -1)                            // 如果某点没被访问过，则对其进行tarjan
                Tarjan(i); 
        int flag = 1;                             // tarjan的成果是得到了一个belong数组，记录每个节点分别属于哪个强联通分量
        for(int i = 1; i <= m; i++)  
            {cout << belong[i] << " - " <<belong[i+m]<<endl; if(belong[i] == belong[i + m]) flag = 0; }
        if(flag) cout <<"panda is telling the truth...\n";
        else cout << "the evil panda is lying again\n";
    }
    system("pause"); 
}

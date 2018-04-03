#include<bits/stdc++.h>

using namespace std;

int N;

struct Node{
    int x, y;
    Node(){}
    Node(int x, int y):x(x), y(y){}
};

vector<Node> nodes;
bool enter[100005][4];
map<int,int> M[4];
int ans[4][100005];


void init()
{
    nodes.clear(); 
    for(int i=0; i<4; i++) M[i].clear();
    memset(enter,0,sizeof(enter));
    memset(ans, 0, sizeof(ans));
}

int cal(int id, int type)
{
    switch(type)
    {
    case 0:
        return nodes[id].y;
    case 1:
        return nodes[id].x;
    case 2:
        return nodes[id].y-nodes[id].x;
    case 3:
        return nodes[id].y+nodes[id].x;
    default:
        return 0;
    }
}
void solve()
{
    init();
    for(int m=0;m<4;m++)
    {
        for(int i=0; i<N; i++)
        {
            int index = cal(i,m);
            
            if( M[m].find(index) == M[m].end() ){
                M[m][index] = M[m].size()+1;
            }
            // cout << m << ": " << index << ": " << M[m][index] << endl;
            ans[m][M[m][index]]++;
        }
    }
    long long sum = 0;
    for(int m=0;m<4;m++)
    {
        for(int i=0; i<N; i++)
        {
            // cout << m << ": " << ans[m][i] << endl;
            sum += 1LL*ans[m][i]*(ans[m][i]-1)/2;
        }
    }
    printf("%lld\n", sum);
    
}

int main()
{
    while(~scanf("%d", &N))
    {
        int x, y;
        for(int i=0; i<N; i++){
            scanf("%d %d", &x, &y);
            nodes.push_back(Node(x, y));
        }
        solve();        
    }
}
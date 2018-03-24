struct Node {
    int id;
    int st[7];
}start;
class Solution {
private:
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int Fac[20] = {1,1,2,6,24,120,720,5040,40320,362880}; 
    int num[7], ans[200000];
    bool vis[200000];
    void init()
    {
        memset(vis,0,sizeof(vis));
    }
    bool check(int x, int y){
        if(x<0 || x>1 || y<0 || y>2) return false;
        return true;
    }

    int Cantor(int s[]) 
    {
        int i,j,num,temp,n=6;
        num=0;
        for(i=0;i<n;i++)
        {
            temp=0;     
            for(j=i+1;j<n;j++)
                if(s[j]<s[i])
                    temp++;
            num+=Fac[n-1-i]*temp; 
        }
        return num;
    }

    void Init() {
        memset(ans, -1, sizeof(ans));
        for(int i = 0; i < 6; i ++) {
            start.st[i] = (i + 1) % 6;
        }
        start.id = Cantor(start.st);
    }


    int yy[7] = {0,1,2,0,1,2};
    int xx[7] = {0,0,0,1,1,1};
    void bfs() {
        ans[start.id] = 0;
        queue<Node> q;
        q.push(start);
        while(!q.empty()) {
            Node now = q.front();
            q.pop();
            int x, y, loc;
            for(int i = 0; i < 6; i ++) {
                if(now.st[i] == 0) {
                    x = xx[i], y = yy[i];
                    loc = i;
                    break;
                }
            }

            for(int i = 0; i < 4; i ++) {
                int tx = x + dir[i][0], ty = y + dir[i][1];
                int tloc = tx * 3 + ty;

                if(check(tx, ty)) {
                    Node tmp = now;
                    tmp.st[loc] = now.st[tloc];
                    tmp.st[tloc] = 0;
                    tmp.id = Cantor(tmp.st);
                    if(ans[tmp.id] < 0) {
                        ans[tmp.id] = ans[now.id] + 1;
                        q.push(tmp);
                    }
                }
            }
        }
    }

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        Init();
        bfs();
        int cnt = 0;
        for(int i=0;i<2; i++) 
            for(int j=0;j<3;j++)
            num[cnt++] = board[i][j];
        int state = Cantor(num);
        if(ans[state] < 0) return -1;
		else return ans[state];
    }
};

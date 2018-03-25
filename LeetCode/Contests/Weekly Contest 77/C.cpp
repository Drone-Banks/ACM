class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> max_row, max_col;
        for(int i=0; i<grid.size(); i++)
        {
            int cnt = 0;
            for(int j=0; j<grid[i].size(); j++) 
                cnt = max(cnt, grid[i][j]);
            max_row.push_back(cnt);
        }
        for(int i=0; i<grid[0].size(); i++)
        {
            int cnt = 0;
            for(int j=0; j<grid.size(); j++) 
                cnt = max(cnt, grid[j][i]);
            max_col.push_back(cnt);
        }
        int ans = 0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[i].size(); j++) 
            {
                ans += max(0, min(max_row[i], max_col[j])-grid[i][j]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int cnt = 0, rows = 0;
        for(int i=0;i<S.length();i++)
        {
            cnt += widths[S[i]-'a'];
            if(cnt==100) {
                cnt=0;
                rows++;
            }
            else if(cnt>100){
                cnt = widths[S[i]-'a'];
                rows++;
            }
        }
        if(cnt) rows++;
        vector<int> ans;
        ans.push_back(rows);
        ans.push_back(cnt);
        return ans;
    }
};
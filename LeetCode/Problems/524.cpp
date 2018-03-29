class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        s = "#"+s;
        int len = s.length();
        vector< vector<int> > next(len, vector<int>(26, -1));
        for(int i=0; i<len; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                int ord = s[j]-'a';
                if( next[i][ord] == -1) next[i][ord] = j;
            }
        }
        
        string ans = "";
        for(int i=0; i<d.size(); i++)
        {
            if( d[i].length() < ans.length() ) continue;
            int now = 0;
            bool flag = true;
            for(int j=0; j<d[i].length(); j++)
            {
                int ord = d[i][j]-'a', index = next[now][ord];
                if(index==-1) {
                    flag = false;
                    break;
                }
                now = index;
            }
            if(flag) {
                if( d[i].length()>ans.length() ) ans = d[i];
                if( d[i] < ans ) ans = d[i];
            }
        }
        return ans;
        
    }
};

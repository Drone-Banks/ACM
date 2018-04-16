class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> M;
        string ans;
        int cnt = 0;
        
        string now = "";
        for(int i=0; i<paragraph.length(); i++)
        {
            char ch = paragraph[i];
            if( ch == ' ' || ch == ',' || ch == '.' || ch == '!' || ch == '?' || ch == '\'' || ch == ';' ) {
                if( now == "" ) continue;
                bool flag = true; 
                for(auto str : banned) {
                    if(str == now) {flag = false; break;}
                }
                if(flag) M[now]++;
                if(M[now] > cnt) {ans = now; cnt = M[now];}
                now = "";
            }
            else {
                if( ch < 97){ch = char(ch-65+97); }
                now.insert(now.end(), ch);
            }
            // cout << now << endl;
        }
        bool flag = true; 
        for(auto str : banned) {
            if(str == now) {flag = false; break;}
        }
        if(flag) M[now]++;
        if(M[now] > cnt) {ans = now; cnt = M[now];}
        return ans;
    }
};
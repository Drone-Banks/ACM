class Solution {
private:
    string dict[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> ans;
        for(int i=0; i<words.size(); i++)
        {
            string tmp = "";
            for(int j=0; j<words[i].length(); j++)
            {
                tmp += dict[words[i][j]-'a'];
            }
            ans.insert(tmp);
        }
        return ans.size();
    }
};
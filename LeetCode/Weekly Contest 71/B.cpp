#define debug(x) cout<<#x" = "<<x<<endl;
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        map<int,int> dict;
        for( int x : answers ) 
        {
            dict[x]++;           
        } 
        for( pair<int,int> item : dict )
        {
            int num = item.first?((item.second/(item.first+1))+((item.second%(item.first+1))?1:0)):(item.second);
            debug(item.first) debug(item.second) debug(num)
            ans += num*(item.first+1);
        }
        return ans;
    }
};
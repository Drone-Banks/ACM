class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if( nums.empty() ) return nums;
        int len = nums.size();
        vector<int> ans = nums, arr = nums;
        arr.insert(arr.end(), nums.begin(), nums.end());
        deque<int> index;
        for(int i=0; i<2*len; i++)
        {
            while( !index.empty() && arr[i]>arr[index.front()] )
            {
                ans[index.front()] = arr[i];
                index.pop_front();
            }
            if( i<len ) 
                if ( !index.empty() && arr[i]>arr[index.front()] ) index.push_back(i);
                else index.push_front(i);
        }
        while( !index.empty() ) {
            ans[index.front()] = -1;
            index.pop_front();
        }
        return ans;
    }
};
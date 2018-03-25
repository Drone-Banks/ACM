class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int sum = 0, len = A.size();
        for(int i=0; i<len; i++) sum+=A[i];
        vector<vector <bool> > DP(sum+1 ,vector<bool>(len+1,0));   
        DP[0][0] = true;
        for(int i=0; i<len; i++)
        {
            for(int s=sum; s>=A[i]; s--)
            {
                for(int n=1; n<=i+1; n++)
                {
                    DP[s][n] = DP[s][n] | DP[s-A[i]][n-1];
                }
            }
        }
        for (int i = 1; i < len; i++) {
            int cnt = sum * i;
            if ( cnt%len == 0) {
                if (DP[cnt/len][i]) return true;
            }
        }
        return false;
    }
};
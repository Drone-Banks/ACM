double dis[1000005];
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        for(int i=0;i<stations.size();i++){
            if(i!=0) dis[i] = stations[i]-stations[i-1];
        }
        double left = 0, right = 1E8, eps = 1E-6;
        while( right-left > eps)
        {
            double mid = (left + right)/2.0;
            int tmp = 0;
            for(int i=1;i<stations.size();i++)
            {
                int cnt = (dis[i]/mid);
                tmp += cnt;
            }
            if( tmp > K ) 
                left = mid;
            else 
                right = mid;
        }
        return right;
    }
};
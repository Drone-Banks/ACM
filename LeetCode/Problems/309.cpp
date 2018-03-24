class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int pre_sell = 0, sell = 0, buy = -prices[0], len = prices.size();
        for(int i=1;i<len;i++)
        {
            int new_sell = max(buy + prices[i], sell);
            int new_buy = max(buy, pre_sell-prices[i]);
            pre_sell = sell, sell = new_sell, buy = new_buy;
        }
        return sell;
    }
};
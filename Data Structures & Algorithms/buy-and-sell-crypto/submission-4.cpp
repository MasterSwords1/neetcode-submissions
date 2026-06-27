class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.size() < 2)
            return 0;
        int profit = 0;
        int buy = 0;
        int sell = 0;

        for (; sell < prices.size(); sell++)
        {
            if (prices[sell] < prices[buy])
                buy = sell;
            else
                profit = max(profit, prices[sell] - prices[buy]);
        }
        return profit;
    }
};

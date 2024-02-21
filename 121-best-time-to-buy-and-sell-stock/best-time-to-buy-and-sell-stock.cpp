class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), minNum = INT_MAX, maxProfit = 0;

        for (int i = 0; i < n; i++)
            if (prices[i] < minNum)
                minNum = prices[i];
            else
                maxProfit = max(maxProfit, prices[i] - minNum);

        return maxProfit;
    }
};
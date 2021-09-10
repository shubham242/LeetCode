static const auto fast = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    
    int minCostClimbingStairs(vector<int> &cost)
    {
        int l = cost.size();
        int dp[l];
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < l; i++)
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        return min(dp[l - 1], dp[l - 2]);
    }
};
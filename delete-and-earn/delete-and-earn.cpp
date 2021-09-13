class Solution {
public:
    int deleteAndEarn(vector<int> &nums)
    {
        int l = nums.size();
        int maxm = 0;
        for (int i = 0; i < l; i++)
            maxm = max(maxm, nums[i]);
        
        if(maxm==1)
            return l;

        vector<int> n(maxm + 1, 0);
        for (int i = 0; i < l; i++)
            n[nums[i]] += nums[i];

        int dp[maxm + 1];
        dp[0] = n[0];
        dp[1] = n[1];
        dp[2] = n[2] + n[0];

        for (int i = 3; i <= maxm; i++)
            dp[i] = n[i] + max(dp[i - 2], dp[i - 3]);

        return max(dp[maxm], dp[maxm - 1]);
    }
};
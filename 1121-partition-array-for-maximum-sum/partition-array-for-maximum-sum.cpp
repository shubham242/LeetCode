class Solution {
   public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int mx = 0;
            for (int j = i; j < min(i + k, n); j++) {
                mx = max(mx, arr[j]);
                dp[i] = max(dp[i], (j - i + 1) * mx + dp[j + 1]);
            }
        }

        return dp[0];
    }
};

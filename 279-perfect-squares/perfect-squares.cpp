class Solution {
   public:
    bool isSquare(int n) {
        int sq = sqrt(n);
        return sq * sq == n;
    }
    int numSquares(int n) {
        int dp[n + 1];

        for (int i = 1; i <= n; i++) {
            dp[i] = i;
            if (isSquare(i)) {
                dp[i] = 1;
                continue;
            }
            for (int j = 1; j * j <= i; j++)
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
        }
        return dp[n];
    }
};
class Solution {
   public:
    int dp[10001];
    bool isSquare(int n) {
        int sq = sqrt(n);
        return sq * sq == n;
    }
    int solve(int n) {
        if (isSquare(n)) return 1;
        if (n <= 3) return n;
        if (dp[n] != -1) return dp[n];

        dp[n] = n;
        for (int i = 1; i * i <= n; i++)
            dp[n] = min(dp[n], 1 + solve(n - i * i));

        return dp[n];
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};
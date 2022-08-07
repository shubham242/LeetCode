class Solution
{
public:
    int M = 1e9 + 7;
    int dp[5][20000];
    long recurr(char prev, int n)
    {
        if (n == 0)
            return 1;
        if (dp[prev][n] != -1)
            return dp[prev][n];

        if (prev == 0)
            return dp[prev][n] = recurr(1, n - 1) % M;
        if (prev == 1)
            return dp[prev][n] = (recurr(0, n - 1) % M + recurr(2, n - 1) % M) % M;
        if (prev == 2)
            return dp[prev][n] = (recurr(0, n - 1) % M + recurr(1, n - 1) % M + recurr(3, n - 1) % M + recurr(4, n - 1) % M) % M;
        if (prev == 3)
            return dp[prev][n] = (recurr(2, n - 1) % M + recurr(4, n - 1) % M) % M;

        return dp[prev][n] = recurr(0, n - 1) % M;
    }
    int countVowelPermutation(int n)
    {
        memset(dp, -1, sizeof(dp));
        return (recurr(0, n - 1) + recurr(1, n - 1) + recurr(2, n - 1) + recurr(3, n - 1) + recurr(4, n - 1)) % M;
    }
};
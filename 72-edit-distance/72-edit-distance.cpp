class Solution
{
public:
    int dp[501][501];
    int solve(string w1, string w2, int i, int j)
    {
        if (i == w1.size())
            return w2.size() - j;
        if (j == w2.size())
            return w1.size() - i;
        if (w1[i] == w2[j])
            return solve(w1, w2, i + 1, j + 1);

        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = min({
                   1 + solve(w1, w2, i + 1, j),
                   1 + solve(w1, w2, i, j + 1),
                   1 + solve(w1, w2, i + 1, j + 1),
               });
    }
    int minDistance(string word1, string word2)
    {
        memset(dp, -1, sizeof(dp));
        return solve(word1, word2, 0, 0);
    }
};
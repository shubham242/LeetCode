class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int l1 = text1.size();
        int l2 = text2.size();
        if (l2 > l1)
        {
            swap(text1, text2);
            swap(l1, l2);
        }
        vector<int> dp(l2 + 1, 0);

        for (int i = 1; i <= l1; i++)
        {
            vector<int> prev = dp;
            for (int j = 1; j <= l2; j++)
                if (text1[i - 1] == text2[j - 1])
                    dp[j] = 1 + prev[j - 1];
                else
                    dp[j] = max(dp[j - 1], prev[j]);
        }

        return dp[l2];
    }
};
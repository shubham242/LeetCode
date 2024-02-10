class Solution {
   public:
    bool isPalindrome(string s, int start, int end, vector<vector<int>> &dp) {
        if (start >= end)
            return true;
        if (dp[start][end] != -1)
            return dp[start][end];

        else if (s[start] == s[end])
            return dp[start][end] = isPalindrome(s, start + 1, end - 1, dp);
        else
            return dp[start][end] = false;
    }
    int countSubstrings(string s) {
        int n = s.size(), res = n;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (isPalindrome(s, i, j, dp))
                    res++;

        return res;
    }
};
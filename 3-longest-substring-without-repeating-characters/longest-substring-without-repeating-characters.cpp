class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), hash[128] = {0}, start = 0, maxLen = 0;

        for (int i = 0; i < n; i++) {
            if (hash[s[i]] > start)
                start = hash[s[i]];
            maxLen = max(maxLen, i - start + 1);
            hash[s[i]] = i + 1;
        }

        return maxLen;
    }
};
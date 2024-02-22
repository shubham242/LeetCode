class Solution {
   public:
    bool checkUnique(int hash[]) {
        for (int i = 0; i < 256; i++)
            if (hash[i] > 1) return false;
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), hash[256] = {0}, start = 0, maxLen = 0;

        for (int end = 0; end < n; end++) {
            hash[s[end]]++;
            while (!checkUnique(hash)) {
                hash[s[start]]--;
                start++;
            }
            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};
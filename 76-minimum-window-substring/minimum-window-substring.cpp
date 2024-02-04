class Solution {
   public:
    bool isHashZero(int hash[]) {
        for (int i = 0; i < 58; i++)
            if (hash[i] > 0) return false;
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n < m) return "";

        int hash[68] = {0};
        for (int i = 0; i < m; i++) {
            hash[t[i] - 'A']++;
        }

        int start = 0, end = 0, minLen = INT_MAX, minStart = 0;

        while (end < n) {
            hash[s[end] - 'A']--;
            while (isHashZero(hash)) {
                if (end - start + 1 < minLen) {
                    minLen = end - start + 1;
                    minStart = start;
                }
                hash[s[start] - 'A']++;
                start++;
            }
            end++;
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
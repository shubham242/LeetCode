class Solution {
   public:
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for (auto string : words)
            if (isPalindrome(string, 0, string.size() - 1)) return string;
        return "";
    }
};
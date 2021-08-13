static const auto fast = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int maxLen = 1;
        int start = 0;

        for (int i = 1; i < s.size(); i++)
        {
            int left, right;

            for (left = i - 1, right = i + 1; left >= 0 && right < s.size() && s[left] == s[right]; left--, right++)
            {
            }
            left++;
            right--;

            if (left >= 0 && right < s.size() && right - left + 1 > maxLen)
            {
                maxLen = right - left + 1;
                start = left;
            }

            for (left = i - 1, right = i; left >= 0 && right < s.size() && s[left] == s[right]; left--, right++)
            {
            }
            left++;
            right--;

            if (left >= 0 && right < s.size() && right - left + 1 > maxLen)
            {
                maxLen = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, maxLen);
    }
};
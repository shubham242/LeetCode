class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = s.size();
        int ch[128] = {0};
        int maxLen = 0;
        int start = 0;
        for (int i = 0; i < l; i++)
        {
            if (ch[s[i]] > start)
                start = ch[s[i]];
            maxLen = max(maxLen, i + 1 - start);
            ch[s[i]] = i + 1;
        }
        return maxLen;
    }
};
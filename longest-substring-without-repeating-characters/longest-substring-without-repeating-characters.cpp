class Solution
{
public:
    vector<int> temp = vector<int>(256, -1);
    int lengthOfLongestSubstring(string s)
    {
        int max_len = 0;
        int start = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (temp[s[i]] > start)
                start = temp[s[i]];
            temp[s[i]] = i;
            max_len = max(max_len, i - start);
        }
        return max_len;
    }
};
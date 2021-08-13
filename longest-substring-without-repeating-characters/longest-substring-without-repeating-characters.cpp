class Solution
{
public:
    vector<int> arr = vector<int>(256, 0);
    vector<int> temp = vector<int>(256, 0);
    vector<int> zero = vector<int>(256, 0);
    int lengthOfLongestSubstring(string s)
    {
        int max_len = 0;
        int start = 0;
        int i;
        for (i = 0; i < s.size(); i++)
        {
            if (arr[s[i]] == 0)
            {
                arr[s[i]]++;
                temp[s[i]] = i;
            }
            else
            {
                for (int j = start; j < temp[s[i]] + 1; j++)
                    arr[s[j]] = 0;
                max_len = max(max_len, i - start);
                start = temp[s[i]] + 1;
                arr[s[i]]++;
                temp[s[i]] = i;
            }
        }
        max_len = max(max_len, i - start);
        return max_len;
    }
};
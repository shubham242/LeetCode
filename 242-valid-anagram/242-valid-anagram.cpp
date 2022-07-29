class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        int arr[26];
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < s.size(); i++)
        {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (arr[i])
                return false;
        return true;
    }
};
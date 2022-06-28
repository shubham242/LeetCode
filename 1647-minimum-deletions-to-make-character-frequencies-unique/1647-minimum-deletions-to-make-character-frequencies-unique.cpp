class Solution
{
public:
    int minDeletions(string s)
    {
        vector<int> hash(26, 0);
        for (auto c : s)
            hash[c - 'a']++;

        unordered_map<int, int> mp;

        for (int i = 0; i < 26; i++)
            mp[hash[i]]++;

        int count = 0;

        for (int i = 0; i < 26; i++)
        {
            while (hash[i] && mp[hash[i]] > 1)
            {
                mp[hash[i]]--;
                hash[i]--;
                mp[hash[i]]++;
                count++;
            }
        }
        return count;
    }
};
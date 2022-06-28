class Solution
{
public:
    int minDeletions(string s)
    {
        vector<int> hash(26, 0);
        for (auto c : s)
            hash[c - 'a']++;

        int count = 0, maxF = s.size();
        sort(hash.begin(), hash.end(), greater<int>());

        for (int i = 0; i < 26 && hash[i] > 0; i++)
        {
            if (hash[i] <= maxF)
                maxF = hash[i] - 1;
            else
            {
                count += hash[i] - maxF;
                maxF = maxF == 0 ? 0 : maxF - 1;
            }
        }

        return count;
    }
};
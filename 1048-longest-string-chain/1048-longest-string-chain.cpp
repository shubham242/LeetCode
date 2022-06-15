class Solution
{
public:
    bool isSubSequence(string str1, string str2)
    {
        int n = str2.size();
        int m = str1.size();
        int j = 0;
        for (int i = 0; i < n && j < m; i++)
            if (str1[j] == str2[i])
                j++;
        return (j == m);
    }

    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        int count[n];
        for (int i = 0; i < n; i++)
            count[i] = 1;
        int maxCount = 1;
        sort(words.begin(), words.end(), [](const std::string &first, const std::string &second)
             { return first.size() < second.size(); });

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (words[j].size() - words[i].size() > 1)
                    break;
                if (words[j].size() - words[i].size() == 0)
                    continue;
                if (isSubSequence(words[i], words[j]))
                {
                    count[j] = max(count[j], 1 + count[i]);
                    maxCount = max(maxCount, count[j]);
                }
            }
        }

        return maxCount;
    }
};
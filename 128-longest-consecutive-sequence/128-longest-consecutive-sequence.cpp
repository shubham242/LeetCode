class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        set<int> hashset;
        for (int num : nums)
        {
            hashset.insert(num);
        }
        int longeststreak = 0;
        for (int num : nums)
        {
            if (!hashset.count(num - 1))
            {
                int currentstreak = num;
                int count = 1;
                while (hashset.count(currentstreak + 1))
                {
                    currentstreak += 1;
                    count += 1;
                }
                longeststreak = max(longeststreak, count);
            }
        }
        return longeststreak;
    }
};